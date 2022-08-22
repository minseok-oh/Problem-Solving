package main

import (
	"bufio"
	"fmt"
	"os"
)

var a, b, c int
var memo [102][102][102]int
var reader = bufio.NewReader(os.Stdin)
var writer = bufio.NewWriter(os.Stdout)

func w(a int, b int, c int) int {
	x := a + 50
	y := b + 50
	z := c + 50

	ret := memo[x][y][z]
	if ret != 0 {
		return ret
	}

	if a <= 0 || b <= 0 || c <= 0 {
		memo[x][y][z] = 1
	} else if a > 20 || b > 20 || c > 20 {
		memo[x][y][z] = w(20, 20, 20)
	} else if a < b && b < c {
		memo[x][y][z] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c)
	} else {
		memo[x][y][z] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1)
	}
	return memo[x][y][z]
}

func solve() {
	fmt.Fscan(reader, &a, &b, &c)
	for a != -1 || b != -1 || c != -1 {
		fmt.Fprintf(writer, "w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c))
		fmt.Fscan(reader, &a, &b, &c)
	}
}

func main() {
	defer writer.Flush()
	solve()
}
