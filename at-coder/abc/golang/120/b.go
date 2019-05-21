package main

import (
	"fmt"
	"math"
)

func b() {
	var a, b, k int
	fmt.Scan(&a, &b, &k)

	min := int(math.Min(float64(a), float64(b)))
	var numbers = []int{}
	for i := min; i >= 1; i-- {
		if a%i == 0 && b%i == 0 {
			numbers = append(numbers, i)
		}
	}

	fmt.Println(numbers[k-1])
}
