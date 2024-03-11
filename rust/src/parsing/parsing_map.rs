//
// EPITECH PROJECT, 2024
// BSQ_Learn
// File description:
// parsing_map
//

//use std::fs;
use std::env;
use std::process;

fn test_argv()
{
    if env::args().len() > 2{
        println!("Too many Argument");
        process::exit(1);
    }
    if env::args().len() < 2{
        println!("Not enought argument");
        process::exit(1);
    }
}

pub fn parsing_map() -> String
{
    let map = String::from("0");
    test_argv();
    map
}