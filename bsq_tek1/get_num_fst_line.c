/*
** EPITECH PROJECT, 2022
** bsq_function
** File description:
** fs_cat_500_bytes
*/
#include "./include/my.h"
#include "./include/my_bsq.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>


int my_len_fst_line(char *buffer)
{
    int i = 0;
    while (buffer[i] != '\n' && buffer[i] != '\0')
            i++;
    return (i);
}

char *my_fst_line_to_array(char *buffer, int size)
{
    char *fst_line = malloc(sizeof(char) * (size + 1));
    int i = 0;
    for (; i < size; i++)
        fst_line[i] = buffer[i];
    fst_line[i] = '\0';
    return (fst_line);
}

int test_nbr_fst_line(char *fst_line)
{
    if (fst_line == NULL)
        return (-1);
    int i = 0;
    while (fst_line[i]){
        if (!(fst_line[i] >= '0' && fst_line[i] <= '9'))
            return 0;
        ++i;
    }
    return 1;
}

int error_buffer(char *buffer, int read_test)
{
    int i = 0;
    int index = 0;
    if (read_test <= 0){
        fprintf(stderr,"error fd\n"); 
        return (-1);
    }
    if (buffer[0] == '\0'){
        fprintf(stderr,"error buffer\n"); 
        return (-1);
    }
    while (i < read_test){
        if (buffer[i] == '\n' && index == 0)
            index = i;
        i++;
    }
    if (index + 1 == read_test || index == 0){
        fprintf(stderr,"error error size line\n"); 
        return (-1);
    }
    return (0);
}

int fs_get_number_from_first_line(char const *filepath)
{
    int fd = fs_open_file(filepath);
    char *buffer = malloc(sizeof(char) * 12);
    int read_test = read(fd, buffer, 12);
    int error = error_buffer(buffer, read_test);
    if (error == -1)
        return (-1);
    int size;
    char *fst_line;
    int rtn = 0;
    size = my_len_fst_line(buffer);
    fst_line = my_fst_line_to_array(buffer, size);
    if (test_nbr_fst_line(fst_line))
        rtn = my_getnbr(fst_line);
    free(fst_line);
    free(buffer);
    close(fd);
    return (rtn);
}
