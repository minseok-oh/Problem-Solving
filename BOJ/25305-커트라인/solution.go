package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var n, k int
var students []int
var reader = bufio.NewReader(os.Stdin)
var writer = bufio.NewWriter(os.Stdout)

func input() {
	fmt.Fscan(reader, &n, &k)

	var s int
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &s)
		students = append(students, s)
	}
}

func solve() {
	sort.Ints(students)
	fmt.Fprintln(writer, students[n-k])
}

func main() {
	defer writer.Flush()
	input()
	solve()
}
