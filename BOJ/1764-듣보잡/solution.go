package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var n, m int
var data = map[string]int{}
var reader = bufio.NewReader(os.Stdin)
var writer = bufio.NewWriter(os.Stdout)

func input() {
	fmt.Fscan(reader, &n, &m)
	var name string

	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &name)
		data[name] = 1
	}
	for i := 0; i < m; i++ {
		fmt.Fscan(reader, &name)

		value, exist := data[name]
		if !exist {
			data[name] = 1
		} else {
			data[name] = value + 1
		}
	}
}

func solve() {
	var res []string
	for key, value := range data {
		if value == 2 {
			res = append(res, key)
		}
	}

	sort.Strings(res)
	fmt.Fprintln(writer, len(res))
	for i := 0; i < len(res); i++ {
		fmt.Fprintln(writer, res[i])
	}
}

func main() {
	defer writer.Flush()
	input()
	solve()
}
