/*
** EPITECH PROJECT, 2022
** mini_printf
** File description:
** function
*/
#include <stdarg.h>
void my_putchar(char c);

int my_put_binary(unsigned int nb,int count);

int my_printf_b_params(unsigned int nb)
{
    return my_put_binary(nb,1);
}
