/*
** EPITECH PROJECT, 2022
** my_str_isnum
** File description:
** add in time
*/

int my_str_isnum(char const *str)
{
    int i = 0;
    while (str[i]){
        if (!(str[i] >= '0' && str[i] <= '9'))
            return (0);
        ++i;
    }
    return (1);
}
