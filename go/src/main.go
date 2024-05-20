package main

import (
    "os"
)

func main(){
    argsWithoutProg := os.Args[1:]
    var new_bsq bsq
    new_bsq.open_file(argsWithoutProg[0])
    new_bsq.parse_map()
    new_bsq.replace_bsq()
    new_bsq.display_map()
}
