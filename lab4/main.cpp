#include <vector>
#include <iostream>
#include <stdio.h>


#include "matr.h"

using namespace std;

void print(matr *new_matr)
{
    cout << "\nrows ";
    for (int i = 0; i < int(new_matr->rows_index.size()); i++) {
        cout << new_matr->rows_index[i] << ' ';
    }
    cout << "\ncols ";
    for (int i = 0; i < int(new_matr->columns.size()); i++) {
        cout << new_matr->columns[i] << ' ';
    }

    cout << "\neles ";
    for (int i = 0; i < int(new_matr->elements.size()); i++) {
        cout << new_matr->elements[i] << ' ';
    }
    cout << '\n';
}

vector<vector<int>> *input(int n, int m) 
{
    vector<vector<int>> *mat = new(vector<vector<int>>);
    for (int i = 0; i < n; i++) {
        vector<int> *col = new(vector<int>);
        for (int j = 0; j < m; j++) {
            int x = 0;
            cin >> x;
            col->push_back(x);
        }
        mat->push_back(*col);
    }
    return mat;
}

int main()
{
    setbuf(stdout, NULL);
    int n = 0, m = 0, q = 0;
    cin >> n;
    cin >> m;
    cin >> q;
    
    auto m1 = input(n, m);
    auto m2 = input(m, q);

    matr * new_matr = get_csrrepresent(*m1);
    matr * new_matr2 = get_csrrepresent(*m2);

    print(new_matr);

    matr *mul = mutl(new_matr, new_matr2, q);

    print(mul);

    int **new_mul = mutl_parallel(new_matr, new_matr2, n, m, q);

    for (int i = 0; i < n; i++) {
        cout << '\n';
        for (int j = 0; j < q; j++)
            cout << new_mul[i][j] << ' ';
    }
    cout << '\n';
    for (int i = 0; i < n; i++)
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