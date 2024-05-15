/*
** EPITECH PROJECT, 2022
** bsq
** File description:
** read_file
*/
#include "my_bsq.h"
#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


char *error_file(char *buffer, int fd, int size)
{
    int read_test = read(fd, buffer, size);
    int i = 0;
    buffer[size] = '\0';
    if (read_test != size)
        return (NULL);
    if (buffer[0] == '\0'){
        return (NULL);
    }
    while (buffer[i] && buffer[i] != '\n')
        i++;
    if (i == my_strlen(buffer) && buffer[i + 1] == '\n')
        return (NULL);
    return (buffer);
}

char *read_file(int fd, int size)
{
    char *buffer = malloc(sizeof(char) * size + 1);

    buffer = error_file(buffer, fd, size);

    close(fd);
    return (buffer);
}
