package main

import (
	"bufio"
	"fmt"
	"os"
)

func isHan(num int) bool {
	a := num / 100
	b := (num / 10) % 10
	c := num % 10

	return (a + c) == 2*b
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n int
	fmt.Fscan(reader, &n)

	if n >= 100 {
		res := 99
		for i := 100; i <= n; i++ {
			if isHan(i) {
				res++
			}
		}
		fmt.Fprint(writer, res)
	} else {
		fmt.Fprint(writer, n)
	}
}
