package main

import (
	"bufio"
	"fmt"
	"os"
)

func fibo(n int) int {
	if n == 0 || n == 1 {
		return 1
	} else {
		return n * fibo(n-1)
	}
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n int
	fmt.Fscan(reader, &n)
	fmt.Fprintln(writer, fibo(n))
}
