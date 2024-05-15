/*
** EPITECH PROJECT, 2022
** my_revstr
** File description:
** reverse a string
*/

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    int lenStr = my_strlen(str);
    char *ptrFirst = str;
    char *ptrLast = str + lenStr - 1;
    char bufferChar;
    while (ptrFirst < ptrLast){
        bufferChar = *ptrFirst;
        *ptrFirst = *ptrLast;
        *ptrLast = bufferChar;
        ptrFirst++;
        ptrLast--;
    }
    return (str);
}
