#ifndef ELF_H
# define ELF_H

// -- libraries -- //
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <elf.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
// -- Libft -- //
#include "libft/libft.h"
// --------------- //

// -- Definition of the macro -- //
#define ERROR_FILE  "Error, file problem.\n"
#define ERROR_ARG   "Error, not enough argument.\n"
#define ERROR_PLD   "Error, payload issue.\n"
#define ERROR_INJ   "Error, not enough space to inject the code.\n"
#define TARGET_FILE "woody"
#define BUFFER_SIZE 2048
// ----------------------------- //

// -- Struct -- //
typedef struct s_elf_data
{
    Elf64_Addr   g_old_addr;
    Elf64_Addr   g_handler_addr;
    Elf64_Addr   g_parasite_addr;
    Elf64_Off    g_parasite_off;
    Elf64_Off    g_handler_off;
    uint64_t     g_parasite_size;
    uint64_t     g_payload_size;
} t_elf_data;
// ---------------------- //

// -- Functions ELF -- //
// - elf_init.c - //
void calcul_payload(char **paths, t_elf_data *elf_data);
void init_segment_value(Elf64_Phdr *phdr, Elf64_Ehdr *eh, t_elf_data *elf_data);
// - elf_injecter.c - //
void patcher(unsigned char *ptr_injection, Elf64_Addr old_entry, t_elf_data *elf_data);
void injection(Elf64_Ehdr *eh, void *base, size_t size, t_elf_data *elf_data);
// - elf_utils.c - //
bool check_for_errors(int argc, char **argv, int *fd, t_elf_data *elf_data);
void error(char *error_msg);
// ------------------ //
#endif