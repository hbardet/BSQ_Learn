//
// EPITECH PROJECT, 2024
// BSQ_Learn
// File description:
// main
//

mod parsing;
mod display_map;
use parsing::parsing_map::load_map;
use display_map::display_map;

fn main() {
    let map = load_map();
    
}
