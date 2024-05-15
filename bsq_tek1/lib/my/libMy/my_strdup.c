/*
** EPITECH PROJECT, 2022
** my_strdup
** File description:
** allocates memory and copies the string given as argument
*/

#include <stdlib.h>

int my_strlen(char const *src);

char *my_strdup(char const *src)
{
    int lenSrc = my_strlen(src);
    char *newStr;
    newStr = malloc(sizeof(char) * (lenSrc + 1));
    int i;
    for (i = 0; i < lenSrc; i++)
        newStr[i] = src[i];
    newStr[i] = '\0';
    return (newStr);
}
