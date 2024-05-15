/*
** EPITECH PROJECT, 2022
** my_strcmp
** File description:
** compare 2 str lexicallement
*/
int my_strlen(char const *str);

int minus_numb(int a, int b)
{
    if (a > b){
        return (b);
    } else {
        return (a);
    }
    return (0);
}

int my_strcmp(char const *s1, char const *s2)
{
    int lenS1 = my_strlen(s1);
    int lenS2 = my_strlen(s2);
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
