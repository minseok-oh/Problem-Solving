package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var n, m, r int
var graph [][]int
var visited []int
var reader = bufio.NewReader(os.Stdin)
var writer = bufio.NewWriter(os.Stdout)

func input() {
	fmt.Fscan(reader, &n, &m, &r)
	graph = make([][]int, n+1)
	visited = make([]int, n+1)

	var u, v int
	for i := 0; i < m; i++ {
		fmt.Fscan(reader, &u, &v)
		graph[u] = append(graph[u], v)
		graph[v] = append(graph[v], u)
	}
	for i := 1; i <= n; i++ {
		sort.Ints(graph[i])
	}
}

func bfs(start int) {
	var queue []int
	count := 1
	queue = append(queue, start)

	for len(queue) != 0 {
		here := queue[0]
		queue = queue[1:]
		if visited[here] != 0 {
			continue
		}

		visited[here] = count
		count++

		for _, val := range graph[here] {
			if visited[val] == 0 {
				queue = append(queue, val)
			}
		}
	}
}

func solve() {
	bfs(r)
	for i := 1; i <= n; i++ {
		fmt.Fprintln(writer, visited[i])
	}
}

func main() {
	defer writer.Flush()
	input()
	solve()
}
