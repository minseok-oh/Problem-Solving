package main

import (
	"bufio"
	"container/list"
	"fmt"
	"os"
)

type Queue struct {
	v    *list.List
	size int
}

func (q *Queue) Push(x any) {
	q.v.PushBack(x)
	q.size++
}

func (q *Queue) Pop() any {
	front := q.v.Front()
	if front == nil {
		return -1
	} else {
		q.v.Remove(front)
		q.size--
		return front.Value
	}
}

func (q *Queue) Size() int {
	return q.size
}

func (q *Queue) Empty() int {
	if q.size == 0 {
		return 1
	} else {
		return 0
	}
}

func (q *Queue) Front() any {
	front := q.v.Front()
	if front == nil {
		return -1
	} else {
		return front.Value
	}
}

func (q *Queue) Back() any {
	back := q.v.Back()
	if q.size == 0 {
		return -1
	} else {
		return back.Value
	}
}

func NewQueue() *Queue {
	return &Queue{list.New(), 0}
}

var n int
var reader = bufio.NewReader(os.Stdin)
var writer = bufio.NewWriter(os.Stdout)

func solve() {
	fmt.Fscan(reader, &n)
	q := NewQueue()

	for i := 0; i < n; i++ {
		var op string
		fmt.Fscan(reader, &op)

		if op == "push" {
			var x int
			fmt.Fscan(reader, &x)
			q.Push(x)
		} else if op == "pop" {
			fmt.Fprintln(writer, q.Pop())
		} else if op == "size" {
			fmt.Fprintln(writer, q.Size())
		} else if op == "empty" {
			fmt.Fprintln(writer, q.Empty())
		} else if op == "front" {
			fmt.Fprintln(writer, q.Front())
		} else if op == "back" {
			fmt.Fprintln(writer, q.Back())
		}
	}
}

func main() {
	defer writer.Flush()
	solve()
}
