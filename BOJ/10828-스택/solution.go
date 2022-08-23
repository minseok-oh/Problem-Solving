package main

import (
	"bufio"
	"fmt"
	"os"
)

var stackArray []any
var reader = bufio.NewReader(os.Stdin)
var writer = bufio.NewWriter(os.Stdout)

func push(x any) {
	stackArray = append(stackArray, x)
}

func pop() any {
	if len(stackArray) == 0 {
		return -1
	} else {
		res := stackArray[len(stackArray)-1]
		stackArray = stackArray[:len(stackArray)-1]
		return res
	}
}

func size() int {
	return len(stackArray)
}

func empty() int {
	if len(stackArray) == 0 {
		return 1
	} else {
		return 0
	}
}

func top() any {
	if len(stackArray) == 0 {
		return -1
	} else {
		return stackArray[len(stackArray)-1]
	}
}

func solve() {
	var n int
	fmt.Fscan(reader, &n)
	for i := 0; i < n; i++ {
		var op string
		fmt.Fscan(reader, &op)

		if op == "push" {
			var value int
			fmt.Fscan(reader, &value)
			push(value)
		} else if op == "pop" {
			fmt.Fprintln(writer, pop())
		} else if op == "size" {
			fmt.Fprintln(writer, size())
		} else if op == "empty" {
			fmt.Fprintln(writer, empty())
		} else if op == "top" {
			fmt.Fprintln(writer, top())
		}
	}
}

func main() {
	defer writer.Flush()
	solve()
}
