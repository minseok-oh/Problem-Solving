package main

import (
	"bufio"
	"fmt"
	"os"
)

type receipt struct {
	cost  int
	count int
}

var x, n int
var list []receipt
var reader = bufio.NewReader(os.Stdin)

func input() {
	fmt.Fscan(reader, &x, &n)

	var u, v int
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &u, &v)
		list = append(list, receipt{u, v})
	}
}

func solve() {
	sum := 0
	for i := 0; i < n; i++ {
		sum += (list[i].cost * list[i].count)
	}

	if sum == x {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

func main() {
	input()
	solve()
}
