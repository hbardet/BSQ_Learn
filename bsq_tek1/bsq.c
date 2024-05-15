/*
** EPITECH PROJECT, 2022
** bsq
** File description:
** bsq
*/

#include "my_bsq.h"
#include "my.h"

data_bsq_t *parcing_row(char **map, cordo_t *max)
{
    data_bsq_t *data = init_data_bsq();
    cordo_t *cordo = init_cordo_struct();
    while (cordo->x < max->x){
        parcing_col(map, max, cordo, data);
        cordo->x = cordo->x + 1;
    }
    free(cordo);
    return (data);
}

int parcing_col(char **map, cordo_t *max, cordo_t *cordo, data_bsq_t *data)
{
    while (cordo->y < max->y){
        test_size_for_cordo(map, cordo, data, max);
        cordo->y = cordo->y + 1;
    }
    cordo->y = 0;
    return (0);
}
