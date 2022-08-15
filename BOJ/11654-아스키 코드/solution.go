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

	var c string
	fmt.Fscan(reader, &c)
	fmt.Fprint(writer, c[0])
}
