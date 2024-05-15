/*
** EPITECH PROJECT, 2022
** my_strncpy
** File description:
** copy n char from a string to an other
*/

int my_strlen(char const *str);

char *my_strncpy(char *dest, char const *src, int n)
{
    int lenDest = my_strlen(dest);
    int i = 0 ;
    while (i < n && i < lenDest){
        dest[i] = src[i];
        i++;
    }
    if (n > lenDest){
        dest[i] = '\0';
    }
    return (dest);
}
