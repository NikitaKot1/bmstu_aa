#pragma once

#include <vector>

using namespace std;

typedef struct {
    vector<int> rows_index;
    vector<int> columns;
    vector<int> elements;
} matr;

matr *get_csrrepresent(vector<vector<int>> old_matr);
matr *mutl(matr *a, matr *b, const int m);