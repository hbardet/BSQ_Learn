/*
** EPITECH PROJECT, 2022
** my_strcat
** File description:
** add in time
*/
int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int lenDest = my_strlen(dest);
    int lenSrc = my_strlen(src);
    char *ptrEndDest = dest;
    int i;
    for (i = 0; i < lenDest; i++){
        ++ptrEndDest;
    }
    for (i = 0; i < lenSrc; i++){
        *ptrEndDest = *src;
        ++ptrEndDest;
        ++src;
    }
    *ptrEndDest = '\0';
    return (dest);
}
