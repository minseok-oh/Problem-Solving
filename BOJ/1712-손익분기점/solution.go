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

	var A, B, C int
	fmt.Fscan(reader, &A, &B, &C)

	if B >= C {
		fmt.Fprint(writer, -1)
	} else {
		res := A/(C-B) + 1
		fmt.Fprint(writer, res)
	}
}
