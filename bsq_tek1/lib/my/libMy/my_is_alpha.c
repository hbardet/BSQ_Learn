/*
** EPITECH PROJECT, 2022
** my_is_alpha
** File description:
** return if char is alpha or not
*/

int my_is_alpha(char c)
{
    if ((c >= 'a' && c <= 'z') ||
        (c >= 'A' && c <= 'Z')){
        return (1);
    }
    return (0);
}
