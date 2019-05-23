package main

import (
	"fmt"
	"strconv"
	"strings"
)

func a() {
	heiseiEndsAt := 20190430

	var s string
	fmt.Scan(&s)

	s = strings.Replace(s, "/", "", 2)

	date, _ := strconv.Atoi(s)
	if heiseiEndsAt < date {
		fmt.Println("TBD")
	} else {
		fmt.Println("Heisei")
	}
}
