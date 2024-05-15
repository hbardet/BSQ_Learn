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

int my_printf_specifiers(va_list ap, int i,const char *format)
{
    int (*tab_specifiers[19])(va_list) = {&my_printf_s, &my_printf_c,
    &my_printf_d, &my_printf_d, &my_printf_percent, &my_printf_ss,
    &my_printf_b, &my_printf_e, &my_printf_ee, &my_printf_f,
    &my_printf_g, &my_printf_gg, &my_printf_o, &my_printf_u,
    &my_printf_x, &my_printf_xx, &my_printf_p,
    &my_printf_ff,0};
    char specifiers[20] = "scid%SbeEfgGouxXpF";
    int index = 0;
    while (specifiers[index] != format[i] && index <= my_strlen(specifiers))
        index++;
    if (index <= my_strlen(specifiers)) {
        return tab_specifiers[index](ap);
    } else {
        return tab_specifiers[4](ap);
    }
}

int my_printf_specifiers_value_return(va_list ap, int i,const char *format)
{
    int (*tab_specifiers_value_return[15])(va_list) = {
    &my_printf_int_value_return, &my_printf_int_value_return,
    &my_printf_unsigned_int_value_return, &my_printf_double_value_return,
    &my_printf_double_value_return, &my_printf_double_value_return,
    &my_printf_double_value_return, &my_printf_double_value_return,
    &my_printf_unsigned_int_value_return, &my_printf_unsigned_int_value_return,
    &my_printf_unsigned_int_value_return, &my_printf_unsigned_int_value_return,
    &my_printf_long_int_value_return, &my_printf_double_value_return, 0};
    char specifiers[15] = "idbeEfgGouxXpF";
    int index = 0;
    while (specifiers[index] != format[i] && index <= my_strlen(specifiers))
        index++;
    if (index <= my_strlen(specifiers)) {
        return tab_specifiers_value_return[index](ap);
    }
}

int my_printf_specifiers_params(int nb, int i,const char *format)
{
    int (*tab_specifiers_params[19])() = {&my_printf_s_params,
    &my_printf_c_params, &my_printf_d_params, &my_printf_d_params,
    &my_printf_percent_params, &my_printf_ss_params, &my_printf_b_params,
    &my_printf_e_params, &my_printf_ee_params, &my_printf_f_params,
    &my_printf_g_params, &my_printf_gg_params, &my_printf_o_params,
    &my_printf_u_params, &my_printf_x_params, &my_printf_xx_params,
    &my_printf_p_params, &my_printf_ff_params, 0};
    char specifiers[19] = "scid%SbeEfgGouxXpF";
    int index = 0;
    while (specifiers[index] != format[i] && index <= my_strlen(specifiers))
        index++;
    if (index <= my_strlen(specifiers))
        return tab_specifiers_params[index](nb);
}
