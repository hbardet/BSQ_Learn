/*
** EPITECH PROJECT, 2024
** cpp_thread
** File description:
** main
*/

#include "BSQ.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        throw std::runtime_error("Error: invalid number of arguments");
    BSQ::BSQ bsq;
    bsq.openFile(av[1]);
    bsq.parseBSQ();
    bsq.replaceBSQ();
    bsq.displayMap();
    return (0);
}
