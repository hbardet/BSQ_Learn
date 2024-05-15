/*
** EPITECH PROJECT, 2022
** mini_printf
** File description:
** function
*/
#include <stdarg.h>

int my_putstr(char const *str);
int my_strlen(char const *str);
int my_str_isprintable (char const *str);
void my_putchar(char c);
int my_put_octal(unsigned int nb, int count);

int my_putchar_nonprintable_octal(char str)
{
    if (str < 32 || str > 126) {
        my_putchar('\\');
        if (str < 8)
            my_putchar('0');
        if (str < 64)
            my_putchar('0');
        my_put_octal(str,0);
        return 4;
    } else {
        my_putchar(str);
        return 1;
    }
}

int my_printf_s(va_list ap)
{
    char *s = va_arg(ap,char *);
    my_putstr(s);
    return my_strlen(s);
}

int my_printf_ss(va_list ap)
{
    char *str = va_arg(ap,char *);
    int i = 0;
    if (my_str_isprintable(str)) {
        my_putstr(str);
        return my_strlen(str);
    } else {
        int count = 0;
        while (str[i]) {
            count += my_putchar_nonprintable_octal(str[i]);
            i++;
        }
        return count;
    }
    return 0;
}

int my_printf_s_params(char *s)
{
    my_putstr(s);
    return my_strlen(s);
}

int my_printf_ss_params(char *str)
{
    int i = 0;
    if (my_str_isprintable(str)) {
        my_putstr(str);
        return my_strlen(str);
    } else {
        int count = 0;
        while (str[i]) {
            count += my_putchar_nonprintable_octal(str[i]);
            i++;
        }
        return count;
    }
    return 0;
}
