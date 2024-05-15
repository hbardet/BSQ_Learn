/*
** EPITECH PROJECT, 2022
** bsq
** File description:
** mem_init
*/
#include "my_bsq.h"
#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char **mem_alloc_2d_array(cordo_t *max)
{
    char **array = malloc(sizeof(char *) * (max->x + 1));

    for (int i = 0; i < max->x; i++){
        array[i] = malloc(sizeof(char *) * (max->y + 2));
    }
    return (array);
}

char **mem_dup_2d_array(char *buffer, cordo_t *max)
{
    char **array_dup = mem_alloc_2d_array(max);
    int i = 0;
    int j = 0;
    int x = 0;
    while (i < max->x){
        array_dup[i][j] = buffer[x];
        ++j;
        if (j > max->y){
            array_dup[i][j] = '\0';
            j = 0;
            ++i;
        }
        ++x;
    }
    array_dup[i] = '\0';
    return (array_dup);
}
