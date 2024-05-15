/*
** EPITECH PROJECT, 2022
** bsq
** File description:
** setup_cordo.c
*/

#include "./include/my_bsq.h"
#include "./include/my.h"

cordo_t *set_max_cordo(char *filepath)
{
    cordo_t *new_element = malloc(sizeof(new_element));

    new_element->x = fs_get_number_from_first_line(filepath);
    new_element->y = get_num_of_cols(filepath, new_element->x);
    if (new_element->y <= 0)
        return (NULL);
    else
        return (new_element);
}

cordo_t *init_cordo_struct(void)
{
    cordo_t *new_element = malloc(sizeof(new_element));

    new_element->y = 0;
    new_element->x = 0;

    return (new_element);
}

int set_new_cordo(cordo_t *point, int new_x, int new_y)
{
    point->x = new_x;
    point->y = new_y;
    return (0);
}

data_bsq_t *init_data_bsq(void)
{
    data_bsq_t *data = malloc(sizeof(*data));
    data->size = 0;
    data->x = 0;
    data->y = 0;

    return (data);
}

int set_new_data(data_bsq_t *data, cordo_t *cordo, int new_size)
{
    data->size = new_size;
    data->x = cordo->x;
    data->y = cordo->y;
    return (0);
}
