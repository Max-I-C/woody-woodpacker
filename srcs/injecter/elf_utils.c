#include "elf.h"

void error(char *error_msg)
{
    write(2, error_msg, ft_strlen(error_msg));
}

void copy_file(char *origin_file)
{
    int fd_dest = 0;
    int fd_origin = 0;
    ssize_t return_read = 0;
    ssize_t return_write = 0;
    char buffer[BUFFER_SIZE];

    fd_origin = open(origin_file, O_RDWR);
    if(fd_origin == -1)
        return(error(ERROR_FILE));
    fd_dest = open(TARGET_FILE,  O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if(fd_dest == -1)
        return(close(fd_origin), error(ERROR_FILE));
    // -- ENCRPYTION ICI NON ? -- //
    encrypter();
    // -- ENCRPYTION ICI NON ? -- //
    while ((return_read = read(fd_origin, buffer, BUFFER_SIZE)) > 0)
    {
        return_write = write(fd_dest, buffer, return_read);    
        if(return_write == -1)
            return(close(fd_origin), close(fd_dest), error(ERROR_FILE));
        else if(return_read != return_write)
            return(close(fd_origin), close(fd_dest), error(ERROR_ARG));
    }
    if(return_read == -1)
        return(close(fd_origin), close(fd_dest), error(ERROR_FILE));
    return ;
}

bool check_for_errors(int argc, char **argv, int *fd, t_elf_data *elf_data)
{
    char *paths[] = {"obj/assembly/virus_test.bin", "obj/assembly/handler_test.bin", NULL};

    if(argc < 2)
        return (error(ERROR_ARG), true);
    copy_file(argv[1]);
    *fd = open(TARGET_FILE, O_RDWR);
    if(*fd == -1)
        return(error(ERROR_FILE), true);
    calcul_payload(paths, elf_data);
    if(!elf_data->g_payload_size)
        return(close(*fd), error(ERROR_PLD), true);
    return (false);
}
