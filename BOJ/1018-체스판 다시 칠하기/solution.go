package main

import (
	"bufio"
	"fmt"
	"os"
)

var n, m int
var board []string
var reader = bufio.NewReader(os.Stdin)

var b_board = [8]string{
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
}

var w_board = [8]string{
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
}

func input() {
	fmt.Fscan(reader, &n, &m)

	var line string
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &line)
		board = append(board, line)
	}
}

func checkBoard(y int, x int) int {
	b_ret := 0
	w_ret := 0
	for i := 0; i < 8; i++ {
		for j := 0; j < 8; j++ {
			if board[y+i][x+j] != b_board[i][j] {
				b_ret++
			}
			if board[y+i][x+j] != w_board[i][j] {
				w_ret++
			}
		}
	}

	if b_ret > w_ret {
		return w_ret
	} else {
		return b_ret
	}
}

func solve() {
	res := 64
	for i := 0; i <= n-8; i++ {
		for j := 0; j <= m-8; j++ {
			temp := checkBoard(i, j)
			if res > temp {
				res = temp
			}
		}
	}
	fmt.Println(res)
}

func main() {
	input()
	solve()
}
