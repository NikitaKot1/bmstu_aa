#include <vector>
#include <iostream>
#include <stdio.h>

#include "matr.h"
#include "iog.h"

int main()
{
    setbuf(stdout, NULL);
    srand(time(nullptr));
    // int n = 0, m = 0, q = 0;
    // cin >> n;
    // cin >> m;
    // cin >> q;
    
    // auto m1 = input(n, m);
    // auto m2 = input(m, q);

    auto m1 = generate();
    auto m2 = generate();

    matr *new_matr = get_csrrepresent_m(m1);
    matr *new_matr2 = get_csrrepresent_m(m2);

  //  print(new_matr);

   // matr *mul = mutl(new_matr, new_matr2, q);

   // print(mul);

    int **new_mul = mutl_parallel(new_matr, new_matr2, N, N, N);

    // for (int i = 0; i < n; i++) {
    //     cout << '\n';
    //     for (int j = 0; j < q; j++)
    //         cout << new_mul[i][j] << ' ';
    // }
    // cout << '\n';
    for (int i = 0; i < N; i++)
        free(new_mul[i]);
    free(new_mul);
    return 0;
}

/*
4 3 5
3 0 0 0 0 3
1 2 3 0 2 0
3 0 0 0 1
0 0 3 0 0
1 2 3 0 0
*/