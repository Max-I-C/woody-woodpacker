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

int64_t set_payload_size(char *path)
{
    int fd = open(path, O_RDONLY);
    if(fd < 0)
        return(printf("Error, the source assembly file is not accesible\n"), 0);
    int64_t size = (int64_t)lseek(fd, 0, SEEK_END);
    if(size == -1)
        return(printf("Error, lseek function return an error\n"), 0);
    close(fd);
    return(size);
}

int main(int argc, char **argv)
{
    if(argc < 2)
        return (printf("ERROR, not enought argument\n"), 1);
    int fd = open(argv[1], O_RDWR);
    if(fd < -1)
        return(printf("Error while opening the file\n"), 1);
    uint64_t payload_size = set_payload_size("virus_test.bin");
    if(!payload_size)
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
            uint64_t seg_size = phdr[i].p_filesz;
            Elf64_Addr seg_addr = phdr[i].p_vaddr;
            Elf64_Off seg_offset = phdr[i].p_offset;

            if(i < eh->e_phnum)
                padding = phdr[i + 1].p_offset - (seg_offset + seg_size);
            if(padding < payload_size)
                return(printf("Error, not possible to inject the code because not enought space\n"), 1);
            else
            {
                printf("Ajusting the size to fill\n");
                phdr[i].p_filesz += payload_size;
                phdr[i].p_memsz += payload_size;
                phdr[i].p_flags |= PF_W;
            }
            break;
        }
    }
    return(0);
}

// J'ai initialiser les variables,
// Rechercher la partie qui est le segment qui est injectable
// Ajuster la taille des donnees du segment pour preparer le payload a y etre injecter 

// Il faut encore faire l'injection et je crois c'est tout non ? 



// 5) Chiffre le code original
// 6) Réécrit les tailles et entrypoint
    
//    # Partie .assemlby
//    Programme Assembly (payload)
//    1) Affiche “Woody”
//    2) Déchiffre le code original
//    3) Saute vers l’ancien entrypoint