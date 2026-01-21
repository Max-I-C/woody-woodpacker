#include "elf.h"

void error(char *error_msg)
{
    write(2, error_msg, ft_strlen(error_msg));
}

bool check_for_errors(int argc, char **argv, int *fd, t_elf_data *elf_data)
{
    char *paths[] = {"obj/assembly/virus_test.bin", "obj/assembly/handler_test.bin", NULL};

    if(argc < 2)
        return (error(ERROR_ARG), true);
    *fd = open(argv[1], O_RDWR);
    if(*fd == -1)
        return(error(ERROR_FILE), true);
    calcul_payload(paths, elf_data);
    if(!elf_data->g_payload_size)
        return(close(*fd), error(ERROR_PLD), true);
    return (false);
}
