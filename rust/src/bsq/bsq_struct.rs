//
// EPITECH PROJECT, 2024
// BSQ_Learn
// File description:
// bsq_struct
//

use crate::bsq::parse::Parse;
use std::fs;

pub struct BSQ {
    pub height: u32,
    pub width: u32,
    pub map: Vec<String>,
    pub x: u32,
    pub y: u32,
    pub size: u32,
}

impl Parse for BSQ {
    fn load(&mut self, path: String) {
        let content = fs::read_to_string(path).expect("Issue when opening map");
        let mut lines: Vec<String> = content.lines().map(String::from).collect();

        self.height = lines[0].trim().parse().expect("Issue to get the height");
        self.width = lines[1].trim().len() as u32;
        lines.remove(0);
        self.map = lines;
    }

    fn find_bsq(&mut self, x: u32, y: u32) {
        let mut size_square = self.size + 1;

        loop {
            if x + size_square > self.width || y + size_square > self.height {
                return;
            }
            for height in 0..size_square {
                for width in 0..size_square {
                    if self.get_sell(x + width, y + height) != '.' {
                        return;
                    }
                }
            }
            self.x = x;
            self.y = y;
            self.size = size_square;
            size_square += 1;
        }
    }

    fn parse_bsq(&mut self) {
        for height in 0..self.height {
            for width in 0..self.width {
                if self.get_sell(width, height) == '.' {
                    self.find_bsq(width, height);
                }
            }
        }
    }

    fn get_sell(&self, x: u32, y: u32) -> char {
        self.map[x as usize].chars().nth(y as usize).unwrap()
    }

    fn replace_bsq(&mut self) {
        for height in self.x..(self.x + self.size) {
            for width in self.y..(self.y + self.size) {
                let x_usize = width as usize;
                self.map[height as usize].replace_range(x_usize..(x_usize + 1), "x");
            }
        }
    }
}
