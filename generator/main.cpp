/*
** EPITECH PROJECT, 2024
** bsq_tek1
** File description:
** main
*/

#include <charconv>
#include <cstdlib>
#include <fstream>
#include <string>
#include <ctime>
#include <iostream>
#include <format>

int main(int argc, char **argv)
{
    if (argc != 3) {
        std::cerr << "invalid argument number" << std::endl;
        return (84);
    }
    std::string map;
    int size = std::atoi(argv[1]);
    float density = std::atof(argv[2]);
    if (size < 0 || density < 0) {
        std::cerr << "invalid size or density" << std::endl;
        return 84;
    }
    std::ofstream out(std::format("map_{}_{}", size, size));
    std::srand(std::time(nullptr));
    map += std::to_string(size) + '\n';
    for (int height = 0; height < size; height++){
        for (int width = 0; width < size; width++){
            if (std::rand() / ((RAND_MAX + 1u) / 100) < density)
                map += 'o';
            else 
                map += '.';
        }
        map += '\n';
    }
    out << map;
}
