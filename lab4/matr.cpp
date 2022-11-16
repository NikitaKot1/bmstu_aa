#include "matr.h"

#include <vector>
#include <array>
#include <stdlib.h>
#include <iostream>


using namespace std;

matr *get_csrrepresent(vector<vector<int>> old_matr)
{
    matr *new_matr = new(matr);
    int row_len = old_matr.size();
    int col_len = old_matr[0].size();
    for (int i = 0; i < row_len; i++) {
        new_matr->rows_index.push_back(new_matr->columns.size());
        for (int j = 0; j < col_len; j++) {
            if (old_matr[i][j] != 0) {
                new_matr->columns.push_back(j);
                new_matr->elements.push_back(old_matr[i][j]);
            }
        }
    }
    new_matr->rows_index.push_back(new_matr->columns.size());
    return new_matr;
}


matr *mutl(matr *a, matr *b, const int m)
{
    matr *new_matr = new(matr); // 1
    new_matr->rows_index.push_back(0);
    int col = 0;
    for (int i = 1; i < int(a->rows_index.size()); i++) // 2
    {
        int start = a->rows_index[i-1];
        int end = a->rows_index[i];
        int *prom = (int *)calloc(m, sizeof(int));
        for (int j = start; j < end; j++) { // 3
            int x = a->elements[j];
            cout << '\n';
            cout << "x: " << x << '\n';
            
            for (int k = 0; k < int(b->elements.size()); k++) {
                int row;
                for (row = 0; row < int(b->rows_index.size() - 1); ++row) {
                    cout << row << ' ';
                    if (b->rows_index[row] <= k && b->rows_index[row + 1] > k)
                        break;
                }
                
                cout << "\nk:   " << k << '\n';
                cout << "ind: " << b->rows_index[row] << '\n';
                cout << "row: " << row << '\n';

                if (row == a->columns[j])
                    prom[b->columns[k]] += x * b->elements[k]; // 3.a
                
                for (int mmm = 0; mmm < m; mmm++)
                    cout << prom[mmm] << ' ';
                cout << '\n';
            }
        }

        for (int i = 0; i < m; i++) // 3.b
            if (prom[i]) {
                new_matr->elements.push_back(prom[i]);
                new_matr->columns.push_back(i);
                col++;
            }
        new_matr->rows_index.push_back(col); // 3.c
        free(prom);
    }

    return new_matr; // 4
}

/*
3 3
3 0 0
0 0 3
1 2 3
*/