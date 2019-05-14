package main

import (
	"fmt"
)

func a() {
	var H, W int
	var h, w int
	fmt.Scan(&H, &W)
	fmt.Scan(&h, &w)

	remain := H * W

	remain -= h * W
	remain -= w * (H - h)

	fmt.Println(remain)
}
