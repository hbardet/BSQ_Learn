/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** my_specifier_x
*/
#include <stdarg.h>

void my_putchar(char c);
int my_put_hexadecimal_value(long unsigned int nb,int count, int maj);
int my_put_hexadecimal(long unsigned int nb,int count, int maj)
{
    int upp = (maj) ? (55) : (87);
    if (nb > 15)
        count = my_put_hexadecimal(nb / 16,count + 1, maj);
    if ((nb % 16) > 9)
        my_putchar((nb % 16) + upp);
    else
        my_putchar((nb % 16) + 48);
    return count;
}

int my_printf_x(va_list ap)
{
    return my_put_hexadecimal(va_arg(ap,unsigned int),1, 0);
}

int my_printf_xx(va_list ap)
{
    return my_put_hexadecimal(va_arg(ap,unsigned int),1, 1);
}
