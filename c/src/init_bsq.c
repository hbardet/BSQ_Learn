/*
** EPITECH PROJECT, 2022
** bsq
** File description:
** bsq header
*/

#include "../include/bsq.h"
#include <strings.h>


static void get_map_and_size_bsq(data_bsq_t *bsq, char *path)
{
    bsq->file = load_file(path, &bsq->size_file_bytes);
    char tmp[READ_SIZE];
    size_t index;

    for (index = 0; bsq->file[index] != '\n' && index < READ_SIZE; index++)
        tmp[index] = bsq->file[index];
    tmp[index] = '\0';
    bsq->size_map = atoi(tmp);
    bsq->map = bsq->file + index + 1;
    bsq->size_map_bytes = bsq->size_file_bytes - index - 1;
}


static data_bsq_t *init_bsq(void)
{
    data_bsq_t *bsq = malloc(sizeof(data_bsq_t));

    if (!bsq)
        return (NULL);

    bsq->posi_bsq.x = 0;
    bsq->posi_bsq.y = 0;
    bsq->size_map = 0;
    bsq->size_bsq = 0;
    return (bsq);
}

data_bsq_t *setup_bsq(char *path)
{
    data_bsq_t *bsq = init_bsq();

    get_map_and_size_bsq(bsq, path);
    bsq->size_bsq = 0;
    bsq->posi_bsq.x = 0;
    bsq->posi_bsq.y = 0;
    return (bsq);
}

void free_bsq(data_bsq_t *bsq)
{
    munmap(bsq->file, bsq->size_file_bytes);
    free(bsq);
}
