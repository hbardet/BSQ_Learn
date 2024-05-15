/*
** EPITECH PROJECT, 2022
** bsq
** File description:
** select_mode
*/

#include "./include/my_bsq.h"
#include "./include/my.h"
#include <stdio.h>

int find_bsq(char **map, cordo_t *max_size)
{
    data_bsq_t *bsq = parcing_row(map, max_size);
    replace_square(map, bsq);
    display_bsq(map, max_size);
    free(bsq);
    return (0);
}

int resolve_bsq(char *filepath)
{
    int fd = fs_open_file(filepath);
    if (fd == -1) {
        fprintf(stderr, "error with fd\n");
        return (84);
    }
    cordo_t *max_size = set_max_cordo(filepath);
    if (max_size == NULL){
        fprintf(stderr,"error with size bsq\n"); 
        return (84);
    }
    char **map = load_2d_arr_from_files(filepath, max_size);
    find_bsq(map, max_size);
    for (int i = 0; i < max_size->x; i++)
        free(map[i]);
    free(map);
    free(max_size);
    return (0);
}

int generate_bsq(char **av)
{
    if (!(my_str_isnum(av[1]))){
        fprintf(stderr, "error with nbr of param\n");
        return (84);
    }
    if (av[2][0] == '\0')
        return (84);
    for (int i = 0; av[2][i]; i++){
        if ((av[2][i] != '.' && av[2][i] != 'o'))
            return (84);
    }
    cordo_t *max = init_cordo_struct();
    int size = my_getnbr(av[1]);
    char **map;
    if (size == 0)
        return (84);
    set_new_cordo(max, size,size);
    map = generate_map(max,av[2]);
    find_bsq(map, max);
    for (int i = 0; i < max->x; i++)
        free(map[i]);
    free(map);
    return (0);
}

int select_mode_bsq(int ac, char **av)
{
    if (ac == 2)
        return (resolve_bsq(av[1]));
    else if (ac == 3)
        return (generate_bsq(av));
    else
        return (84);
}
