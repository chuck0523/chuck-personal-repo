package main

import (
	"fmt"
	"sort"
)

func main() {
	// scan starts
	var N int
	fmt.Scan(&N)

	nums := make([]int, N)
	for i := 0; i < N; i++ {
		var num int
		fmt.Scan(&num)
		nums[i] = num
	}
	// scan ends

	// find biggest by sorting
	sort.Ints(nums)
	others, biggest := nums[:N-1], nums[N-1]

	// sum up others
	othersSum := 0
	for _, num := range others {
		othersSum += num
	}

	// result
	if biggest < othersSum {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
