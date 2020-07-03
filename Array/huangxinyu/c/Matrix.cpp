//
// Created by hasee on 2020/7/2.
//
#include <assert.h>
#include <cstdlib>
#include <cstdio>

/**
 * 矩阵加法
 * @param m1 矩阵1
 * @param wh1 矩阵1行列数
 * @param m2 矩阵2
 * @param wh2 矩阵2行列数
 * @return
 */

int **create(int m, int n);

int **add(int m, int n, int **m1, int **m2);

int **subtraction(int m, int n, int **m1, int **m2);

int **multipl(int m, int n1, int n, int **m1, int **m2);

int **add(int m, int n, int **m1, int **m2) {

    int **ret = (int **) malloc(sizeof(int) * m);
    for (int i = 0; i < m; ++i) {
        ret[i] = (int *) (malloc(sizeof(int) * n));
    }
    for (int j = 0; j < m; ++j) {
        for (int k = 0; k < n; ++k) {
            ret[j][k] = m1[j][k] + m2[j][k];
        }
    }
    return ret;
}

int **subtraction(int m, int n, int **m1, int **m2) {

    int **ret = (int **) malloc(sizeof(int) * m);
    for (int i = 0; i < m; ++i) {
        ret[i] = (int *) (malloc(sizeof(int) * n));
    }
    for (int j = 0; j < m; ++j) {
        for (int k = 0; k < n; ++k) {
            ret[j][k] = m1[j][k] - m2[j][k];
        }
    }
    return ret;
}
/**
 * 该函数默认m1矩阵列数和m2矩阵行数相同
 * @param m m1矩阵行数
 * @param n1 m1矩阵列数
 * @param n m2矩阵列数
 * @param m1
 * @param m2
 * @return
 */
int **multipl(int m, int n1, int n, int **m1, int **m2) {
    int **ret = create(m, n);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            ret[i][j] = 0;
            for (int k = 0; k < n1; ++k) {
                ret[i][j] += m1[i][k] + m2[k][j];
            }
        }
    }
    return ret;
}

int **create(int m, int n) {
    int **matrix = static_cast<int **>(malloc(sizeof(int) * m));
    for (int i = 0; i < m; ++i) {
        matrix[i] = (int *) malloc(sizeof(int) * n);
    }
    return matrix;
}

void printMatrix(int m, int n, int **matrix) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}


int main() {
    const int m = 3;
    const int n = 2;
    int **a = create(m, n);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            a[i][j] = 1;
        }
    }
    int **b = create(m, n);
    for (int k = 0; k < m; ++k) {
        for (int i = 0; i < n; ++i) {
            b[k][i] = 2;
        }
    }
    int **ret = subtraction(m, n, a, b);
    printMatrix(m, n, ret);
}