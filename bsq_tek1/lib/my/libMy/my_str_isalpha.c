/*
** EPITECH PROJECT, 2022
** my_str_isalpha
** File description:
** add in time
*/

int my_str_isalpha(char const *str)
{
    int i = 0;
    while (str[i]){
        if (!(str[i] >= 'a' && str[i] <= 'z' ||
            str[i] >= 'A' && str[i] <= 'Z'))
            return (0);
        ++i;
    }
    return (1);
}
