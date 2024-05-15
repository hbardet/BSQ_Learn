/*
** EPITECH PROJECT, 2022
** mini_printf
** File description:
** function
*/
#include <stdarg.h>

int my_count_number(int nb);
int my_put_nbr(int nb);

int my_printf_d(va_list ap)
{
    int n = va_arg(ap,int);
    my_put_nbr(n);
    return my_count_number(n);
}

int my_printf_int_value_return(va_list ap)
{
    return va_arg(ap,int);
}

int my_printf_d_params(int nb)
{
    my_put_nbr(nb);
    return my_count_number(nb);
}
