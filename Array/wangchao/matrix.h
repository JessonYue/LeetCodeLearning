//
// Created by  wangchao on 2020/7/4.
//

#ifndef C_DEMO_MATRIX_H
#define C_DEMO_MATRIX_H

#endif //C_DEMO_MATRIX_H


//定义矩阵结构体
typedef struct {
    int row, col;
    int * data; //这个指针是数组
}Matrix;

Matrix* init_matrix(Matrix* matrix, int row, int col);
void value_matrix(Matrix* matrix, double* array);
int size_matrix(Matrix* matrix);
void print_matrix(Matrix* matrix);
Matrix* add_matrix(Matrix* sum, Matrix* matrix1, Matrix* matrix2);
void free_matrix(Matrix* matrix);
