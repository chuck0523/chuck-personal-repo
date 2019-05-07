package main

import (
	"fmt"
)

func a() {
	var a, b, c, d, e, k int
	fmt.Scan(&a)
	fmt.Scan(&b)
	fmt.Scan(&c)
	fmt.Scan(&d)
	fmt.Scan(&e)
	fmt.Scan(&k)

	if e-a <= k {
		fmt.Println("Yay!")
	} else {
		fmt.Println(":(")
	}
}
