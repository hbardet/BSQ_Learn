/*
** EPITECH PROJECT, 2022
** bsq
** File description:
** bsq header
*/

#include "../include/bsq.h"

static char get_cell(data_bsq_t *bsq, uvector_t pos)
{
    return (bsq->map[(pos.y * (bsq->size_map + 1)) + pos.x]);
}

static size_t find_bsq(data_bsq_t *bsq, uvector_t pos)
{
    size_t tmp_size = 1;
    while (1) {
        if (pos.x + tmp_size >= bsq->size_map || pos.y + tmp_size >= bsq->size_map)
            return (tmp_size - 1);
        for (size_t height = 0; height < tmp_size; height++){
            if (get_cell(bsq, (uvector_t){pos.x + tmp_size - 1, pos.y + height}) != '.')
                return (tmp_size - 1);
        }
        for (size_t width = 0; width < tmp_size; width++){
            if (get_cell(bsq, (uvector_t){pos.x + width, pos.y + tmp_size - 1}) != '.')
                return (tmp_size - 1);
        }
        tmp_size++;
    }

    return (tmp_size);
}

void resolve_bsq(data_bsq_t *bsq)
{
    size_t tmp_size = 0;
    for (size_t height = 0; height < bsq->size_map; height++){
        for (size_t width = 0; width < bsq->size_map; width++){
            if (get_cell(bsq, (uvector_t){width, height}) == '.') {
                tmp_size = find_bsq(bsq, (uvector_t){width, height});
                if (tmp_size > bsq->size_bsq){
                    bsq->size_bsq = tmp_size;
                    bsq->posi_bsq = (uvector_t){width, height};
                }
            }
        }
    }

}

void replace_bsq(data_bsq_t *bsq)
{
    for (size_t height = 0; height < bsq->size_bsq; height++){
        for (size_t width = 0; width < bsq->size_bsq; width++){
            bsq->map[(bsq->posi_bsq.y + height) * (bsq->size_map + 1) + bsq->posi_bsq.x + width] = 'x';
        }
    }
}

void display_bsq(data_bsq_t *bsq)
{
    size_t bytes_written = 0;
    while (bytes_written < bsq->size_map_bytes) {
        size_t result = write(STDOUT_FILENO, bsq->map + bytes_written, bsq->size_map_bytes - bytes_written);
        bytes_written += result;
    }
}
