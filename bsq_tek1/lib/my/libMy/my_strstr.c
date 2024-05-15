/*
** EPITECH PROJECT, 2022
** my_strstr
** File description:
** find a sub str in str
*/

int my_strncmp(char *s1, char *s2, int n);
int my_strlen(char const *str);

char *my_strstr(char *str, char *to_find)
{
    int lenFind = my_strlen(to_find);
    char *ptrStr = str;
    int i = 0;
    while (str[i]){
        if (my_strncmp(ptrStr, to_find, lenFind - 1) == 0)
            return (ptrStr);
        ptrStr = str + i;
        ++i;
    }
    return (str);
}
