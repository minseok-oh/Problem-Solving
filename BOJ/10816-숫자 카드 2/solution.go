package main

import (
	"bufio"
	"fmt"
	"os"
)

var n, m int
var cards = map[int]int{}
var reader = bufio.NewReader(os.Stdin)
var writer = bufio.NewWriter(os.Stdout)

func input() {
	fmt.Fscan(reader, &n)
	var key int
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &key)

		value, exist := cards[key]
		if !exist {
			cards[key] = 1
		} else {
			cards[key] = value + 1
		}
	}
	fmt.Fscan(reader, &m)
}

func solve() {
	var target int
	for i := 0; i < m; i++ {
		fmt.Fscan(reader, &target)
		value, exist := cards[target]

		if !exist {
			fmt.Fprint(writer, 0)
		} else {
			fmt.Fprint(writer, value)
		}
		fmt.Fprint(writer, " ")
	}
}

func main() {
	defer writer.Flush()
	input()
	solve()
}
