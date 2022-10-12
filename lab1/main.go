package main

import "fmt"

func main() {
	var first, second string
	// for i := 0; i < 1000; i++ {
	// 	dam_lev_recursive("qwertyuio", "asdfghjkl", false)
	// }
	fmt.Printf("Введите первое слово: ")
	fmt.Scanln(&first)
	fmt.Printf("Введите второе слово: ")
	fmt.Scanln(&second)

	dist := dam_lev_matrix(first, second, false)
	fmt.Println("расстояние Домерау-Левенштейна, алгоритм не рекурсивный: ", dist)

	dist = dam_lev_rec_cash(first, second, false)
	fmt.Println("расстояние Домерау-Левенштейна, алгоритм рекурсивный с кешем: ", dist)

	dist = dam_lev_recursive(first, second, false)
	fmt.Println("расстояние Домерау-Левенштейна, алгоритм рекурсивный: ", dist)

	dist = lev_matrix(first, second, false)
	fmt.Println("расстояние Левенштейна, алгоритм не рекурсивный: ", dist)
}