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
    
    return 0;
}