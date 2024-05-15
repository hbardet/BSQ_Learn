/*
** EPITECH PROJECT, 2022
** bsq
** File description:
** generate_map
*/

#include "my_bsq.h"
#include "my.h"

char **generate_map(cordo_t *max, char *motif)
{
    int x = 0;
    int j = 0;
    int i = 0;
    char **map = mem_alloc_2d_array(max);
    for (i = 0; i < max->x; i++){
        for (j = 0; j < max->y; j++){
            map[i][j] = motif[x % my_strlen(motif)];
            ++x;
        }
        map[i][j] = '\n';
        map[i][j + 1] = '\0';
    }
    map[i] = '\0';
    return (map);
}
