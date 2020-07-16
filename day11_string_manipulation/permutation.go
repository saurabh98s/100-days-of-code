package main

import "fmt"

func permutationPalindrome(str string) bool {
	charMap := make(map[rune]int)
	for _, char := range str {
		if char != rune(' ') {
			charMap[char]++
		}
	}
	oddCount := 0
	isPermutation := true

	for _, value := range charMap {
		if value%2 == 1 {
			oddCount++
		}
		if oddCount > 1 {
			isPermutation = false
			break
		}
	}
	return isPermutation

}

func main() {
	fmt.Println(permutationPalindrome("Taaut"))
	fmt.Println(permutationPalindrome("Tact Coa"))
}
