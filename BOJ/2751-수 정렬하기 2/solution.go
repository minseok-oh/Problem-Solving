package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var n int
var list []int
var reader = bufio.NewReader(os.Stdin)
var writer = bufio.NewWriter(os.Stdout)

func input() {
	fmt.Fscan(reader, &n)

	var temp int
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &temp)
		list = append(list, temp)
	}
}

func solve() {
	sort.Ints(list)
	for i := 0; i < n; i++ {
		fmt.Fprintln(writer, list[i])
	}
}

func main() {
	input()
	solve()
	defer writer.Flush()
}
