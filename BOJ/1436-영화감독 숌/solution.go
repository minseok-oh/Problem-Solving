package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

var n int
var reader = bufio.NewReader(os.Stdin)

func solve() {
	fmt.Fscan(reader, &n)
	var num string

	for i := 666; ; i++ {
		num = fmt.Sprint(i)
		if strings.Contains(num, "666") {
			n--
		}

		if n == 0 {
			break
		}
	}

	fmt.Println(num)
}

func main() {
	solve()
}
