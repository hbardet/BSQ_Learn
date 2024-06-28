/*
** EPITECH PROJECT, 2022
** bsq
** File description:
** bsq header
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>

#ifndef MY_BSQ_H_
    #define MY_BSQ_H_
#define READ_SIZE 1000

typedef struct uvector_s{
    size_t x; // Rows
    size_t y; // Cols
}uvector_t;

typedef struct data_bsq{
    uvector_t posi_bsq;
    size_t size_file_bytes;
    size_t size_map_bytes;
    size_t size_map;
    size_t size_bsq;
    char *map;
    char *file;
}data_bsq_t;

char *load_file(char const *filepath, size_t *size);
data_bsq_t *setup_bsq(char *path);
void free_bsq(data_bsq_t *bsq);
void resolve_bsq(data_bsq_t *bsq);
void replace_bsq(data_bsq_t *bsq);
void display_bsq(data_bsq_t *bsq);
#endif /* !MY_BSQ_H_ */
