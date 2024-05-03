//
// EPITECH PROJECT, 2024
// BSQ_Learn
// File description:
// main
//

mod bsq;
mod display_map;
use crate::bsq::parse::Parse;

use bsq::bsq_struct::*;
use display_map::display_map;
use std::env;

fn main() {
    let mut bsq = BSQ {
        height: 0,
        width: 0,
        map: Vec::new(),
        size: 2,
        x: 3,
        y: 3,
    };
    let path: String = env::args().collect::<Vec<String>>()[1].clone();
    bsq.load(path);
    bsq.parse_bsq();
    bsq.replace_bsq();
    display_map(bsq.map);
}
