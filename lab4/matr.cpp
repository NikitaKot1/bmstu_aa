#include "matr.h"

#include <vector>
#include <array>
#include <stdlib.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <cmath>


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
            
            for (int k = 0; k < int(b->elements.size()); k++) {
                int row;
                for (row = 0; row < int(b->rows_index.size() - 1); ++row) {
                    if (b->rows_index[row] <= k && b->rows_index[row + 1] > k)
                        break;
                }
                if (row == a->columns[j])
                    prom[b->columns[k]] += x * b->elements[k]; // 3.a
            }
        }

        for (int f = 0; f < m; f++) // 3.b
            if (prom[f]) {
                new_matr->elements.push_back(prom[f]);
                new_matr->columns.push_back(f);
                col++;
            }
        new_matr->rows_index.push_back(col); // 3.c
        free(prom);
    }

    return new_matr; // 4
}

int **mutl_new(matr *a, matr *b, const int n, const int m, const int q)
{
    int **new_matr = (int**)calloc(n, sizeof(int*));
    for (int i = 1; i < int(a->rows_index.size()); i++) // 2
    {
        int start = a->rows_index[i-1];
        int end = a->rows_index[i];
        int *prom = (int *)calloc(q, sizeof(int));
        for (int j = start; j < end; j++) { // 3
            int x = a->elements[j];
            
            for (int k = 0; k < int(b->elements.size()); k++) {
                int row;
                for (row = 0; row < int(b->rows_index.size() - 1); ++row) {
                    if (b->rows_index[row] <= k && b->rows_index[row + 1] > k)
                        break;
                }
                if (row == a->columns[j])
                    prom[b->columns[k]] += x * b->elements[k]; // 3.a
            }
        }
        new_matr[i - 1] = prom;
   }
    return new_matr; // 4
}

void parallel_func(int **res, int st, int en, matr *a, matr *b, const int q)
{
    for (int i = st; i < en; i++) // 2
    {
        int start = a->rows_index[i-1];
        int end = a->rows_index[i];
        int *prom = (int *)calloc(q, sizeof(int));
        for (int j = start; j < end; j++) { // 3
            int x = a->elements[j];
            
            for (int k = 0; k < int(b->elements.size()); k++) {
                int row;
                for (row = 0; row < int(b->rows_index.size() - 1); ++row) {
                    if (b->rows_index[row] <= k && b->rows_index[row + 1] > k)
                        break;
                }
                if (row == a->columns[j])
                    prom[b->columns[k]] += x * b->elements[k]; // 3.a
            }
        }
        res[i - 1] = prom;
   }
}

int **mutl_parallel(matr *a, matr *b, const int n, const int m, const int q)
{
    int **new_matr = (int**)calloc(n, sizeof(int*));
    int thread_count = 2;
    vector<thread> threads(thread_count);
    double dc = double(n) / thread_count;
    int nows = 1;
    for (auto& thr: threads) {
        thr = thread(parallel_func, new_matr, nows, int(round(nows + dc)), a, b, q);
        nows += dc;
    }

    for (auto& thr: threads)
        thr.join();

    return new_matr; // 4
}

/*
4 3 5
3 0 0 0 0 3
1 2 3 0 2 0
3 0 0 0 1
0 0 3 0 0
1 2 3 0 0
*/

/*
3 3
3 0 0
0 0 3
1 2 3
*/