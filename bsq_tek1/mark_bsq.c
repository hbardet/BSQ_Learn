/*
** EPITECH PROJECT, 2022
** bsq
** File description:
** mark_bsq
*/

#include "my_bsq.h"
#include "my.h"

int replace_square(char **map, data_bsq_t *data)
{
    for (int i = 0; i < data->size; i++){
        for (int j = 0; j < data->size; j++){
            map[data->x + i][data->y + j] = 'x';
        }
    }
    return (0);
}
