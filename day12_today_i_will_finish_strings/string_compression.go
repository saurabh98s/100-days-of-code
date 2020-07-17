package main

import (
	"fmt"
	"strconv"
)

func basicCompress(input string) string {

	var compStr string

	counter := 1

	for i := 1; i < len(input); i++ {
		if input[i-1] == input[i] {
			counter++
		} else {
			compStr = compStr + string(input[i-1]) + strconv.Itoa(counter)
			fmt.Println("inside loop", compStr)
			counter = 1
		}
	}
	compStr = compStr + string(input[len(input)-1]) + strconv.Itoa(counter)
	fmt.Println("outside loop", compStr)
	if len(compStr) > len(input) {
		return input
	}
	return compStr

}

func compressString(input string) string {

	var compareString string

	counter := 1

	for i := 1; i < len(input); i++ {
		if input[i-1] == input[i] {
			counter++
		} else {
		compareString = compareString + string(input[i-1]) + strconv.Itoa(counter)
		fmt.Println("inside loop", compareString)
		counter = 1
	}
	}
	compareString = compareString + string(input[len(input)-1]) + strconv.Itoa(counter)
	fmt.Println("outside loop", compareString)
	if len(compareString) > len(input) {
		return input
	}
	return compareString

}

func main() {

	fmt.Println("returned value", basicCompress("aabcccccaaa"))
	fmt.Println("returned value", compressString("aabcccccaaa"))
}
