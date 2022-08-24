package main

import (
	"bufio"
	"fmt"
	"os"
)

var n int
var reader = bufio.NewReader(os.Stdin)
var writer = bufio.NewWriter(os.Stdout)

func solve() {
	fmt.Fscan(reader, &n)

	var queue []int
	for i := 1; i <= n; i++ {
		queue = append(queue, i)
	}

	for {
		if len(queue) == 1 {
			break
		}

		val := queue[1]
		queue = queue[2:]
		queue = append(queue, val)
	}
	fmt.Fprintln(writer, queue[0])
}

func main() {
	defer writer.Flush()
	solve()
}
