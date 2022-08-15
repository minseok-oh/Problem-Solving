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
	var arr string
	fmt.Fscan(reader, &n, &arr)

	sum := 0
	for i := 0; i < len(arr); i++ {
		sum += int(arr[i]) - int('0')
	}
	fmt.Fprint(writer, sum)
}
