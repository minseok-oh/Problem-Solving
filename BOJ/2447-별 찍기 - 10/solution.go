package main

import (
	"bufio"
	"fmt"
	"os"
)

var board [6600][6600]bool

func recur(n int, y int, x int) {
	if n == 0 {
		board[y][x] = true
		return
	}

	size := n / 3
	recur(size, y, x)
	recur(size, y, x+size)
	recur(size, y, x+2*size)
	recur(size, y+size, x)
	recur(size, y+size, x+2*size)
	recur(size, y+2*size, x)
	recur(size, y+2*size, x+size)
	recur(size, y+2*size, x+2*size)
}

func main() {
	var n int
	fmt.Scanf("%d", &n)
	recur(n, 0, 0)

	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if board[i][j] {
				fmt.Fprint(writer, "*")
			} else {
				fmt.Fprint(writer, " ")
			}
		}
		fmt.Fprintln(writer, "")
	}
}
