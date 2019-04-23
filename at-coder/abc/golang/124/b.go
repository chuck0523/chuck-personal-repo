package main

import (
	"fmt"
	"os"
	"bufio"
	"strings"
	"strconv"
)

func main() {
	var n, highest, views int
	var text string
	fmt.Scan(&n)

	reader := bufio.NewReader(os.Stdin)
	text, _ = reader.ReadString('\n')
	text = strings.TrimSuffix(text, "\n")

	numbers := strings.Split(text, " ")
	
	highest, _ = strconv.Atoi(numbers[0])
	views = 1

	for i := 1; i < len(numbers); i++ {
		num, _ := strconv.Atoi(numbers[i])

		if highest <= num {
			highest = num
			views += 1
		}
	}

	fmt.Println(views)
}
