/*
** EPITECH PROJECT, 2022
** my_strncmp
** File description:
** add in time
*/
int my_strlen(char const *str);

int minus_numb(int a, int b);

int my_strncmp(char const *s1, char const *s2, int n)
{
    int lenS1 = ((my_strlen(s1)) > n) ? (n) : (my_strlen(s1));
    int lenS2 = ((my_strlen(s2)) > n) ? (n) : (my_strlen(s1));
    int lenMin = minus_numb(lenS1, lenS2);
    int i;
    for (i = 0; i < lenMin; i++){
        if (s1[i] < s2[i])
            return (-1);
        if (s1[i] > s2[i])
            return (1);
    }
    if (lenS1 == lenS2)
        return (0);
    if (lenS1 == lenMin){
        return (-1);
    } else if (lenS2 == lenMin){
        return (1);
    }
    return (0);
}
