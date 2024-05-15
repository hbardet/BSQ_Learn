/*
** EPITECH PROJECT, 2022
** my_strcapitalize
** File description:
** add in time
*/

int my_is_lower(char c);
int my_is_alphanum(char c);
int my_is_upper(char c);

char *my_strcapitalize(char *str)
{
    int i = 0;
    int newWord = 1;
    while (str[i]){
        if (my_is_lower(str[i]) && newWord){
            str[i] -= 32;
            newWord = 0;
        }
        if (my_is_upper(str[i]) && newWord == 0)
            str[i] += 32;
        if (!(my_is_alphanum(str[i])))
            newWord = 1;
        i++;
    }
    return (str);
}
