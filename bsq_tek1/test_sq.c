/*
** EPITECH PROJECT, 2022
** bsq
** File description:
** test_sq
*/

#include "my_bsq.h"
#include "my.h"

int test_bsq(char **map, cordo_t *cordo, int square_size, int i)
{
    for (int j = 0; j < square_size; j++){
        if (map[cordo->x + i][cordo->y + j] != '.')
            return (0);
    }
    return (1);
}

int is_square_of_size(char **map, cordo_t *cordo, int square_size)
{
    int stop = 0;
    for (int i = 0; i < square_size ; i++){
        stop = test_bsq(map, cordo, square_size, i);
        if (!(stop))
            return (0);
    }
    return (1);

}

int sq_size_in_map(cordo_t *cordo, cordo_t *max, int size)
{
    if (cordo->x + size <= max->x && cordo->y + size <= max->y)
        return (1);
    else
        return (0);
}

int test_size_for_cordo(char **map, cordo_t *cd, data_bsq_t *dt, cordo_t *mx)
{
    int i = 1;
    while (sq_size_in_map(cd, mx, i) && is_square_of_size(map,cd, i)){
        if (dt->size < i)
            set_new_data(dt, cd, i);
        if (dt->size == mx->x || dt->size == mx->y)
            return (0);
        i++;
    }
    return (0);
}
