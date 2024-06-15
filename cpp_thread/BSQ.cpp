/*
** EPITECH PROJECT, 2024
** cpp_thread
** File description:
** BSQ
*/

#include "BSQ.hpp"
#include <cstddef>
#include <fstream>
#include <mutex>

BSQ::BSQ::BSQ(): _sizeMap(0), _sizeSquare(0), _map(""), _y(0), _x(0)
{
    _threadPool.Start();
}

BSQ::BSQ::~BSQ()
{
}

void BSQ::BSQ::openFile(const std::string &filename)
{
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open())
        throw std::runtime_error("Error: file not found");

    while (std::getline(file, line)) {
        if (_sizeMap == 0)
            _sizeMap = std::stoi(line);
        else
            _map += line + "\n";
    }
}

void BSQ::BSQ::displayMap()
{
    std::cout << _map;
}

void BSQ::BSQ::writeBSQ()
{
    replaceBSQ();
    displayMap();
}

void BSQ::BSQ::newCord()
{
    std::unique_lock<std::mutex> lock(_mutex);
    std::cout << "[" << _x << "," << _y << "] = " << _sizeSquare << std::endl;
}

void BSQ::BSQ::findBSQ(std::size_t x, std::size_t y)
{
    std::size_t tmpSizeSquare = 1;

    while (1) {
        if (x + tmpSizeSquare > _sizeMap || y + tmpSizeSquare > _sizeMap)
            return;
        for (std::size_t height = 0; height < tmpSizeSquare; height++) {
            if (getCell(x + tmpSizeSquare - 1, y + height) != '.')
                return;
        }
        for (std::size_t width = 0; width < tmpSizeSquare; width++) {
            if (getCell(x + width, y + tmpSizeSquare - 1) != '.')
                return;
        }
        if (tmpSizeSquare > _sizeSquare) {
            std::unique_lock<std::mutex> lock(_mutex);
            _x = x;
            _y = y;
            _sizeSquare = tmpSizeSquare;
        }
        tmpSizeSquare++;
    }
}

void BSQ::BSQ::parseBSQ()
{
    for (std::size_t height = 0; height < _sizeMap; height++)
        _threadPool.QueueJob([this, height] { parseLineBSQ(height); });
    _threadPool.waitEndQueue();
    _threadPool.Stop();
}

void BSQ::BSQ::parseLineBSQ(std::size_t y)
{
    for (std::size_t width = 0; width < _sizeMap; width++) {
        if (getCell(width, y) == '.')
            findBSQ(width, y);
    }
}

char BSQ::BSQ::getCell(std::size_t x, std::size_t y)
{
    return (_map[(y * (_sizeMap + 1)) + x]);
}

void BSQ::BSQ::replaceBSQ()
{
    for (std::size_t height = 0; height < _sizeSquare; height++) {
        for (std::size_t width = 0; width < _sizeSquare; width++) {
            _map[((_y + height) * (_sizeMap + 1)) + _x + width] = 'x';
        }
    }
}
