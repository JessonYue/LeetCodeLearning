//
// Created by qiguang.zhu on 2020/7/2.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int row;//行
    int column;//列
    int *data;
} Matrix;

/**
 * 初始化矩阵
 * @param matrix
 * @param row
 * @param column
 * @return
 */
Matrix *init(Matrix *matrix, int row, int column);

/**
 * 给矩阵赋值
 * @param matrix
 * @param arr
 */
void input_matrix(Matrix *matrix, int arr[]);

/**
 * 获取矩阵长度
 * @param matrix
 * @return
 */
int getMatrixLength(Matrix *matrix);

/**
 * 打印矩阵
 * @param matrix
 */
void print_matrix(Matrix *matrix);

Matrix *add(Matrix *matrix1, Matrix *matrix2);

Matrix *minus(Matrix *matrix1, Matrix *matrix2);

Matrix *multiply(Matrix *matrix1, Matrix *matrix2);

Matrix *init(Matrix *matrix, int row, int column) {
    if (row > 0 && column > 0) {
        matrix = (Matrix *) malloc(sizeof(Matrix));
        matrix->row = row;
        matrix->column = column;
        matrix->data = malloc(sizeof(int) * row * column);
        return matrix;
    } else {
        return NULL;
    }
}

void input_matrix(Matrix *matrix, int arr[]) {
    memcpy(matrix->data, arr, sizeof(int) * matrix->row * matrix->column);
}

int getMatrixLength(Matrix *matrix) {
    return matrix->row * matrix->column;
}

void print_matrix(Matrix *matrix) {
    for (int i = 0; i < getMatrixLength(matrix); ++i) {
        printf("%d ", matrix->data[i]);
        if ((i + 1) % matrix->row == 0) {
            printf("\n");
        }
    }
    printf("----------------\n");
}

Matrix *add(Matrix *matrix1, Matrix *matrix2) {
    Matrix *matrix = NULL;
    if ((matrix1->row != matrix2->row) || (matrix1->column != matrix2->column)) return matrix;
    matrix = init(matrix, matrix1->row, matrix2->column);
    matrix->row = matrix1->row;
    matrix->column = matrix1->column;
    for (int i = 0; i < getMatrixLength(matrix1); ++i) {
        matrix->data[i] = matrix1->data[i] + matrix2->data[i];
    }
    return matrix;
}

Matrix *minus(Matrix *matrix1, Matrix *matrix2) {
    Matrix *matrix = NULL;
    if ((matrix1->row != matrix2->row) || (matrix1->column != matrix2->column)) return matrix;
    matrix = init(matrix, matrix1->row, matrix2->column);
    matrix->row = matrix1->row;
    matrix->column = matrix1->column;
    for (int i = 0; i < getMatrixLength(matrix1); ++i) {
        matrix->data[i] = matrix1->data[i] - matrix2->data[i];
    }
    return matrix;
}

Matrix *multiply(Matrix *matrix1, Matrix *matrix2) {
    Matrix *matrix = NULL;
    //todo 乘法搞不懂
    return matrix;
}


int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int b[] = {2, 3, 4, 5, 6, 7, 8, 9, 10};
    Matrix *matrixa = NULL;
    matrixa = init(matrixa, 3, 3);
    input_matrix(matrixa, a);
    print_matrix(matrixa);

    Matrix *matrixb = NULL;
    matrixb = init(matrixb, 3, 3);
    input_matrix(matrixb, b);
    print_matrix(matrixb);
    printf("===========加法============\n");
    print_matrix(add(matrixa, matrixb));

    printf("===========减法============\n");
    print_matrix(minus(matrixa, matrixb));

    printf("===========乘法============\n");
    print_matrix(multiply(matrixa, matrixb));
    return 0;
}

