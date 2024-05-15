/*
** EPITECH PROJECT, 2022
** my_swap
** File description:
** swap 2 number
*/

void my_swap(int *a, int *b)
{
    int bufferNum;
    bufferNum = *a;
    *a = *b;
    *b = bufferNum;
}
