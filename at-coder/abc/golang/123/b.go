package main

import (
	"fmt"
)

func b() {
	var a, b, c, d, e int
	fmt.Scan(&a)
	fmt.Scan(&b)
	fmt.Scan(&c)
	fmt.Scan(&d)
	fmt.Scan(&e)

	dishes := [5]int{a, b, c, d, e}

	// find dish which should be ordered last
	var lastOrder = 0
	var largestGap = 0
	for i := 0; i < len(dishes); i++ {
		gap := 10 - dishes[i]%10
		if gap == 10 {
			continue
		}
		if largestGap < gap {
			largestGap = gap
			lastOrder = i
		}
	}

	// calculate total time to order every dishes
	var totalTime = 0
	for i := 0; i < len(dishes); i++ {
		totalTime += dishes[i]
		gap := 10 - (dishes[i] % 10)

		if i == lastOrder {
			continue
		}
		if gap == 10 {
			continue
		}

		totalTime += gap
	}

	fmt.Println(totalTime)
}
