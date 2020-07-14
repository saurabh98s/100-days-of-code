// check if two strings are a permutation of the other

package main

import (
	"fmt"
	"sort"
)

type sortBy []rune

func (a sortBy) Len() int           { return len(a) }
func (a sortBy) Swap(i, j int)      { a[i], a[j] = a[j], a[i] }
func (a sortBy) Less(i, j int) bool { return a[i] < a[j] }

func sortString(s string) string {
	r := []rune(s)
	sort.Sort(sortBy(r))
	return string(r)
}

func checkPermutation2(a string, b string) bool {
	if len(a) != len(b) {
		return false
	}
	a=sortString(a)
	b=sortString(b)
	aRune:=[]rune(a)
	bRune:=[]rune(b)
	for i:=0;i<len(a);i++ {
		if aRune[i] != bRune[i] {
			return false
		}	
	}
	return true
}

func checkPermutation(a string, b string) bool {
	if len(a) != len(b) {
		return false
	}
	counts := make(map[rune]int)
	for _, character := range a {
		counts[character]++
	}
	for _, character := range b {
		counts[character]--
	}

	for _, val := range counts {
		if val != 0 {
			return false
		}
	}
	return true
}

func main() {
	a := "pasta"
	b := "astap"

	fmt.Println(checkPermutation(a, b))
	fmt.Println(checkPermutation2(a, b))
}
