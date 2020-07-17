package main

import (
	"fmt"
)
// CTCI method
func rotateMe(matrix [][]int) [][]int {
	if len(matrix) == 0 {
		return matrix
	}
	// check length of row and columns
	n := len(matrix)
	for layer := 0; layer < n/2; layer++ {
		last := n - 1 - layer
		for i := layer; i < last; i++ {
			offset := i - layer
			temp := matrix[layer][i]
			matrix[layer][i] = matrix[last-offset][layer]
			matrix[last-offset][layer] = matrix[last][last-offset]
			matrix[last][last-offset] = matrix[i][last]
			matrix[i][last] = temp
		}
	}
	return matrix
}

// My Method
func rotateMatrix(matrix [][]int) [][]int {
	if len(matrix) == 0 {
		return matrix
	}
	rows,columns:=len(matrix),len(matrix[0])
	fmt.Println("rows and columns",rows,columns)
	fmt.Println("3/2",rows/2)
	if rows !=columns {
		return matrix
	}
	// transposing the matrix
	length:=len(matrix)
	for i := 0; i < length; i++ {
		for j := i; j < length; j++ {
			
			temp:=matrix[i][j]
			matrix[i][j]=matrix[j][i]
			matrix[j][i]=temp //swapping the rows and the columns

		}
		
	}
	for i := 0; i < length; i++ { //length =3
		for j := 0; j < length/2; j++ {  //final j value is 3/2 is 1
			temp:=matrix[i][j]
			matrix[i][j]=matrix[i][length-1-j] //at first iteration length -1-j=3-1-0=2 so swap by matrix[0][2]
			matrix[j][i]=temp
		}
		
	}
	return matrix
}

func main(){
	arr:=[][]int{{1,2,3},
				 {4,5,6},
				 {7,8,9}}
	fmt.Println(rotateMe(arr))
	fmt.Println(rotateMatrix(arr))
}

/* 

[1,2,3]							[1,4,7]						[7,4,1]
[4,5,6] ----> after transposing [2,5,8]----->swapping rows	[8,5,2]
[7,8,9]							[3,6,9]						[9,6,3] //done!!

*/