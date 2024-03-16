//
// EPITECH PROJECT, 2024
// BSQ_Learn
// File description:
// parsing_map
//

use std::fs;
use std::env;
use std::process;

fn test_argv()
{
    let argv: Vec<String> = env::args().collect();

    if argv.len() > 2{
        println!("Too many Argument");
        process::exit(1);
    }
    if argv.len() < 2{
        println!("Not enought argument");
        process::exit(1);
    }
}

fn read_map() -> Vec<String>
{
    let argv: Vec<String> = env::args().collect();
    fs::read_to_string(argv[1].as_str())
        .unwrap()
        .lines()
        .map(String::from)
        .collect()
}

pub fn load_map() -> Vec<String>
{
    test_argv();
    let mut map: Vec<String> = read_map();
    map.remove(0);
    map
}