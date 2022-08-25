package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var n, m int
var list []int
var reader = bufio.NewReader(os.Stdin)
var writer = bufio.NewWriter(os.Stdout)

func input() {
	fmt.Fscan(reader, &n)
	var temp int
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &temp)
		list = append(list, temp)
	}
	fmt.Fscan(reader, &m)
}

func binarySearch(left int, right int, value int) int {
	for left <= right {
		mid := (left + right) / 2

		if list[mid] > value {
			right = mid - 1
		} else if list[mid] < value {
			left = mid + 1
		} else {
			return mid
		}
	}
	return -1
}

func solve() {
	var temp int
	sort.Ints(list)

	for i := 0; i < m; i++ {
		fmt.Fscan(reader, &temp)
		check := binarySearch(0, n-1, temp)

		if check == -1 {
			fmt.Fprintln(writer, 0)
		} else {
			fmt.Fprintln(writer, 1)
		}
	}
}

func main() {
	defer writer.Flush()
	input()
	solve()
}
