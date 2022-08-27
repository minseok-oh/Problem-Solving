package main

import (
	"bufio"
	"container/heap"
	"fmt"
	"os"
)

type IntHeap []int

func (h IntHeap) Len() int           { return len(h) }
func (h IntHeap) Less(i, j int) bool { return h[i] < h[j] }
func (h IntHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *IntHeap) Push(x interface{}) {
	*h = append(*h, x.(int))
}
func (h *IntHeap) Pop() interface{} {
	old := *h
	n := len(old)

	x := old[n-1]
	*h = old[:n-1]
	return x
}

var n int
var list []int
var reader = bufio.NewReader(os.Stdin)
var writer = bufio.NewWriter(os.Stdout)

func input() {
	fmt.Fscan(reader, &n)

	var num int
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &num)
		list = append(list, num)
	}
}

func solve() {
	h := &IntHeap{}
	heap.Init(h)

	for i := 0; i < n; i++ {
		if list[i] == 0 {
			if h.Len() == 0 {
				fmt.Fprintln(writer, 0)
			} else {
				fmt.Fprintln(writer, heap.Pop(h))
			}
		} else {
			heap.Push(h, list[i])
		}
	}
}

func main() {
	defer writer.Flush()
	input()
	solve()
}
