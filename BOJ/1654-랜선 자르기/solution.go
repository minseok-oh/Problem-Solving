package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var k, n int
var list []int
var reader = bufio.NewReader(os.Stdin)
var writer = bufio.NewWriter(os.Stdout)

func input() {
	fmt.Fscan(reader, &k, &n)

	var lan int
	for i := 0; i < k; i++ {
		fmt.Fscan(reader, &lan)
		list = append(list, lan)
	}
}

func splitLan(length int) int {
	res := 0
	for i := 0; i < k; i++ {
		res += (list[i] / length)
	}
	return res
}

func solve() {
	sort.Ints(list)

	left := 1
	right := list[len(list)-1]
	for left <= right {
		mid := (left + right) / 2
		check := splitLan(mid)

		if check >= n {
			left = mid + 1
		} else {
			right = mid - 1
		}
	}
	fmt.Fprintln(writer, right)
}

func main() {
	defer writer.Flush()
	input()
	solve()
}
