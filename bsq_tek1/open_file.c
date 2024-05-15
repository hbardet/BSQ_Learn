/*
** EPITECH PROJECT, 2022
** my_bsq
** File description:
** open_file
*/
#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int fs_open_file(char const *filepath)
{
    int fd = open(filepath, S_IRUSR);
    if (fd == -1)
        return (-1);
    else
        return (fd);
}
