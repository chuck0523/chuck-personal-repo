package main

import (
	"fmt"
	"strings"
)

func b() {
	var s string
	fmt.Scan(&s)

	chars := strings.Split(s, "")

	var longest = ""
	var substring string
	for _, char := range chars {
		if strings.Contains("ATGC", char) {
			// pile chars up
			substring += char
		} else if len(substring) > len(longest) {
			longest = substring
			substring = ""
		} else {
			substring = ""
		}
	}

	if len(substring) > len(longest) {
		longest = substring
	}

	fmt.Println(len(longest))
}
