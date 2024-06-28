/*
** EPITECH PROJECT, 2022
** bsq
** File description:
** bsq main
*/

#include "../include/bsq.h"

int main (int ac, char **av)
{
    data_bsq_t *bsq;
    if (ac != 2)
        return (84);

    bsq = setup_bsq(av[1]); 
    resolve_bsq(bsq);
    replace_bsq(bsq);
    display_bsq(bsq);
    free_bsq(bsq);
    return (0);
}
