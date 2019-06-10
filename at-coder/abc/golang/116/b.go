package main

import (
	"fmt"
)

func b() {
	// scan starts
	var s int
	fmt.Scan(&s)

	nums := []int{s}
	answer := -1
	for i := 1; true; i++ {
		// current num
		prev := nums[i-1]
		a := prev / 2
		if prev%2 != 0 {
			a = prev*3 + 1
		}

		// find answer
		for _, num := range nums {
			if num == a {
				// answer found
				answer = i + 1
				break
			}
		}

		if answer != -1 {
			break
		} else {
			nums = append(nums, a)
		}
	}

	fmt.Println(answer)
}
