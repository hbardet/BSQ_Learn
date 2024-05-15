/*
** EPITECH PROJECT, 2022
** mini_printf
** File description:
** function
*/
#include <stdarg.h>
void my_putchar(char c);

int my_put_binary(unsigned int nb,int count)
{
    if (nb > 1)
        count = my_put_binary(nb / 2, count + 1);
    my_putchar((nb % 2) + 48);
    return count;
}

int my_printf_b(va_list ap)
{
    return my_put_binary(va_arg(ap,unsigned int),1);
}

int my_printf_unsigned_int_value_return(va_list ap)
{
    return va_arg(ap,unsigned int);
}
