/*
** EPITECH PROJECT, 2022
** bsq
** File description:
** bsq header
*/
#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef MY_BSQ_H_
    #define MY_BSQ_H_

typedef struct cordo{
    int x; // Rows
    int y; // Cols
}cordo_t;

typedef struct data_bsq{
    int x; // Rows
    int y; // Cols
    int size;
}data_bsq_t;

int display_bsq(char **map, cordo_t *max_size);
char *error_file(char *buffer, int fd, int size);
char *first_skip(char *buffer);
int resolve_bsq(char *filepath);
int fs_open_file(char const *filepath);
int find_bsq(char **map, cordo_t *max_size);
int fs_get_number_from_first_line(char const *filepath);
int generate_bsq(char **av);
char **generate_map(cordo_t *max, char *motif);
int get_size_fmakeiles(char const *filepath);
int get_num_of_cols(const char *filepath, int nb_rows);
cordo_t *init_cordo_struct(void);
data_bsq_t *init_data_bsq(void);
int is_square_of_size(char **map, cordo_t *cordo, int square_size);
char *load_file_in_mem(char const *filepath);
int loop_test_cols(const char *filepath, int nb_rows);
char **load_2d_arr_from_files(char const *filepath, cordo_t *max);
int my_len_fst_line(char *buffer);
char *my_fst_line_to_array(char *buffer, int size);
char **mem_alloc_2d_array(cordo_t *max);
char **mem_dup_2d_array(char *buffer, cordo_t *max);
int parsing_line(char *map);
data_bsq_t *parcing_row(char **map, cordo_t *max);
int parcing_col(char **map, cordo_t *max, cordo_t *cordo, data_bsq_t *data);
int resolve_bsq(char *filepath);
int replace_square(char **map, data_bsq_t *data);
cordo_t *set_max_cordo(char *filepath);
int select_mode_ssq(int ac, char **av);
int set_new_cordo(cordo_t *point, int new_x, int new_y);
int sq_size_in_map(cordo_t *cordo, cordo_t *max, int size);
int set_new_data(data_bsq_t *data, cordo_t *cordo, int new_size);
int test_nbr_fst_line(char *fst_line);
int test_size_for_cordo(char **map, cordo_t *cd, data_bsq_t *dt, cordo_t *mx);
char *read_file(int fd, int size);
int test_bsq(char **map, cordo_t *cordo, int square_size, int i);

#endif /* !MY_BSQ_H_ */
