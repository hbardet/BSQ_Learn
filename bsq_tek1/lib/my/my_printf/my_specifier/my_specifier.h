/*
** EPITECH PROJECT, 2022
** my_printf headeré
** File description:
** header for all files
*/

#ifndef MY_SPECIFIER_H_
    #define MY_SPECIFIER_H_
    int my_printf_b(va_list ap);
    int my_printf_c(va_list ap);
    int my_printf_d(va_list ap);
    int my_printf_e(va_list ap);
    int my_printf_ee(va_list ap);
    int my_printf_f(va_list ap);
    int my_printf_ff(va_list ap);
    int my_printf_g(va_list ap);
    int my_printf_gg(va_list ap);
    int my_printf_o(va_list ap);
    int my_printf_p(va_list ap);
    int my_printf_percent(va_list ap);
    int my_printf_s(va_list ap);
    int my_printf_ss(va_list ap);
    int my_printf_u(va_list ap);
    int my_printf_x(va_list ap);
    int my_printf_xx(va_list ap);

    int my_printf_int_value_return(va_list ap);
    int my_printf_double_value_return(va_list ap);
    int my_printf_unsigned_int_value_return(va_list ap);
    int my_printf_long_int_value_return(va_list ap);

    int my_printf_b_params(unsigned int nb);
    int my_printf_c_params(int nb);
    int my_printf_d_params(int nb);
    int my_printf_e_params(double nb);
    int my_printf_ee_params(double nb);
    int my_printf_f_params(double nb);
    int my_printf_ff_params(double nb);
    int my_printf_g_params(double nb);
    int my_printf_gg_params(double nb);
    int my_printf_o_params(unsigned int nb);
    int my_printf_p_params(unsigned int nb);
    int my_printf_percent_params(void);
    int my_printf_s_params(char *s);
    int my_printf_ss_params(char *str);
    int my_printf_u_params(unsigned int nb);
    int my_printf_x_params(unsigned int nb);
    int my_printf_xx_params(unsigned int nb);

#endif /* MY_SPECIFIER_H_ */
