//
// Created by 丰雷 on 2020/7/2.
//

#include <stdio.h>
#include <mm_malloc.h>

#define ARRAY_ROW 3
#define ARRAY_COL 3

// 加
int **add(int(*a)[ARRAY_ROW], int(*b)[ARRAY_ROW]);

// 减
int **sub(int(*a)[ARRAY_ROW], int(*b)[ARRAY_ROW]);

// 乘
int **multi(int(*a)[ARRAY_ROW], int(*b)[ARRAY_ROW]);

// 除
int **division(int(*a)[ARRAY_ROW], int(*b)[ARRAY_ROW]);

// 打印
void printMatrix(int **a);


int **add(int(*a)[ARRAY_ROW], int(*b)[ARRAY_ROW]) {
    int **result = malloc(sizeof(int *) * ARRAY_ROW);
    int i, j;
    for (i = 0; i < ARRAY_ROW; ++i) {
        result[i] = malloc(sizeof(int) * ARRAY_COL);
        for (j = 0; j < ARRAY_COL; ++j) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
    return result;
}

int **sub(int(*a)[ARRAY_ROW], int(*b)[ARRAY_ROW]) {
    int **result = malloc(sizeof(int *) * ARRAY_ROW);
    int i, j;
    for (i = 0; i < ARRAY_ROW; ++i) {
        result[i] = malloc(sizeof(int) * ARRAY_COL);
        for (j = 0; j < ARRAY_COL; ++j) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
    return result;
}


int **multi(int(*a)[ARRAY_ROW], int(*b)[ARRAY_ROW]) {
    int **result = malloc(sizeof(int *) * ARRAY_ROW);
    int i, j;
    for (i = 0; i < ARRAY_ROW; ++i) {
        result[i] = malloc(sizeof(int) * ARRAY_COL);
        for (j = 0; j < ARRAY_ROW; ++j) {
            for (int k = 0; k < ARRAY_COL; ++k) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return result;
}

int **division(int(*a)[ARRAY_ROW], int(*b)[ARRAY_ROW]) {
    int **result = malloc(sizeof(int *) * ARRAY_ROW);
    int i, j;
    for (i = 0; i < ARRAY_ROW; ++i) {
        result[i] = malloc(sizeof(int) * ARRAY_COL);
        for (j = 0; j < ARRAY_COL; ++j) {
            result[i][j] = a[i][j] / b[i][j];
        }
    }
    return result;
}

void printMatrix(int **a) {
    for (int i = 0; i < ARRAY_ROW; ++i) {
        for (int j = 0; j < ARRAY_COL; ++j) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


void main() {
    int a[ARRAY_ROW][ARRAY_COL] = {
            {1, 2,  3},
            {5, 6,  7},
            {9, 10, 11}
    };
    int b[ARRAY_ROW][ARRAY_COL] = {
            {1, 4, 7},
            {2, 5, 8},
            {3, 6, 9}
    };

    int **result = add(a, b);
    printMatrix(result);

    result = sub(a,b);
    printMatrix(result);

    result = multi(a,b);
    printMatrix(result);

    result = division(a,b);
    printMatrix(result);
}
