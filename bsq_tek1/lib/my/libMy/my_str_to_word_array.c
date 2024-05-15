/*
** EPITECH PROJECT, 2022
** my_str_to_word_array
** File description:
** splits a string into word
*/

#include <stdio.h>
#include <stdlib.h>

int my_is_alphanum(char c);

int do_count_word(char const *str)
{
    int i = 0;
    int j = 0;
    int countWord = 0;
    while (str[i]){
        j = 1;
        while (my_is_alphanum(str[i])){
            i++;
            j = 0;
        }
        if (j == 1)
            i++;
        else
            countWord++;
    }
    return (countWord);
}

int do_count_char(char const *str, int index)
{
    int i = index;
    int countChar = 0;
    while (my_is_alphanum(str[i])){
        ++countChar;
        ++i;
    }
    return (countChar);
}

void do_all_malloc_tab(char const *str, char **tab, int countWord)
{
    int index = 0;
    int tempMemo = 0;
    int i = 0;
    while (i < countWord){
        while (do_count_char(str,index) == 0){
            ++index;
        }
        tempMemo = do_count_char(str, index);
        tab[i] = malloc(sizeof(char) * (tempMemo + 1));
        index += tempMemo + 1;
        i++;
    }
}

char **my_str_to_word_array(char const *str)
{
    int i = 0;
    int j = 0;
    int x = 0;
    int countWord = do_count_word(str);
    char **tab = malloc(sizeof(char *) * (countWord + 1));
    do_all_malloc_tab(str, tab, countWord);
    for (i = 0; i < countWord; i++){
        j = 0;
        while (do_count_char(str, x) == 0){
            ++x;
        }
        while (do_count_char(str, x)){
            tab[i][j] = str[x];
            tab[i][j + 1] = '\0';
            ++x;
            ++j;
        }
    }
    tab[i] = '\0';
    return (tab);
}
