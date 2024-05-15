/*
** EPITECH PROJECT, 2022
** mini_printf
** File description:
** function third part
*/
#include <stdarg.h>
int my_putstr(char const *str);

int my_put_hexadecimal(long unsigned int nb,int count, int maj);

int my_put_hexadecimal_value(long unsigned int nb,int count, int maj)
{
    if (nb > 15)
        count = my_put_hexadecimal_value(nb / 16,count + 1, maj);
    return count;
}

int my_printf_p(va_list ap)
{
    my_putstr("0x");
    return my_put_hexadecimal(va_arg(ap,long int),1 ,0) + 2;
}

int my_printf_long_int_value_return(va_list ap)
{
    return va_arg(ap,long int);
}

int my_printf_p_params(long int nb)
{
    my_putstr("0x");
    return my_put_hexadecimal(nb,1 ,0) + 2;
}
