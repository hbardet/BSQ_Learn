/*
** EPITECH PROJECT, 2022
** my_bsq
** File description:
** main.c
*/
#include "my_bsq.h"
#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    int error = select_mode_bsq(ac, av);
    return (error);
}
