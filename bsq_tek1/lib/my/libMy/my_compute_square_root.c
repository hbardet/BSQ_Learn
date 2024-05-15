/*
** EPITECH PROJECT, 2022
** my_compute_square_root
** File description:
** return square return
*/

#include <stdio.h>



int my_compute_square_root(int nb)
{
    if (nb < 0){
        return (0);
    } else if (nb == 1) {
        return (1);
    } else {
        int sqrtNum;
        sqrtNum = 0;
        while (sqrtNum * sqrtNum < nb){
            sqrtNum++;
        }
        if (sqrtNum * sqrtNum == nb){
            return (sqrtNum);
        } else {
            return (0);
        }
    }
}
