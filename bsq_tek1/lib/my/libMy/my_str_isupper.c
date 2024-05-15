/*
** EPITECH PROJECT, 2022
** my_str_isupper
** File description:
** add in time
*/

int my_str_isupper(char const *str)
{
    int i = 0;
    while (str[i]){
        if (!(str[i] >= 'A' && str[i] <= 'Z'))
            return (0);
        ++i;
    }
    return (1);
}
