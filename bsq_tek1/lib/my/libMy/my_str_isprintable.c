/*
** EPITECH PROJECT, 2022
** my_str_isprintable.c
** File description:
** add in time
*/

int my_str_isprintable(char const *str)
{
    int i = 0;
    while (str[i]){
        if (!(str[i] >= ' ' && str[i] <= '~'))
            return (0);
        ++i;
    }
    return (1);
}
