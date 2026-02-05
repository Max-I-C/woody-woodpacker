#include "elf.h"

void key_generation(uint32_t key[4])
{
    int fd = open("/dev/urandom", O_RDONLY);
    if(fd < 0)
        return(error(ERROR_SYSTEM_FILE));
    read(fd, key, sizeof(uint32_t) * 4);
    close(fd);
    printf("Key: 0x%08x%08x%08x%08x\n", key[0], key[1], key[2], key[3]);
}

void encryption_TEA(void *data, size_t size, uint32_t key[4])
{
    uint32_t *ptr = (uint32_t *)data;
    uint32_t delta = 0x9e3779b9;

    size_t safe_limit = (size >= 8) ? (size - 8) : 0;
    for(size_t i = 0; i <= safe_limit /sizeof(uint32_t); i+=2)
    {
        uint32_t v0 = ptr[i];
        uint32_t v1 = ptr[i + 1];
        uint32_t sum = 0;

        // 32 spin of hashing //
        for(int j = 0; j < 32; j++)
        {
            sum += delta;
            v0 += ((v1 << 4) + key[0]) ^ (v1 + sum) ^ ((v1 >> 5) + key[1]);
            v1 += ((v0 << 4) + key[2]) ^ (v0 + sum) ^ ((v0 >> 5) + key[3]);
        }
        ptr[i] = v0;
        ptr[i + 1] = v1;
    }
}

void encrypter(Elf64_Phdr *phdr, Elf64_Ehdr *eh, void *base, t_elf_data *elf_data)
{
    uint32_t key[4];
    key_generation(key);
    ft_memcpy(elf_data->key, key, sizeof(key));
    for(uint16_t i = 0; i < eh->e_phnum; i++)
    { 
        if(phdr[i].p_type == PT_LOAD && phdr[i].p_flags == (PF_R | PF_X))   
        {
            elf_data->g_text_addr = phdr[i].p_vaddr;
            elf_data->g_text_size = phdr[i].p_filesz;
            encryption_TEA(base + phdr[i].p_offset, phdr[i].p_filesz, key);
            break;
        }
    }
}
