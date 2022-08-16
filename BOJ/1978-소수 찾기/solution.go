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

	var n int
	fmt.Fscan(reader, &n)

	var isNotPrime [1001]bool
	isNotPrime[0] = true
	isNotPrime[1] = true
	for i := 2; i < 1001; i++ {
		if !isNotPrime[i] {
			for j := i * 2; j < 1001; j += i {
				isNotPrime[j] = true
			}
		}
	}

	var num int
	res := 0
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &num)
		if !isNotPrime[num] {
			res++
		}
	}
	fmt.Fprint(writer, res)
}
