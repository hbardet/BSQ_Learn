/*
** EPITECH PROJECT, 2022
** percent specifier
** File description:
** function that print %
*/
#include <stdarg.h>

void my_putchar(char c);

int my_printf_percent(va_list ap)
{
    my_putchar('%');
    return 1;
}

int my_printf_percent_params(void)
{
    my_putchar('%');
    return 1;
}
