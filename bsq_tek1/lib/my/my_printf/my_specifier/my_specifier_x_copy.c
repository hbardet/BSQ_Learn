/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** my_specifier_x
*/
#include <stdarg.h>

void my_putchar(char c);
int my_put_hexadecimal_value(long unsigned int nb,int count, int maj);
int my_put_hexadecimal(long unsigned int nb,int count, int maj);

int my_printf_x_params(unsigned int nb)
{
    return my_put_hexadecimal(nb,1, 0);
}

int my_printf_xx_params(unsigned int nb)
{
    return my_put_hexadecimal(nb,1, 1);
}
