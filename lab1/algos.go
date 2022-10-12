package main

/*
Рекурсивная функция Домерау-Левенштейна
*/
func dam_lev_recursive(str1, str2 string, output bool) int {
	min_ret := 0
	n := len(str1)
	m := len(str2)
	if n == 0 {
		return m
	}
	if m == 0 {
		return n
	}

	change := 0
	if str1[n-1] != str2[m-1] {
		change += 1
	}

	if n > 1 && m > 1 && str1[n-1] == str2[m-2] && str1[n-2] == str2[m-1] {
		min_ret = MinOf(dam_lev_recursive(str1[:n-1], str2, output)+1,
			dam_lev_recursive(str1, str2[:m-1], output)+1,
			dam_lev_recursive(str1[:n-1], str2[:m-1], output)+change,
			dam_lev_recursive(str1[:n-2], str2[:m-2], output)+1)
	} else {
		min_ret = MinOf(dam_lev_recursive(str1[:n-1], str2, output)+1,
			dam_lev_recursive(str1, str2[:m-1], output)+1,
			dam_lev_recursive(str1[:n-1], str2[:m-1], output)+change)
	}

	return min_ret
}

/*
Итерационная функция Домерау-Левенштейна
*/
func dam_lev_matrix(str1, str2 string, output bool) int {
	n := len(str1)
	m := len(str2)

	matr := createMatr(n+1, m+1)
	for i := 1; i < n+1; i++ {
		for j := 1; j < m+1; j++ {
			add, delete, change := matr[i-1][j]+1, matr[i][j-1]+1, matr[i-1][j-1]

			if str1[i-1] != str2[j-1] {
				change += 1
			}

			matr[i][j] = MinOf(add, delete, change)

			if i > 1 && j > 1 && str1[i-1] == str2[j-2] && str1[i-2] == str2[j-1] {
				matr[i][j] = MinOf(matr[i][j], matr[i-2][j-2]+1)
			}
		}
	}

	if output {
		printMatr(matr, n+1, m+1)
	}

	return matr[n][m]
}

/*
Рекурсивная функция Домерау-Левенштейна с кещэм
*/
func dam_lev_rec_cash_help(str1, str2 string, matr MatrInt) {
	len1 := len(str1)
	len2 := len(str2)

	if len1 == 0 {
		matr[len1][len2] = len2
	} else if len2 == 0 {
		matr[len1][len2] = len1
	} else {
		//insert
		if matr[len1][len2-1] == INF {
			dam_lev_rec_cash_help(str1, str2[:len2-1], matr)
		}
		//delete
		if matr[len1-1][len2] == INF {
			dam_lev_rec_cash_help(str1[:len1-1], str2, matr)
		}
		//replase
		if matr[len1-1][len2-1] == INF {
			dam_lev_rec_cash_help(str1[:len1-1], str2[:len2-1], matr)
		}

		change := 0
		if str1[len1-1] != str2[len2-1] {
			change += 1
		}

		matr[len1][len2] = MinOf(matr[len1][len2-1]+1,
			matr[len1-1][len2]+1,
			matr[len1-1][len2-1]+change)

		if len1 > 1 && len2 > 1 && str1[len1-1] == str2[len2-2] && str1[len1-2] == str2[len2-1] {
			matr[len1][len2] = MinOf(matr[len1][len2], matr[len1-2][len2-2]+1)
		}
	}
}

func dam_lev_rec_cash(str1, str2 string, output bool) int {
	n := len(str1)
	m := len(str2)

	matr := createInfMatrix(n+1, m+1)
	dam_lev_rec_cash_help(str1, str2, matr)

	if output {
		printMatr(matr, n+1, m+1)
	}

	return matr[n][m]
}


/*
Итерационаая функция Левенштейна
*/
func lev_matrix(str1, str2 string, output bool) int {
	n := len(str1)
	m := len(str2)

	matr := createMatr(n+1, m+1)
	for i := 1; i < n+1; i++ {
		for j := 1; j < m+1; j++ {
			add, delete, change := matr[i-1][j]+1, matr[i][j-1]+1, matr[i-1][j-1]

			if str1[i-1] != str2[j-1] {
				change += 1
			}

			matr[i][j] = MinOf(add, delete, change)
		}
	}
	
	if output {
		printMatr(matr, n+1, m+1)
	}

	return matr[n][m]
}