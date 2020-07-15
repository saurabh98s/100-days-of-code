package main

import "fmt"

func uRLify(input string) string {
	count := 0
	spaces := 0
	for _, character := range input {
		count++
		if character == rune(' ') {
			spaces++
		}
	}
	temp := make([]rune, count+(spaces*2))
	i := 0
	for _, character := range input {
		if character == rune(' ') {
			temp[i] = rune('%')
			temp[i+1] = rune('2')
			temp[i+2] = rune('0')
			i += 3
		} else {
			temp[i] = character
			i++
		}

	}
	return string(temp)
}

func main() {
	fmt.Print(uRLify("HI I"))
}
