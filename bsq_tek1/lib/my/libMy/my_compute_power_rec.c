/*
** EPITECH PROJECT, 2022
** my_compute_power_rec
** File description:
** pow in rec
*/

int my_compute_power_rec(int nb, int p)
{
    long longNb = nb;
    if (p < 0)
        return (0);
    else if (p == 0)
        return (1);
    longNb = longNb * my_compute_power_rec(longNb, p - 1);
    if (longNb > 2147483647 || longNb < -2147483648)
        return (0);
    return (longNb);
}
