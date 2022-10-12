package main

import (
	"fmt"
)

var INF = -1

type MatrInt [][]int

func createMatr(n, m int) MatrInt {
	matr := make(MatrInt, n+1)
	for i := range matr {
		matr[i] = make([]int, m+1)
	}

	for i := 0; i < n+1; i++ {
		matr[i][0] = 0
	}
	for j := 1; j < m+1; j++ {
		matr[0][j] = 0
	}

	return matr
}

func createInfMatrix(n, m int) MatrInt {
	matr := make(MatrInt, n+1)
	for i := range matr {
		matr[i] = make([]int, m+1)
	}

	for i := 0; i < n+1; i++ {
		for j := 0; j < m+1; j++ {
			matr[i][j] = INF
		}
	}

	return matr
}

// function min of some integers
func MinOf(vars ...int) int {
	min := vars[0]

	for _, i := range vars {
		if min > i {
			min = i
		}
	}

	return min
}

// print matrix
func printMatr(matr MatrInt, n, m int) {
	for i := 0; i < n; i++ {
		for j := 0; j < m-1; j++ {
			fmt.Print(matr[i][j])
			fmt.Print(", ")
		}
		fmt.Println(matr[i][m])
	}
}
