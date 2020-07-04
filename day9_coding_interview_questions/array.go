package main

import "fmt"

//isItUnique uses maps to find the result
func isItUnique(input string) bool {
	seen := make(map[rune]bool)
	for _, r := range input {
		_, ok := seen[r]
		if ok {
			return false
		}
		seen[r] = true
	}
	return true
}

// isUnique uses no additional data structures
func isUnique(input string) bool {
	if len(input) > 128 {
		return false
	}
	boolArray := [128]bool{}
	for _, r := range input {
		ok := int(r)
		if boolArray[ok] {
			return false

		}
		boolArray[ok] = true
	}
	return true
}

func main() {
	boolArray := [128]bool{}
	/*
	checking if an initialized bool array has all values true or false
	Here it is all false
	*/
	for _, r := range boolArray {
		if r!=true {
			print(r)
		}

	}

	fmt.Println(isItUnique("Hello"))
	fmt.Println(isItUnique("Hello"))
	fmt.Println(isItUnique("Helo"))
	fmt.Println(isItUnique("oo"))
	fmt.Println("Is unique")
	fmt.Println(isUnique("Hello"))
	fmt.Println(isUnique("Hello"))
	fmt.Println(isUnique("Helo"))
	fmt.Println(isUnique("oo"))
}
