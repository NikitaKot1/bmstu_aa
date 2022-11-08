#include <stdlib.h>
#include <stdio.h>

#include "data.h"

int **multStand(int ** m1, int ** m2, int l, int m, int n)
{
    int **res = allocateMatrix(l, n);
    if (res) {
        for (int i = 0; i < l; i++) {

            for (int j = 0; j < n; j++) {
                res[i][j] = 0;
                for (int r = 0; r < m; r++)
                    res[i][j] = res[i][j] + m1[i][r] * m2[r][j];
            }
        }
    }
    else
        printf("Error !\n");
    return res;
}


int **multVin(int **m1, int **m2, int l, int m, int n)
{
    int **res = allocateMatrix(l, n);
    int *mulH = calloc (l, sizeof(int));
    int *mulV = calloc (n, sizeof(int));
    if (res && mulH && mulV) {
        for (int i = 0; i < l; i++)
            for (int k = 0; k < m / 2; k++)
                mulH[i] = mulH[i] + m1[i][2 * k] * m1[i][2 * k + 1];
        for (int i = 0; i < n; i++)
            for (int k = 0; k < m / 2; k++)
                mulV[i] = mulV[i] + m2[2 * k][i] * m2[2 * k + 1][i];
        for (int i = 0; i < l; i++)
            for (int j = 0; j < n; j++) {
                res[i][j] = - mulH[i] - mulV[j];
                for (int k = 0; k < m / 2; k++)
                    res[i][j] = res[i][j] + (m1[i][2 * k] + m2[2 * k + 1][j]) * (m1[i][2 * k + 1] + m2[2 * k][j]);
        }
        if (m % 2 == 1)
            for (int i = 0; i < l ; i++)
                for (int j = 0; j < n ; j++)
                    res[i][j] = res[i][j] + m1[i][m - 1] * m2 [m - 1][j];
        free(mulH);
        free(mulV);
    }
    else
        printf("Error!\n");
    return res;
}

int **multVinOptimize(int **m1, int **m2, int l, int m, int n)
{
    int **res = allocateMatrix(l, n);
    int *mulH = calloc(l, sizeof(int));
    int *mulV = calloc(n, sizeof(int));
    if (res && mulH && mulV) {
        int optm = m / 2;
        int f;
        for (int i = 0; i < l; i++)
            for (int k = 0; k < optm; k++) {
                f = k << 1;
                mulH[i] += m1[i][f] * m1[i][f + 1];
            }
        for (int i = 0; i < n; i++)
            for (int k = 0; k < optm; k++) {
                f = k << 1;
                mulV[i] += m2[f][i] * m2[f + 1][i];
            }
        for (int i = 0; i < l; i++)
            for (int j = 0; j < n; j++) {
                res[i][j] = - mulH[i] - mulV[j];
                for (int k = 0; k < optm; k++) {
                    f = k << 1;
                    res[i][j] += (m1[i][f] + m2[f+ 1][j]) * (m1[i][f + 1] + m2[f][j]);
                }
        }
        if (m % 2 == 1)
            for (int i = 0; i < l ; i++)
                for (int j = 0; j < n ; j++)
                    res[i][j] += m1[i][m - 1] * m2 [m - 1][j];
        free(mulH);
        free(mulV);
    }
    else
        printf("Error!\n");
    return res;
}