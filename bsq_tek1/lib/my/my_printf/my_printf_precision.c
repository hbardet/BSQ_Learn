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
int my_printf_fag(va_list ap, int i, const char *format);
int my_printf_fag_detected(va_list ap, int i, const char *format);
int my_printf_specifiers_value_return(va_list ap, int i,const char *format);
int my_printf_specifiers_params(int nb, int i,const char *format);
int my_count_number(int nb);
int my_printf_detect_number(int i, const char *format);
int my_printf_prec(va_list ap,int i, const char *format)
{
    int count = 0;
    int nbr = my_printf_detect_number(i + 1,format);
    int value = my_printf_specifiers_value_return(ap,i +
    my_count_number(nbr) + 1,format);
    for (int index = nbr - my_count_number(value);index > 0;index--) {
        my_putchar('0');
        count++;
    }
    my_printf_specifiers_params(value,i + my_count_number(nbr) + 1,format);
    return count;
}
