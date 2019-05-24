package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	var N, M int
	fmt.Scan(&N, &M)

	votes := make([]int, M)

	for i := 0; i < N; i++ {
		row, _ := reader.ReadString('\n')
		// ex. "1 4 2 9"
		row = strings.TrimSuffix(row, "\n")
		// ex. {"1" "4" "2" "9"}
		splitted := strings.Split(row, " ")

		for i, char := range splitted {
			if i == 0 {
				continue
			}
			num, _ := strconv.Atoi(char)
			votes[num-1]++
		}
	}

	answer := 0
	for i := 0; i < M; i++ {
		if votes[i] == N {
			answer++
		}
	}

	fmt.Println(answer)
}
