/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** compute file
*/
#include <stdarg.h>

void my_putchar(char c);

int my_put_octal(unsigned int nb,int count)
{
    if (nb > 7)
        count = my_put_octal(nb / 8,count + 1);
    my_putchar((nb % 8) + 48);
    return count;
}

int my_printf_o(va_list ap)
{
    return my_put_octal(va_arg(ap,unsigned int),1);
}

int my_printf_o_params(unsigned int nb)
{
    return my_put_octal(nb,1);
}
