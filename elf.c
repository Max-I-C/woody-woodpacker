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
static Elf64_Addr   g_parasite_addr;
static Elf64_Off    g_parasite_off;
static uint64_t     g_parasite_size;
static uint64_t     g_payload_size;

void calcul_payload(char **paths)
{
    int64_t size = 0;
    int verif = 0;
    for (int i = 0; paths[i]; i++)
    {
        int fd = open(paths, O_RDONLY);
        if(fd < 0)
        {
            close(fd);
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
        else
            size += verif;
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
    char **paths = {"virus_test.bin", "handler_test.bin"};
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

            if(i < eh->e_phnum)
                padding = phdr[i + 1].p_offset - (seg_offset + seg_size);
            if(padding < g_payload_size)
                return(printf("Error, not possible to inject the code because not enought space\n"), 1);
            else
            {
                printf("Ajusting the size to fill\n");
                phdr[i].p_filesz += g_payload_size;
                phdr[i].p_memsz += g_payload_size;
                phdr[i].p_flags |= PF_W;
            }
            break;
        }
    }
    g_parasite_addr = seg_addr + seg_size;
    g_parasite_off = seg_offset + seg_size;
    
    // Changer l'entry point //
    //Elf64_Addr old_entry = eh->e_entry;
    //if(eh->e_type == ET_EXEC)
    //{
    //    eh->e_entry = g_handler_addr; // ?
    //}
    //else
    //{
    //    eh->e_entry = g_handler_off; // ?
    //}
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