#pragma once

#include <vector>
#include <iostream>
#include <stdio.h>

#include "matr.h"

using namespace std;

#define N 500

int **generate();
void print(matr *new_matr);
vector<vector<int>> *input(int n, int m);
