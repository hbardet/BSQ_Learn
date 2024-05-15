/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** flags 1
*/
#include <stdarg.h>
void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_printf_specifiers(va_list ap, int i,const char *format);
int my_printf_specifiers_value_return(va_list ap, int i,const char *format);
int my_printf_specifiers_params(int nb, int i,const char *format);
int my_printf_detect_number(int i, const char *format);
int my_count_number(int nb);

int my_printf_fag_minus(va_list ap,int i, const char *format)
{
    int count = 0;
    if (format[i] > 47 && format[i] < 58) {
        int nbr = my_printf_detect_number(i,format);
        for (int index = nbr -
        my_printf_specifiers(ap,i + my_count_number(nbr),format);
        index > 0;index--) {
            my_putchar(' ');
            count ++;
        }
    } else
        my_printf_specifiers(ap,i,format);
    return count;
}

int my_printf_fag_plus(va_list ap,int i, const char *format,...)
{
    int count = 0;
    int value = my_printf_specifiers_value_return(ap,i,format);
    if (value > 0) {
        my_putchar('+');
        count++;
    }
    my_printf_specifiers_params(value,i,format);
    return count;
}

int my_printf_fag_null(va_list ap,int i, const char *format)
{
    int count = 0;
    int nbr = my_printf_detect_number(i,format);
    int count_nbr;
    if (nbr != 0)
        count_nbr = my_count_number(nbr);
    else
        count_nbr = nbr;
    int value = my_printf_specifiers_value_return(ap,i +
    count_nbr,format);
    for (int index = nbr - my_count_number(value);index > 0;index--) {
        my_putchar('0');
        count++;
    }
    my_printf_specifiers_params(value,i + count_nbr,format);
    return count;
}

int my_printf_fag_space(va_list ap,int i, const char *format)
{
    int count = 0;
    my_putchar(' ');
    count++;
    my_printf_specifiers(ap,i,format);
    return count;
}

int my_printf_fag_disease(va_list ap,int i, const char *format)
{
    int count = 0;
    if (format[i] == 88) {
        my_putstr("0X");
        count = count + 2;
    }
    if (format[i] == 111) {
        my_putchar('0');
        count++;
    }
    if (format[i] == 120) {
        my_putstr("0x");
        count = count + 2;
    }
    if (format[i] == 98) {
        my_putstr("0b");
        count = count + 2;
    }
    my_printf_specifiers(ap,i,format);
    return count;
}
