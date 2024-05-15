/*
** EPITECH PROJECT, 2022
** new strlen
** File description:
** the new str len
*/

int my_strlen(char const *str)
{
    int i = 0;
    while (str[i] != '\0')
        i += 1;
    return (i);
}
