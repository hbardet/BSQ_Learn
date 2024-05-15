/*
** EPITECH PROJECT, 2022
** my_put_float
** File description:
** print a float
*/

void my_putchar(char c);

int my_put_nbr(int nb);

int my_put_float(float nb)
{
    my_put_nbr(nb);
    my_putchar('.');
    int integer = nb;
    int flt = (nb * 100) - (integer * 100);
    my_put_nbr(flt);
    return (0);
}
