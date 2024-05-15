/*
** EPITECH PROJECT, 2022
** my_strlowcase
** File description:
** add in time
*/

char *my_strlowcase(char *str)
{
    int i = 0;
    while (str[i]){
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        i++;
    }
    return (str);
}
