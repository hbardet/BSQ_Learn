/*
** EPITECH PROJECT, 2022
** my_show_word_array
** File description:
** function that display the content of an array of word
*/

void my_putchar(char c);
int my_putstr(char const *str);

int my_show_word_array(char * const *tab)
{
    int i = 0;
    while (tab[i]){
        my_putstr(tab[i]);
        my_putchar('\n');
        i++;
    }
    return (1);
}
