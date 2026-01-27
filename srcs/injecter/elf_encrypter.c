#include "elf.h"

int key_generation()
{
    int fd = open("/dev/random", O_RDONLY);
    if(fd < 0)
        return(error(ERROR_FILE), 0);

    unsigned int random_num;
    int result = read(fd, &random_num, sizeof(random_num));
    close(fd);
    if(result < 0)
        return(error(ERROR_FILE), 0);

    printf("-> %d\n", random_num);
    return(random_num);
}

void encrypter()
{
    key_generation();
}
