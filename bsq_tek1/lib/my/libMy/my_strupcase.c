/*
** EPITECH PROJECT, 2022
** my_strupcase
** File description:
** add in time
*/

char *my_strupcase(char *str)
{
    int i = 0;
    while (str[i]){
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
        i++;
    }
    return (str);
}
