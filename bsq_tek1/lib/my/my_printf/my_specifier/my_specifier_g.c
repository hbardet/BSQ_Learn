/*
** EPITECH PROJECT, 2022
** mini_printf
** File description:
** function four part
*/
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int my_put_exp(double nb, int precis, int maj);
int my_put_float_printf(double nb, int n, int maj);
int my_isfloat(float nb);
int my_count_number(int nb);

int find_expo(double nb)
{
    int exp = 0;
    for (;nb >= 10 || nb <= -10; exp++)
        nb /= 10;
    for (;nb < 1 && nb > -1; exp--)
        nb = nb * 10;
    return (exp);
}

int *tab_float(double nb, int precis)
{
    int *tab = malloc(sizeof(int) * (3 + 1));
    double tempNb = nb - ((int) nb);
    int haveNb = 0;
    for (int i = 0; i < precis; i++) {
        tempNb *= 10;
        if ((int) tempNb == 0)
            ++tab[haveNb];
        else {
            ++tab[1];
            haveNb = 2;
        }
        tempNb -= (int) tempNb;
    }
    return (tab);
}

int my_printf_select_g(double nb, int precis, int maj)
{
    int exp = find_expo(nb);
    int *tabInfo = tab_float(nb , precis);
    if ((int) nb == 0 );
}

int my_printf_g(va_list ap)
{

    return (my_printf_select_g(va_arg(ap, double),5,0));
}

int my_printf_gg(va_list ap)
{
    write(2,"specifier not added yet\n",24);
    return 84;
}
