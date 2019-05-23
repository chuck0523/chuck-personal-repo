package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func b() {
	reader := bufio.NewReader(os.Stdin)

	var N int
	fmt.Scan(&N)

	sum := 0.0
	for i := 0; i < N; i++ {
		str, _ := reader.ReadString('\n')
		str = strings.TrimSuffix(str, "\n")
		chars := strings.Split(str, " ")

		amount, _ := strconv.ParseFloat(chars[0], 32)
		currency := chars[1]

		if currency == "JPY" {
			sum += amount
		} else {
			sum += amount * 380000
		}

	}

	fmt.Println(sum)
}
