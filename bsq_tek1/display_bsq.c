/*
** EPITECH PROJECT, 2022
** bsq
** File description:
** display_bsq
*/

#include "my_bsq.h"
#include "my.h"

int display_bsq(char **map, cordo_t *max_size)
{
    for (int i = 0; i < max_size->x; i++)
        write(1,map[i],max_size->y + 1);
    return (0);
}
