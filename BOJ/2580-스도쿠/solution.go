package main

import (
	"bufio"
	"fmt"
	"os"
)

type point struct {
	y, x int
}

var board [9][9]int
var flag bool
var list []point
var reader = bufio.NewReader(os.Stdin)
var writer = bufio.NewWriter(os.Stdout)

func input() {
	for i := 0; i < 9; i++ {
		for j := 0; j < 9; j++ {
			fmt.Fscan(reader, &board[i][j])
			if board[i][j] == 0 {
				list = append(list, point{i, j})
			}
		}
	}
}

func check_board(y int, x int, value int) bool {
	ret := true
	for i := 0; i < 9; i++ {
		if board[y][i] == value {
			ret = false
		}
		if board[i][x] == value {
			ret = false
		}
	}

	for i := 0; i < 3; i++ {
		for j := 0; j < 3; j++ {
			if board[(y/3)*3+i][(x/3)*3+j] == value {
				ret = false
			}
		}
	}
	return ret
}

func solve(here int) {
	if flag {
		return
	}

	if here == len(list) {
		flag = true

		for i := 0; i < 9; i++ {
			for j := 0; j < 9; j++ {
				fmt.Fprintf(writer, "%d ", board[i][j])
			}
			fmt.Fprintf(writer, "\n")
		}
	} else {
		y := list[here].y
		x := list[here].x
		for i := 1; i < 10; i++ {
			if check_board(y, x, i) {
				board[y][x] = i
				solve(here + 1)
				board[y][x] = 0
			}
		}
	}
}

func main() {
	defer writer.Flush()
	input()
	solve(0)
}
