package main

import "fmt"

func d(n int) int {
	res := n
	for n != 0 {
		res += (n % 10)
		n /= 10
	}
	return res
}

func main() {
	var res [10001]bool
	for i := 1; i < 10001; i++ {
		temp := d(i)
		if temp < 10001 {
			res[temp] = true
		}
	}

	for i := 1; i < 10001; i++ {
		if !res[i] {
			fmt.Println(i)
		}
	}
}
