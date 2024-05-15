/*
** EPITECH PROJECT, 2022
** my_get_nbr
** File description:
** get nbr in a string
*/

#include "../my.h"
#include <stdlib.h>
#include <stdio.h>


int is_number(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    else
        return (0);
}

int lenght_numb(char const *str, int index)
{
    int countNumb = 0;
    while (is_number(str[index + countNumb]))
        ++countNumb;
    return (countNumb);
}

int calculate_nb(int index, char const *str, int lenNumb)
{
    long long finalNumb = 0;
    int x;
    int temp;
    for (x = 0; x < lenNumb; x++) {
        temp = str[index - 1] - 48;
        finalNumb += (temp * my_compute_power_rec(10, x));
        index--;
    }
    if (finalNumb >= 2147483647 && finalNumb <= -2147483648)
        return (0);
    else
        return (finalNumb);
}

int my_getnbr(char const *str)
{
    int numb = 0;
    int lenNumb = 0;
    int i = 0;
    while (str[i] && lenNumb == 0){
        if (is_number(str[i]))
            lenNumb = lenght_numb(str,i);
        ++i;
    }
    numb = calculate_nb(i + lenNumb - 1, str, lenNumb);
    if (i == 1)
        return (numb);
    else if (str[i - 2] == '-')
        return (- 1 * numb);
    return (numb);
}
