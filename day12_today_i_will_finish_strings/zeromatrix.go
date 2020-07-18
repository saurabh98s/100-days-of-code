package main

import "fmt"
// the question asks if the  element in an m*n matrix is 0, if yes then changes the entire 
// row and columns of the element to 0.


func checkForZero(matrix [][]int)  [][]int{
	rows:=make([]bool,len(matrix))
	cols:=make([]bool,len(matrix))

	for i := 0; i < len(matrix); i++ {
		for j := 0; j < len(matrix); j++ {
			if matrix[i][j]==0 {
				rows[i]=true
				cols[j]=true		
			}
		}
	}
	for row := 0; row < len(rows); row++ {
		if rows[row] {
			zeroRows(matrix,row)
		}
	}

	for col := 0; col < len(rows); col++ {
		if cols[col] {
			zeroCols(matrix,col)
		}
	}
	return matrix

}

func zeroRows(matrix [][]int, row int)  {
	for i := 0; i < len(matrix[0]); i++ {
		matrix[row][i]=0
	}
}

func zeroCols(matrix [][]int, cols int)  {
	for i := 0; i < len(matrix); i++ {
		matrix[i][cols]=0
	}
}


func main(){
	arr:=[][]int{{1,0,3},
	{4,5,6},
	{7,8,9}}
fmt.Println(checkForZero(arr))
}