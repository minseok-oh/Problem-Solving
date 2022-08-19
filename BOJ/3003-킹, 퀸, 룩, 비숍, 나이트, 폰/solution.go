package main

import "fmt"

var list [6]int
var chess = [6]int{1, 1, 2, 2, 2, 8}

func input() {
	for i := 0; i < 6; i++ {
		fmt.Scan(&list[i])
	}
}

func solve() {
	for i := 0; i < 6; i++ {
		fmt.Printf("%d ", chess[i]-list[i])
	}
}

func main() {
	input()
	solve()
}
