package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

type bsq struct{
    size_map int
    map_bsq string
    x int
    y int
    size_square int
}

func check(e error) {
    if e != nil {
        panic(e)
    }
}

func (b *bsq) open_file(path string) { 
    file, err := os.ReadFile(path)
    check(err)
    parts := strings.SplitN(string(file), "\n", 2)

    b.size_map, err = strconv.Atoi(parts[0])
    if err != nil {
        panic(err)
    }
    b.map_bsq = parts[1]
}

func (b *bsq) get_cell(x int, y int) byte {
    return b.map_bsq[((y * (b.size_map + 1)) + x)];
}

func (b *bsq) find_bsq(x int, y int) {
    size_square := 1

    for true {
        if x + size_square > b.size_map || y + size_square > b.size_map {
            return;
        }
        for height := range size_square {
            if b.get_cell(x + size_square - 1, y + height) != '.' {
                return;
            }
        }
        for width := range size_square {
            if b.get_cell(x + width, y + size_square - 1) != '.' {
                return;
            }
        }
        if size_square > b.size_square {
            b.x = x
            b.y = y
            b.size_square = size_square
        }
        size_square++
    }
}

func (b *bsq) parse_map() {
    for height := range b.size_map {
        for width := range b.size_map {
            if b.get_cell(width, height) == '.' {
                b.find_bsq(width, height)
            }
        }
    }
}

func (b *bsq) replace_bsq() {
    new_map := []rune(b.map_bsq)
    for height := range b.size_square {
        for width := range b.size_square {
             new_map[(((height + b.y) * (b.size_map + 1)) + (width + b.x))] = 'x';
        }
    }
    b.map_bsq = string(new_map)
}

func (b bsq) display_map() {
    fmt.Print(b.map_bsq)
}
