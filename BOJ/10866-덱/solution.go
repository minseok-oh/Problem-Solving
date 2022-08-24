package main

import (
	"bufio"
	"container/list"
	"fmt"
	"os"
)

type Deque struct {
	v    *list.List
	size int
}

func (dq *Deque) PushFront(x any) {
	dq.v.PushFront(x)
	dq.size++
}

func (dq *Deque) PushBack(x any) {
	dq.v.PushBack(x)
	dq.size++
}

func (dq *Deque) PopFront() any {
	if dq.size == 0 {
		return -1
	} else {
		front := dq.v.Front()
		dq.v.Remove(front)
		dq.size--
		return front.Value
	}
}

func (dq *Deque) PopBack() any {
	if dq.size == 0 {
		return -1
	} else {
		back := dq.v.Back()
		dq.v.Remove(back)
		dq.size--
		return back.Value
	}
}

func (dq *Deque) Size() int {
	return dq.size
}

func (dq *Deque) Empty() int {
	if dq.size == 0 {
		return 1
	} else {
		return 0
	}
}

func (dq *Deque) Front() any {
	if dq.size == 0 {
		return -1
	} else {
		return dq.v.Front().Value
	}
}

func (dq *Deque) Back() any {
	if dq.size == 0 {
		return -1
	} else {
		return dq.v.Back().Value
	}
}

func NewDeque() *Deque {
	return &Deque{list.New(), 0}
}

var reader = bufio.NewReader(os.Stdin)
var writer = bufio.NewWriter(os.Stdout)

func solve() {
	var n int
	fmt.Fscan(reader, &n)

	var op string
	dq := NewDeque()
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &op)

		if op == "push_front" {
			var x int
			fmt.Fscan(reader, &x)
			dq.PushFront(x)
		} else if op == "push_back" {
			var x int
			fmt.Fscan(reader, &x)
			dq.PushBack(x)
		} else if op == "pop_front" {
			fmt.Fprintln(writer, dq.PopFront())
		} else if op == "pop_back" {
			fmt.Fprintln(writer, dq.PopBack())
		} else if op == "size" {
			fmt.Fprintln(writer, dq.Size())
		} else if op == "empty" {
			fmt.Fprintln(writer, dq.Empty())
		} else if op == "front" {
			fmt.Fprintln(writer, dq.Front())
		} else if op == "back" {
			fmt.Fprintln(writer, dq.Back())
		}
	}
}

func main() {
	defer writer.Flush()
	solve()
}
