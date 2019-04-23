package main

import (
    "fmt"
)

func a() {
    var a, b, sum int
	fmt.Scan(&a, &b)

	// 1st try
	if a > b {
		sum = a
		a--
	} else {
		sum = b
		b--
	}
	
	// 2nd try
	if a > b {
		sum += a
	} else {
		sum += b
	}

	fmt.Println(sum)
}
