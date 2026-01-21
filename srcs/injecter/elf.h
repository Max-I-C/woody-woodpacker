#ifndef ELF_H
# define ELF_H

// -- External library -- //
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

// -- Libft -- //
#include "libft/libft.h"

// -- Definition of the macro -- //
#define ERROR_FILE  "Error, file problem.\n"
#define ERROR_ARG   "Error, not enough argument.\n"
#define ERROR_PLD   "Error, payload issue.\n"
#define ERROR_INJ   "Error, not enough space to inject the code.\n"

// -- Static variables -- //
static Elf64_Addr   g_old_addr;
static Elf64_Addr   g_handler_addr;
static Elf64_Addr   g_parasite_addr;
static Elf64_Off    g_parasite_off;
static Elf64_Off    g_handler_off;
static uint64_t     g_parasite_size;
static uint64_t     g_payload_size;
// ---------------------- //

#endif