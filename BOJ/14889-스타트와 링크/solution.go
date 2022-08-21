package main

import (
	"bufio"
	"fmt"
	"os"
)

var n int
var board = [][]int{}
var reader = bufio.NewReader(os.Stdin)
var writer = bufio.NewWriter(os.Stdout)

func input() {
	fmt.Fscan(reader, &n)
	for i := 0; i < n; i++ {
		var temp int
		var list = []int{}
		for j := 0; j < n; j++ {
			fmt.Fscan(reader, &temp)
			list = append(list, temp)
		}
		board = append(board, list)
	}
}

var start_list []int
var visited [21]bool

func sum_team(list []int) int {
	ret := 0
	for i := 0; i < len(list); i++ {
		for j := i + 1; j < len(list); j++ {
			ret += board[list[i]][list[j]] + board[list[j]][list[i]]
		}
	}
	return ret
}

func back_tracking(here int) int {
	ret := 987654321

	if len(start_list) == n/2 {
		var link_list []int
		for i := 0; i < n; i++ {
			if !visited[i] {
				link_list = append(link_list, i)
			}
		}

		ret = sum_team(start_list) - sum_team(link_list)
		if ret < 0 {
			ret = ret * -1
		}
	} else {
		for i := here + 1; i < n; i++ {
			start_list = append(start_list, i)
			visited[i] = true
			temp := back_tracking(i)
			start_list = start_list[:len(start_list)-1]
			visited[i] = false

			if ret > temp {
				ret = temp
			}
		}
	}

	return ret
}

func main() {
	defer writer.Flush()
	input()
	fmt.Fprintln(writer, back_tracking(-1))
}
