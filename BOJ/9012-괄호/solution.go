package main

import (
	"bufio"
	"fmt"
	"os"
)

var n int
var problem []string
var reader = bufio.NewReader(os.Stdin)
var writer = bufio.NewWriter(os.Stdout)

func input() {
	fmt.Fscan(reader, &n)
	var pro string
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &pro)
		problem = append(problem, pro)
	}
}

func solve() {
	for i := 0; i < n; i++ {
		var stackArray []int

		for j := 0; j < len(problem[i]); j++ {
			if problem[i][j] == '(' {
				stackArray = append(stackArray, 1)
			} else if problem[i][j] == ')' {
				if len(stackArray) == 0 || stackArray[len(stackArray)-1] != 1 {
					stackArray = append(stackArray, -1)
				} else {
					stackArray = stackArray[:len(stackArray)-1]
				}
			}
		}

		if len(stackArray) == 0 {
			fmt.Fprintln(writer, "YES")
		} else {
			fmt.Fprintln(writer, "NO")
		}
	}
}

func main() {
	defer writer.Flush()
	input()
	solve()
}
