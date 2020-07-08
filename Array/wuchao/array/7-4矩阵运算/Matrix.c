#include <stdlib.h>
#include <stdio.h>
//
// Created by 吴超 on 2020/7/2.
//

typedef struct Matrix {
    int rows;
    int cols;
    int **data;
} Matrix;

Matrix *makeMatrix(int rows, int cols);

Matrix *matrixAdd(Matrix *a, Matrix *b);

Matrix *matrixSub(Matrix *a, Matrix *b);
Matrix *matrixMultiplyWithANumber(Matrix *a, int b);
Matrix *matrixMultiply(Matrix *a, Matrix *b);

void printMatrix(Matrix *matrix);

int main() {
    Matrix *a = makeMatrix(5, 3);
    Matrix *b = makeMatrix(5, 3);
    int test1[5][3] = {
            {1,  3,  4},
            {3,  5,  6},
            {43, 1,  5},
            {6,  7,  33},
            {34, 77, 11}
    };
    int test2[5][3] = {
            {10, 31, 4},
            {5,  68, 62},
            {53, 0,  52},
            {26, 67, 63},
            {84, 7,  12}
    };
//    int test1[3][1] = {
//            {1},
//            {2},
//            {3}
//    };
//    int test2[1][3] = {
//            {1, 2, 3}
//    };
    for (int i = 0; i < a->rows; i++) {
        a->data[i] = test1[i];
    }
    printMatrix(a);
    printf("----------------\n");
    for (int i = 0; i < b->rows; i++) {
        b->data[i] = test2[i];
    }
    printMatrix(b);
    printf("----------------\n");
    printMatrix(matrixAdd(a, b));
    printf("----------------\n");
    printMatrix(matrixSub(b, a));
    printf("----------------\n");
    printMatrix(matrixMultiplyWithANumber(a,4));
    printMatrix(matrixMultiply(b, a));
}

Matrix *makeMatrix(int rows, int cols) {
    Matrix *matrix = malloc(sizeof(Matrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix->data[i] = malloc(cols * sizeof(int));
    }
    return matrix;
}

Matrix *matrixAdd(Matrix *a, Matrix *b) {
    //不是同形矩阵，不能做加法运算
    if (a->rows != b->rows || a->cols != b->cols) {
        printf("不是同形矩阵，不能做加法运算\n");
        return NULL;
    }
    Matrix *matrix = makeMatrix(a->rows, a->cols);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            matrix->data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }
    return matrix;
}

Matrix *matrixSub(Matrix *a, Matrix *b){
    if (a->rows != b->rows || a->cols != b->cols) {
        printf("不是同形矩阵，不能做减法运算\n");
        return NULL;
    }
    Matrix *matrix = makeMatrix(a->rows, a->cols);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            matrix->data[i][j] = a->data[i][j] - b->data[i][j];
        }
    }
    return matrix;
}

Matrix *matrixMultiplyWithANumber(Matrix *a, int b){
    Matrix * matrix = makeMatrix(a->rows,a->cols);
    for(int i=0;i<matrix->rows;i++){
        for(int j=0;j<matrix->cols;j++){
            matrix->data[i][j] = a->data[i][j] * b;
        }
    }
    return matrix;
}

Matrix *matrixMultiply(Matrix *a, Matrix *b){
    if(a->cols!=b->rows){
        printf("左矩阵的列数和右矩阵的行数不等，不能做乘法运算\n");
        return NULL;
    }
    Matrix * matrix = makeMatrix(a->rows,b->cols);
    for(int i=0;i<matrix->rows;i++){
        for(int j=0;j<matrix->cols;j++){
            int result1=0;
            for(int m=0;m<a->cols;m++){
                result1+=a->data[i][m]*b->data[m][j];
            }
            matrix->data[i][j] = result1;
        }
    }
    return matrix;
}

void printMatrix(Matrix *matrix) {
    if(matrix==NULL){
        return;
    }
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%d,", matrix->data[i][j]);
        }
        printf("\n");
    }
}



