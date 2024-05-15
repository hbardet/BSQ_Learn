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
void my_printf_e_printexp(int exp);
int my_put_exp(double nb, int maj);

int my_printf_e_params(double nb)
{
    return my_put_exp(nb, 0);
}

int my_printf_ee_params(double nb)
{
    return my_put_exp(nb, 1);

}
