/*
** EPITECH PROJECT, 2022
** my_isneg
** File description:
** display N if int is neg and P if pos
*/
void my_putchar(char c);

int my_isneg(int n)
{
    if (n >= 0) {
        my_putchar(80);
    } else {
        my_putchar(78);
    }
    my_putchar('\n');
    return (0);
}
