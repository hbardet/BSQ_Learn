/*
** EPITECH PROJECT, 2022
** my_sort_int_array
** File description:
** sort array with size
*/

void buble_sort(int *tab, int size)
{
    int temp;
    for (int i = 0; i < size - 1; i++){
        if (tab[i] > tab[i + 1]){
            temp = tab[i];
            tab[i] = tab[i + 1];
            tab[i + 1] = temp;
        }
    }
}

void my_sort_int_array(int *tab, int size)
{
    for (int i = 0; i < size; i++)
        buble_sort(tab, size);
}
