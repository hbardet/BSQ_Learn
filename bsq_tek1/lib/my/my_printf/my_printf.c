/*
** EPITECH PROJECT, 2022
** mini_printf
** File description:
** miniprintf
*/
#include <stdio.h>
#include <stdarg.h>
#include "my_specifier/my_specifier.h"

void my_putchar(char c);
int my_strlen(char const *str);

int my_printf_fag_minus(va_list ap,int i, const char *format);
int my_printf_fag_plus(va_list ap,int i, const char *format);
int my_printf_fag_null(va_list ap,int i, const char *format);
int my_printf_fag_space(va_list ap,int i, const char *format);
int my_printf_fag_disease(va_list ap,int i, const char *format);
int my_printf_specifiers(va_list ap, int i,const char *format);
int my_printf_wt(va_list ap, int i, const char *format);
int my_printf_wt_detec(va_list ap, int i, const char *format);
int my_printf_prec(va_list ap,int i, const char *format);
int my_count_number(int nb);
int my_printf_detect_number(int i, const char *format);

int my_printf_fag(va_list ap, int i, const char *format)
{
    if (format[i] == '+' || format[i] == '0'
    || format[i] == ' ' || format[i] == '#' || format[i] == '-') {
        if (format[i + 1] > 47 && format[i + 1] < 58) {
            int nbr =
            my_count_number(my_printf_detect_number(i + 1,format)) + 1;
            return nbr;
            }
        return 1;
    }
    return 0;
}

int my_printf_specifier(va_list ap, int i, const char *format)
{
    char specifiers[20] = "scid%SbeEfgGouxXpF";
    int index = 0;
    while (specifiers[index] != format[i] && index <= my_strlen(specifiers))
        index++;
    if (index <= my_strlen(specifiers))
        return 1;
    else
        return 0;
}

int my_printf_fag_detected(va_list ap, int i, const char *format)
{
    int (*tab_flags[6])(va_list,int, const char *) = {&my_printf_fag_minus,
    &my_printf_fag_plus, &my_printf_fag_null, &my_printf_fag_space,
    &my_printf_fag_disease, 0};
    char flags[6] = "-+0 #";
    int index = 0;
    while (flags[index] != format[i] && index <= my_strlen(flags))
        index++;
    if (index <= my_strlen(flags))
        return tab_flags[index](ap, i + 1, format);
}

int my_printf_rec(const char *format , va_list ap, int count, int i)
{
    if (!format[i])
        return count;
    if (format[i] == '%') {
        if (my_printf_fag(ap,i + 1,format) > 0)
            return my_printf_rec(format,ap,count + my_printf_fag_detected
            (ap, i + 1, format) + 2, i + my_printf_fag(ap,i + 1,format) + 2);
        if (my_printf_wt(ap,i + 1,format) > 0)
            return my_printf_rec(format,ap,count + my_printf_wt_detec(ap, i + 1,
            format) + 2,i + 2 + my_count_number(my_printf_wt(ap,i + 1,format)));
        if (my_printf_specifier(ap,i + 1,format))
            return my_printf_rec(format,ap,count + my_printf_specifiers
            (ap,i + 1,format),i + 2);
        my_putchar('%');
        return my_printf_rec(format,ap,count + 1,i + 1);
    } else {
        my_putchar(format[i]);
        return my_printf_rec(format,ap,count + 1,i + 1);
    }
}

int my_printf(const char *format , ...)
{
    va_list ap;
    int count = 0;
    va_start(ap, format);
    count = my_printf_rec(format,ap,count,0);
    va_end(ap);
    return count;
}
