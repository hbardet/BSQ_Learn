/*
** EPITECH PROJECT, 2022
** is_alphanum
** File description:
** return if a number is alphanum or not
*/

int my_is_alphanum(char c)
{
    if ((c >= '0' && c <= '9') ||
        (c >= 'A' && c <= 'Z') ||
        (c >= 'a' && c <= 'z')){
        return (1);
    }
    return (0);
}
