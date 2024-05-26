/*
** EPITECH PROJECT, 2022
** bsq
** File description:
** setup_file
*/
#include "./include/my_bsq.h"
#include "./include/my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int get_size_files(char const *filepath)
{
    struct stat st;
    stat(filepath, &st);
    return (st.st_size);
}

char *load_file_in_mem(char const *filepath)
{
    int fd = fs_open_file(filepath);
    unsigned int size;
    char *buffer;
    if (fd == -1)
        return (NULL);
    else {
        size = get_size_files(filepath);
        buffer = read_file(fd, size);
        return (buffer);
    }
    return (NULL);
}

char **load_2d_arr_from_files(char const *filepath, cordo_t *max)
{
    char **map;

    int fd = fs_open_file(filepath);
    if (fd == -1)
        return (NULL);
    int size = get_size_files(filepath);
    char *buffer = read_file(fd, size);
    buffer = first_skip(buffer);
    map = mem_dup_2d_array(buffer, max);
    return (map);
}
