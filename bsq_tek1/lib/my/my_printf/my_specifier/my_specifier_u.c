/*
** EPITECH PROJECT, 2022
** mini_printf
** File description:
** function four part
*/
#include <stdarg.h>

void my_putchar(char c);
int my_count_number(int nb);

void my_print_unsigned_int(unsigned int nb)
{
    if (nb > 9)
        my_print_unsigned_int(nb / 10);
    my_putchar((nb % 10) + 48);
}

unsigned int my_put_unsigned_nbr(unsigned int nb)
{
    if (nb > 0){
        my_print_unsigned_int(nb);
    } else if (nb < 0) {
        my_putchar(45);
        my_print_unsigned_int(-(nb));
    } else {
        my_putchar(48);
    }
    return 0;
}

int my_printf_u(va_list ap)
{
    unsigned int nb_unsigned = va_arg(ap,unsigned int);
    my_put_unsigned_nbr(nb_unsigned);
    return my_count_number(nb_unsigned);
}

int my_printf_u_params(unsigned int nb)
{
    my_put_unsigned_nbr(nb);
    return my_count_number(nb);
}
