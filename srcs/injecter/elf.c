#include "elf.h"

int main(int argc, char **argv)
{
    t_elf_data elf_data = {0};
    Elf64_Ehdr *eh;
    struct stat st;
    off_t size;
    void *base;
    int fd;

    if(check_for_errors(argc, argv, &fd, &elf_data))
        return(1);
    size = lseek(fd, 0, SEEK_END);
    if(size == -1)
        return(perror("lseek"), 1);
    base = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if(base == MAP_FAILED)
        perror("mmap");
    eh = (Elf64_Ehdr *) base;
    encrypter((Elf64_Phdr *)((void *)base + eh->e_phoff), eh, base, &elf_data);
    init_segment_value((Elf64_Phdr *)((void *)base + eh->e_phoff), eh, &elf_data);
    injection(eh, base, size, &elf_data);
    return(0);
}
