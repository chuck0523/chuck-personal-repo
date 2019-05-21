package main

import (
	"fmt"
	"math"
)

func a() {
	var a, b, c int
	fmt.Scan(&a, &b, &c)

	if a*c <= b {
		fmt.Println(c)
	} else {
		fmt.Println(math.Floor(float64(b / a)))
	}
}
