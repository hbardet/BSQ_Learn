/*
** EPITECH PROJECT, 2022
** my_find_prime_sup
** File description:
** return plus petit prime of nb
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    int i = nb;
    while (i >= 2){
        if (my_is_prime(i))
            return (i);
        --i;
    }
    return (0);
}
