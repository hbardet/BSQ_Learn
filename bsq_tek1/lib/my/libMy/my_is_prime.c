/*
** EPITECH PROJECT, 2022
** my_is_prime
** File description:
** find if a number is prime
*/

int my_is_prime(int nb)
{
    if (nb < 2)
        return (0);
    int i = 2;
    while (i < nb / 2){
        if (nb % i == 0)
            return (0);
        ++i;
    }
    return (1);
}
