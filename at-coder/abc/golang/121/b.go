package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	count := 0
	var N, M, C int
	fmt.Scan(&N, &M, &C)

	// B1, B2, ... Bn
	reader := bufio.NewReader(os.Stdin)
	numberChars, _ := reader.ReadString('\n')
	numberChars = strings.TrimSuffix(numberChars, "\n")
	numberCharsAry := strings.Split(numberChars, " ")
	var numbers = []int{}
	for _, numChar := range numberCharsAry {
		num, _ := strconv.Atoi(numChar)
		numbers = append(numbers, num)
	}

	// An1, An2, ... Anm
	for i := 0; i < N; i++ {
		codeChars, _ := reader.ReadString('\n')
		codeChars = strings.TrimSuffix(codeChars, "\n")
		codes := strings.Split(codeChars, " ")

		// calculate single line
		sum := 0
		for i, code := range codes {
			code, _ := strconv.Atoi(code)
			sum += code * numbers[i]
		}
		if sum+C > 0 {
			count++
		}
	}

	fmt.Println(count)
}
