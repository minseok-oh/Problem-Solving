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

	res := 1
	count := 1
	for res < n {
		res += (6 * count)
		count++
	}
	fmt.Fprint(writer, count)
}
