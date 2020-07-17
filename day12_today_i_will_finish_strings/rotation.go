package main

import (
	"fmt"
)

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

func rotateMatrix(matrix [][]int) [][]int {
	if len(matrix) == 0 {
		return matrix
	}
	rows,columns:=len(matrix),len(matrix[0])
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
	for i := 0; i < length; i++ {
		for j := 0; j < length/2; j++ {
			temp:=matrix[i][j]
			matrix[i][j]=matrix[i][length-1-j]
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