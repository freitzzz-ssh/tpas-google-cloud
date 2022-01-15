package main

import (
    "fmt"
    "os/exec"
)

func main() {
    app := "nc"

    arg0 := "-nv"
    arg1 := "34.76.10.0"
    arg2 := "4444"

    cmd := exec.Command(app, arg0, arg1, arg2)
    stdout, err := cmd.Output()

    if err != nil {
        fmt.Println(err.Error())
        return
    }

    // Print the output
    fmt.Println(string(stdout))
}
