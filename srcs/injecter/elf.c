#include "elf.h"

int main(int argc, char **argv)
{
    // -- Init variable -- //
    t_elf_data elf_data = {0};
    Elf64_Ehdr *eh;
    struct stat st;
    size_t size;
    void *base;
    int fd;

    if(check_for_errors(argc, argv, &fd, &elf_data))
        return(1);
    fstat(fd, &st);
    size = st.st_size;
    base = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    eh = (Elf64_Ehdr *) base;
    init_segment_value((Elf64_Phdr *)((void *)base + eh->e_phoff), eh, &elf_data);
    injection(eh, base, size, &elf_data);
    return(0);
}
