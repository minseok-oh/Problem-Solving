package main

import (
	"bufio"
	"fmt"
	"os"
)

var reader = bufio.NewReader(os.Stdin)
var writer = bufio.NewWriter(os.Stdout)

func solve() {
	var n int
	var fibo [41]int
	fmt.Fscan(reader, &n)

	fibo[3] = 2
	fibo[4] = 3
	for i := 5; i <= n; i++ {
		fibo[i] = fibo[i-1] + fibo[i-2]
	}
	fmt.Fprintf(writer, "%d %d\n", fibo[n], n-2)
}

func main() {
	defer writer.Flush()
	solve()
}
