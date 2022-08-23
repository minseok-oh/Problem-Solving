package main

import (
	"bufio"
	"fmt"
	"os"
)

var n int
var list []int
var reader = bufio.NewReader(os.Stdin)
var writer = bufio.NewWriter(os.Stdout)

func input() {
	fmt.Fscan(reader, &n)
	var value int
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &value)
		list = append(list, value)
	}
}

func solve() {
	var stackArray []int
	for i := 0; i < n; i++ {
		if list[i] != 0 {
			stackArray = append(stackArray, list[i])
		} else {
			if len(stackArray) != 0 {
				stackArray = stackArray[:len(stackArray)-1]
			}
		}
	}

	res := 0
	for i := 0; i < len(stackArray); i++ {
		res += stackArray[i]
	}
	fmt.Fprintln(writer, res)
}

func main() {
	defer writer.Flush()
	input()
	solve()
}
