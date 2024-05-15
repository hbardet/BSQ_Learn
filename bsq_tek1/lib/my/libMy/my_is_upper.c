/*
** EPITECH PROJECT, 2022
** my_is_upper
** File description:
** return if char is UPPER or not
*/

int my_is_upper(char c)
{
    if (c >= 'A' && c <= 'Z'){
        return (1);
    }
    return (0);
}
