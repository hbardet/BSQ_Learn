/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** compute file
*/
#include <stdarg.h>

void my_putchar(char c);
int my_put_nbr(int nb);
int my_compute_power_rec(int nb, int power);
int my_putstr(char const *str);
int my_count_number(int nb);

int test_nan_inf(double nb, int maj)
{
    char *inf = (maj) ? ("INF") : ("inf");
    char *nan = (maj) ? ("NAN") : ("nan");
    if (nb == 1.0 / 0.0) {
        my_putstr(inf);
        return (3);
    }
    if (nb == -1.0 / 0.0) {
        my_putchar('-');
        my_putstr(inf);
        return (4);
    }
    if (nb != nb) {
        my_putstr(nan);
        return (3);
    }
    return (0);
}

double round_float_number(double nb, int n)
{
    int integer = nb;
    long double flt = (nb - integer) * my_compute_power_rec(10, n + 1);
    long double round = (nb - integer) * my_compute_power_rec(10, n);
    int result = (flt - (round * 10));
    result = (result < 0) ? (result * -1) : (result);
    if (result >= 5){
        double j = 1;
        for (int i = 0; i < n ; i++)
            j /= 10;
        return (j);
    } else
        return (0.0);
    return (0.0);
}

int my_put_float_printf(double nb, int n, int maj)
{
    int len = test_nan_inf(nb, maj);
    int integer = nb;
    double round = round_float_number(nb, n);
    double flt = (nb + round) - integer;
    flt = (flt < 0) ? (flt * -1) : (flt);
    if (len != 0)
        return (len);
    my_put_nbr((int) nb);
    if (n >= 0){
        my_putchar('.');
        n++;
    }
    for (int i = 0; i < n - 1; i++){
        flt *= 10;
        integer = flt;
        my_put_nbr(flt);
        flt -= integer;
    }
    return (my_count_number(nb) + n);
}

int my_printf_f(va_list ap)
{
    return (my_put_float_printf(va_arg(ap, double), 6, 0));
}

int my_printf_ff(va_list ap)
{
    return (my_put_float_printf(va_arg(ap, double), 6, 1));
}
