#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <elf.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

static Elf64_Addr   g_old_addr;
static Elf64_Addr   g_handler_addr;
static Elf64_Addr   g_parasite_addr;
static Elf64_Off    g_parasite_off;
static Elf64_Off    g_handler_off;
static uint64_t     g_parasite_size;
static uint64_t     g_payload_size;

void calcul_payload(char **paths)
{
    int verif = 0;
    for (int i = 0; paths[i]; i++)
    {
        int fd = open(paths[i], O_RDONLY);
        if(fd == -1)
        {
            printf("Error, the source assembly file is not accesible\n");
            return ;
        }
        verif = (int64_t)lseek(fd, 0, SEEK_END);
        if(verif == -1)
        {
            close(fd);
            printf("Error, lseek function return an error\n");
            return ;
        }
        if(i == 0)
            g_parasite_size = verif;
        g_payload_size += verif;
        close(fd);
    }
    return ;
}

int main(int argc, char **argv)
{
    uint64_t seg_size = 0;
    Elf64_Addr seg_addr = 0;
    Elf64_Off seg_offset = 0;
    if(argc < 2)
        return (printf("ERROR, not enought argument\n"), 1);
    int fd = open(argv[1], O_RDWR);
    if(fd < -1)
        return(printf("Error while opening the file\n"), 1);
    char *paths[] = {"obj/assembly/virus_test.bin", "obj/assembly/handler_test.bin", NULL};
    calcul_payload(paths);
    if(!g_payload_size)
        return(printf("Error, payload issue\n"), 1);
    struct stat st;
    fstat(fd, &st);
    size_t size = st.st_size;
    void *base = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    Elf64_Ehdr *eh = (Elf64_Ehdr *) base;
    Elf64_Phdr *phdr = (Elf64_Phdr *)((void *)base + eh->e_phoff);
    uint64_t padding = 0;
    for(uint16_t i = 0; i < eh->e_phnum; i++)
    { 
        if(phdr[i].p_type == PT_LOAD && phdr[i].p_flags == (PF_R | PF_X))
        {
            seg_size = phdr[i].p_filesz;
            seg_addr = phdr[i].p_vaddr;
            seg_offset = phdr[i].p_offset;

            if(i + 1 < eh->e_phnum)
                padding = phdr[i + 1].p_offset - (seg_offset + seg_size);
            if(padding < g_payload_size)
                return(printf("Error, not possible to inject the code because not enought space\n"), 1);
            else
            {
                printf("Ajusting the size to fill\n");
                phdr[i].p_filesz += g_payload_size;
                phdr[i].p_memsz += g_payload_size;
                phdr[i].p_flags = PF_W | PF_R | PF_X;
            }
            break;
        }
    }
    g_parasite_addr = seg_addr + seg_size;
    g_parasite_off = seg_offset + seg_size;

    g_handler_addr = g_parasite_addr + g_parasite_size;
    g_handler_off = g_parasite_off + g_parasite_size;
    // Changer l'entry point //

    Elf64_Addr old_entry = eh->e_entry;
    eh->e_entry = g_handler_addr;

    unsigned char *ptr_injection = (unsigned char *)base + g_parasite_off;

    int vfd = open("obj/assembly/virus_test.bin", O_RDONLY);
    read(vfd, ptr_injection, g_parasite_size);
    close(vfd);

    vfd = open("obj/assembly/handler_test.bin", O_RDONLY);
    read(vfd, ptr_injection + g_parasite_size, g_payload_size - g_parasite_size);
    close(vfd);

    /* TEST */
    // Utilise un pointeur unsigned char pour parcourir octet par octet
    for (size_t i = 0; i <= g_payload_size - sizeof(uint64_t); i++) {
        uint64_t *ptr = (uint64_t *)(ptr_injection + i);
        if (*ptr == 0xAAAAAAAAAAAAAAAA) {
            *ptr = (int64_t)old_entry - (int64_t)g_handler_addr;
            printf("Old entry patched at offset %lu\n", i);
        }
        if (*ptr == 0xBBBBBBBBBBBBBBBB) {
            *ptr = g_parasite_size;
            printf("Parasite size patched at offset %lu\n", i);
        }
    }
    /* TEST */

    msync(base, size, MS_SYNC);
    munmap(base, size);
    printf("Binary infected\n");
    return(0);
}

// Faire le handler.s
// Redefinir le payload size
// Redefinir le entry_point
// Injecter le handler et le virus



// 5) Chiffre le code original
// 6) Réécrit les tailles et entrypoint
    
//    # Partie .assemlby
//    Programme Assembly (payload)
//    1) Affiche “Woody”
//    2) Déchiffre le code original
//    3) Saute vers l’ancien entrypoint
