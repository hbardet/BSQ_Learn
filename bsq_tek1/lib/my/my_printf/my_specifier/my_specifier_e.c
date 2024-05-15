/*
** EPITECH PROJECT, 2022
** mini_printf
** File description:
** function third part
*/
#include <stdarg.h>

void my_putchar(char c);
int my_put_nbr(int nb);
int my_put_float_printf(double flt, int n, int maj);
int my_putstr(char const *str);
int my_printf_e_extrem(double nb, int maj);

void my_printf_e_printexp(int exp)
{
    if (exp <= 9)
        my_putchar('0');
    if (exp > 0)
        my_put_nbr(exp);
    else
        my_put_nbr(exp * -1);
}

int my_put_exp(double nb,int precis, int maj)
{
    char *expoStrNeg = (maj) ? ("E-") : ("e-");
    char *expoStrPos = (maj) ? ("E+") : ("e+");
    int exp = 0;
    int extrem = my_printf_e_extrem(nb,maj);
    if (extrem > 0)
        return extrem;
    for (;nb >= 10 || nb <= -10; exp++)
        nb /= 10;
    for (;nb < 1 && nb > -1; exp--)
        nb = nb * 10;
    my_put_float_printf(nb, precis, maj);
    if (exp >= 0)
        my_putstr(expoStrPos);
    else
        my_putstr(expoStrNeg);
    my_printf_e_printexp(exp);
    return 12;
}

int my_printf_e(va_list ap)
{
    return my_put_exp(va_arg(ap,double), 6, 0);
}

int my_printf_ee(va_list ap)
{
    return my_put_exp(va_arg(ap,double), 6, 1);

}
