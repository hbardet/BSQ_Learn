/*
** EPITECH PROJECT, 2022
** my_str_islower
** File description:
** add in time
*/

int my_str_islower(char const *str)
{
    int i = 0;
    while (str[i]){
        if (!(str[i] >= 'a' && str[i] <= 'z'))
            return (0);
        ++i;
    }
    return (1);
}
