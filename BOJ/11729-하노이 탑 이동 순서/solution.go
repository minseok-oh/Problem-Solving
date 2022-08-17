package main

import (
	"bufio"
	"fmt"
	"os"
)

type position struct {
	start int
	end   int
}

var writer = bufio.NewWriter(os.Stdout)
var res []position

func hannoi(start int, mid int, end int, idx int) {
	if idx == 1 {
		res = append(res, position{start, end})
		return
	}

	hannoi(start, end, mid, idx-1)
	hannoi(start, mid, end, 1)
	hannoi(mid, start, end, idx-1)
}

func main() {
	var n int
	fmt.Scanf("%d", &n)
	defer writer.Flush()
	hannoi(1, 2, 3, n)

	fmt.Fprintln(writer, len(res))
	for i := 0; i < len(res); i++ {
		fmt.Fprintln(writer, res[i].start, res[i].end)
	}
}
