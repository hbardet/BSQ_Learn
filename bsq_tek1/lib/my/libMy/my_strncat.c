/*
** EPITECH PROJECT, 2022
** my_strncat
** File description:
** concatenates n char of src
*/
int my_strlen(char const *str);

char *my_strncat(char *dest, char const *src, int nb)
{
    int lenDest = my_strlen(dest);
    int lenSrc = my_strlen(src);
    char *ptrEndDest = dest;
    int i;
    for (i = 0; i < lenDest; i++){
        ++ptrEndDest;
    }
    i = 0;
    while (i < nb && i < lenSrc){
        *ptrEndDest = *src;
        ++ptrEndDest;
        ++src;
        ++i;
    }
    *ptrEndDest = '\0';
    return (dest);
}
