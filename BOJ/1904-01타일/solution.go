package main

import (
	"bufio"
	"fmt"
	"os"
)

var n int
var memo [1000001]int

const mod = 15746

var reader = bufio.NewReader(os.Stdin)
var writer = bufio.NewWriter(os.Stdout)

func make_tile(count int) int {
	ret := memo[count]
	if ret != 0 {
		return memo[count]
	}

	memo[count] = (((make_tile(count-1) % mod) + (make_tile(count-2) % mod)) % mod)
	return memo[count]
}

func solve() {
	fmt.Fscan(reader, &n)

	memo[1] = 1
	memo[2] = 2
	fmt.Fprintln(writer, (make_tile(n) % mod))
}

func main() {
	defer writer.Flush()
	solve()
}
