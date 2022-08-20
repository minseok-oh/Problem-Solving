package main

import (
	"bufio"
	"fmt"
	"os"
)

var n, m int
var cards = map[int]bool{}
var reader = bufio.NewReader(os.Stdin)
var writer = bufio.NewWriter(os.Stdout)

func input() {
	fmt.Fscan(reader, &n)
	var key int
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &key)
		cards[key] = true
	}
	fmt.Fscan(reader, &m)
}

func solve() {
	var target int
	for i := 0; i < m; i++ {
		fmt.Fscan(reader, &target)
		value, exists := cards[target]
		_ = value

		if !exists {
			fmt.Fprint(writer, "0 ")
		} else {
			fmt.Fprint(writer, "1 ")
		}
	}
}

func main() {
	defer writer.Flush()
	input()
	solve()
}
