/*
** EPITECH PROJECT, 2022
** mini_printf
** File description:
** miniprintf
*/
#include <stdio.h>
#include "my_specifier/my_specifier.h"
#include <stdarg.h>
void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_printf_specifiers(va_list ap, int i,const char *format);
int my_printf_specifiers_value(va_list ap, int i,const char *format);
int my_printf_specifiers_value_return(va_list ap, int i,const char *format);
int my_printf_specifiers_params(int nb, int i,const char *format);
int my_printf_prec(va_list ap,int i, const char *format);
int my_count_number(int nb);

int my_printf_detect_number(int i, const char *format)
{
    int nbr = 0;
    while (format[i] > 47 && format[i] < 58) {
        nbr = nbr * 10;
        nbr = nbr + format[i] - '0';
        i++;
    }
    return nbr;
}

int my_printf_wt_number(va_list ap,int i, const char *format)
{
    int count = 0;
    int nbr = my_printf_detect_number(i,format);
    int value = my_printf_specifiers_value_return(ap,i +
    my_count_number(nbr),format);
    for (int index = nbr - my_count_number(value);index > 0;index--) {
        my_putchar(' ');
        count++;
    }
    my_printf_specifiers_params(value,i + my_count_number(nbr),format);
    return count;
}

int my_printf_wt_star(va_list ap,int i, const char *format)
{
    int count = 0;
    int nbr = va_arg(ap,int);
    int value = my_printf_specifiers_value_return(ap,i +
    my_count_number(nbr),format);
    for (int index = nbr - my_count_number(value);index > 0;index--) {
        my_putchar(' ');
        count++;
    }
    my_printf_specifiers_params(value,i + my_count_number(nbr),format);
    return count;
}

int my_printf_wt(va_list ap, int i, const char *format)
{
    if (format[i] > 47 && format[i] < 58) {
        int nbr = my_printf_detect_number(i,format);
        return nbr;
    }
    if (format[i] == '*') {
        return 1;
    }
    if (format[i] == '.') {
        return 11;
    }
    return 0;
}

int my_printf_wt_detec(va_list ap, int i, const char *format)
{
    int (*tab_width[12])(va_list,int, const char *) = {
    &my_printf_wt_number, &my_printf_wt_number, &my_printf_wt_number,
    &my_printf_wt_number, &my_printf_wt_number, &my_printf_wt_number,
    &my_printf_wt_number, &my_printf_wt_number,
    &my_printf_wt_number, &my_printf_wt_star,my_printf_prec,0};
    char width[12] = "123456789*.";
    int index = 0;
    while (width[index] != format[i] && index <= my_strlen(width))
        index++;
    if (index <= my_strlen(width))
        return tab_width[index](ap, i, format);
}
