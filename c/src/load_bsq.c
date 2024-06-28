/*
** EPITECH PROJECT, 2022
** bsq
** File description:
** bsq main
*/

#include "../include/bsq.h"

static void error_exit(char *str)
{
    perror(str);
    exit(84);
}

static size_t get_size_file(char const *filepath)
{
    struct stat st;
    int ret = stat(filepath, &st);

    if (ret == -1)
        error_exit("stat");
    return (st.st_size);
}

char *load_file(char const *filepath, size_t *size)
{
    *size = get_size_file(filepath);
    int fd = open(filepath, O_RDONLY);
    char *buffer;

    if (fd == -1)
        error_exit("open");
    buffer = mmap(NULL, *size, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0); 
    if (buffer == MAP_FAILED) {
        close(fd);
        error_exit("read");
    }
    close(fd);
    return (buffer);
}
