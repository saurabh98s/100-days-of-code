package main

import "fmt"

func isUnique(string) bool {
	var str string
	if len(str) > 128 {
		return false
	}
	boolArray := [128]bool{}

	for i := range str {
		value := str[i]
		fmt.Println(string(value))
		if value==1 {
			return false
		}
		boolArray[value] = true

	}
	return true
}

func main() {
	fmt.Println(isUnique("Helo"))
	fmt.Println(isUnique("oo"))
}
