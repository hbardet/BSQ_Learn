/*
** EPITECH PROJECT, 2022
** mini_printf
** File description:
** function third part
*/
#include <stdarg.h>
int test_nan_inf(double nb, int maj);
int my_printf(const char *format , ...);

int my_printf_double_value_return(va_list ap)
{
    return va_arg(ap,double);
}

int my_printf_e_extrem(double nb, int maj)
{
    char *expoStrPos = (maj) ? ("E+") : ("e+");
    int len = test_nan_inf(nb, maj);
    if (len != 0)
        return (len);
    if (nb == 0.0) {
        my_printf("0.000000%s00",expoStrPos);
        return 12;
        }
    return 0;
}
