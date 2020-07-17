package main

import "fmt"

// given an array of integers and a number, check which two number's sum matches the given number


func twoNumberSum(input []int,val int)(val1 int ,val2 int){
	sumMap:=make(map[int]bool)
	for _, num := range input {
		sum:=19-num
		if sumMap[sum] {
			return num,sum
		}
		sumMap[num]=true
	}
	return 0,0
}

func main(){
	arr:=[]int{3,5,-4,8,11,1,-1,6}
	fmt.Println(twoNumberSum(arr,19))
}