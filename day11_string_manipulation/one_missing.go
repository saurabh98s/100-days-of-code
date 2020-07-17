package main

import (
	"fmt"
)

func checkOneMissing(input1 string, input2 string) bool {
	charMap := make(map[rune]int)
	char := 0

	for _, val := range input1 {
		charMap[val]++
		fmt.Println("inside input 1",charMap[val])
	}
	for _, val := range input2 {
		charMap[val]--
		fmt.Println("inside input 2",charMap[val])
	}
	for _, val := range charMap {
		if val < 0 || val > 0 {
			char++
			
		}
	}
	fmt.Println(char)
	if char > 1 {
		return false
	}

	return true
}

func main() {
	fmt.Println(checkOneMissing("panic", "panixl"))
	fmt.Println(checkOneMissing("panic", "pan"))

}
