package main

import (
    "os"
    "net/http"
    _ "net/http/pprof"
    "log"
)

func main(){
    go func() {
        log.Println(http.ListenAndServe("localhost:6060", nil))
    }()
    argsWithoutProg := os.Args[1:]
    var new_bsq bsq
    new_bsq.open_file(argsWithoutProg[0])
    new_bsq.parse_map()
    new_bsq.replace_bsq()
    new_bsq.display_map()
}
