/*
** EPITECH PROJECT, 2024
** cpp_thread
** File description:
** BSQ
*/


#pragma once
#include <cstddef>
#include <iostream>

namespace BSQ {
    class BSQ {
    public:
        BSQ();
        ~BSQ();
        void openFile(const std::string &filename);
        void displayMap(void);
        void findBSQ(std::size_t x, std::size_t y);
        void parseBSQ(void);
        void parseLineBSQ(std::size_t y);
        void writeBSQ(void);
        char getCell(std::size_t x, std::size_t y);
        void replaceBSQ(void);
    private:
        std::size_t _sizeMap;
        std::size_t _sizeSquare;
        std::string _map;
        std::size_t _y;
        std::size_t _x;
    };
}
