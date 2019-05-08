package main

import (
	"fmt"
)

func a() {
	var b string
	fmt.Scan(&b)

	switch b {
	case "A":
		fmt.Println("T")
	case "T":
		fmt.Println("A")
	case "C":
		fmt.Println("G")
	case "G":
		fmt.Println("C")
	default:
	}
}
