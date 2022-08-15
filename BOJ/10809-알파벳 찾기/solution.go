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

	var S string
	fmt.Fscan(reader, &S)

	var count [26]int
	for i := 0; i < 26; i++ {
		count[i] = -1
	}

	for i := 0; i < len(S); i++ {
		if count[int(S[i]-'a')] == -1 {
			count[int(S[i]-'a')] = i
		}
	}

	for i := 0; i < 26; i++ {
		fmt.Fprintf(writer, "%d ", count[i])
	}
}
