package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var isNotPrime [10001]bool
	for i := 2; i < 10001; i++ {
		if !isNotPrime[i] {
			for j := i * 2; j < 10001; j += i {
				isNotPrime[j] = true
			}
		}
	}

	var t int
	fmt.Fscan(reader, &t)

	var n int
	for i := 0; i < t; i++ {
		fmt.Fscan(reader, &n)

		var x, y int
		for j := 2; j <= n/2; j++ {
			if !isNotPrime[j] && !isNotPrime[n-j] {
				x = j
				y = n - j
			}
		}
		fmt.Fprint(writer, x, " ", y, "\n")
	}
}
