/*
** EPITECH PROJECT, 2022
** bsq
** File description:
** get_line
*/
#include "my_bsq.h"

int parsing_line(char *map)
{
    int i = 0;
    while (map[i] != '\n' && map[i]){
        if ((map[i] != '.' && map[i] != 'o'))
            return (-1);
        i++;
    }
    if (i == 0)
        return (-1);
    return (i);
}

char *first_skip(char *buffer)
{
    char *tmp = buffer;
    while (tmp[0] != '\n')
        ++tmp;
    ++tmp;
    return (tmp);
}

int loop_test_cols(const char *filepath, int nb_rows)
{
    char *buffer = load_file_in_mem(filepath);
    int nb_cols = 0;
    int tmp_cols = 0;
    int test_rows = 1;
    int i = 0;
    buffer = first_skip(buffer);
    nb_cols = parsing_line(buffer + i);
    tmp_cols = nb_cols;
    buffer += nb_cols + 1;
    while (test_rows != nb_rows){
        tmp_cols = parsing_line(buffer + i);
        buffer += tmp_cols + 1;
        if (test_rows - 1 == nb_rows && tmp_cols <= 3)
            return (nb_cols);
        if ((tmp_cols != nb_cols || test_rows >= nb_rows + 1))
            return (-1);
        test_rows++;
    }
    return (nb_cols);
}

int get_num_of_cols(const char *filepath, int nb_rows)
{
    if (nb_rows == -1)
        return (-1);
    else
        return (loop_test_cols(filepath,nb_rows));
}
