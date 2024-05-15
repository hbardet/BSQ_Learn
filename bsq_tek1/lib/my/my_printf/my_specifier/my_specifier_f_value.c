/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** compute file
*/
#include <stdarg.h>

void my_putchar(char c);
int my_put_nbr(int nb);
int my_compute_power_rec(int nb, int power);
int my_putstr(char const *str);
int my_count_number(int nb);
int my_put_float_printf(double nb, int n, int maj);

int my_printf_f_params(double nb)
{
    return (my_put_float_printf(nb, 6, 0));
}

int my_printf_ff_params(double nb)
{
    return (my_put_float_printf(nb, 6, 1));
}
