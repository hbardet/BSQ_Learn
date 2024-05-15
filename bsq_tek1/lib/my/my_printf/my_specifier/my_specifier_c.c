/*
** EPITECH PROJECT, 2022
** mini_printf
** File description:
** function
*/
#include <stdarg.h>

void my_putchar(char c);

int my_printf_c(va_list ap)
{
    my_putchar((char) va_arg(ap,int));
    return 1;
}

int my_printf_c_params(int nb)
{
    my_putchar((char) nb);
    return 1;
}
