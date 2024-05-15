/*
** EPITECH PROJECT, 2022
** mini_printf
** File description:
** count number
*/

int my_count_number(int nb)
{
    int count = (nb >= 0) ? (1) : (2);
    while (nb > 9) {
        nb /= 10;
        count += 1;
    }

    while (nb < -9) {
        nb /= 10;
        count += 1;
    }
    return count;
}
