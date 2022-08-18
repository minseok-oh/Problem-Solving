package main

import (
	"bufio"
	"fmt"
	"os"
)

var reader = bufio.NewReader(os.Stdin)

type person struct {
	weight int
	height int
}

var n int
var list []person

func input() {
	fmt.Fscan(reader, &n)

	var x, y int
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &x, &y)
		list = append(list, person{x, y})
	}
}

func isBigger(a person, b person) int {
	if a.weight < b.weight && a.height < b.height {
		return 1
	} else if a.weight > b.weight && a.height > b.height {
		return -1
	} else {
		return 0
	}
}

func solve() {
	var res [51]int
	for i := 0; i < n; i++ {
		res[i] = 1
	}

	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			check := isBigger(list[i], list[j])
			if check == 1 {
				res[i] = res[i] + 1
			} else if check == -1 {
				res[j] = res[j] + 1
			}
		}
	}

	for i := 0; i < n; i++ {
		fmt.Printf("%d ", res[i])
	}
}

func main() {
	input()
	solve()
}
