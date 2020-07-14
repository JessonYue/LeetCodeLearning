//
// Created by 张佳男 on 2020/7/10.
//

#include<string.h>
#include <assert.h>
#include <stdlib.h>
//定义矩阵结构体
typedef struct {
    int row, col;
    int * data; //这个指针是数组
}Matrix;

Matrix* init_matrix(int row, int col);
void value_matrix(Matrix* matrix, double* array);
int size_matrix(Matrix* matrix);
void print_matrix(Matrix* matrix);
Matrix* add_matrix(Matrix* sum, Matrix* matrix1, Matrix* matrix2);
Matrix* sub_matrix(Matrix* sum, Matrix* matrix1, Matrix* matrix2);
void free_matrix(Matrix* matrix);

//矩阵初始化 初始化就是开辟内存空间,
Matrix* init_matrix(int row, int col){
    assert(row > 0 && col > 0);
    Matrix* matrix=(Matrix*)malloc(sizeof(Matrix));
    matrix->col = col;
    matrix->row = row;
    matrix->data=malloc(sizeof(row*col*sizeof(int)));
    return matrix;
}

void value_matrix(Matrix* matrix, double* array){
    assert(matrix->data != NULL);
    memcpy(matrix->data,array,matrix->row*matrix->col*sizeof(int));
}

int size_matrix(Matrix* matrix){
    return matrix->col*matrix->row;
}

void print_matrix(Matrix* matrix){
    for (int i = 0; i < size_matrix(matrix); ++i) {
        printf("%d",matrix->data[i]);
        if ((i + 1) % matrix->row == 0) {
            printf("\n");
        }
    }
}
Matrix* add_matrix(Matrix* sum, Matrix* matrix1, Matrix* matrix2){
    if (matrix1->row!=matrix2->row||matrix2->col!=matrix1->col) {
        printf("不是同形矩阵，不能做加法运算\n");
        return NULL;
    }
    for (int i = 0; i < size_matrix(matrix1); ++i) {
        sum->data[i] = matrix1->data[i] + matrix2->data[i];
    }
}
Matrix* sub_matrix(Matrix* sum, Matrix* matrix1, Matrix* matrix2){
    if (matrix1->row!=matrix2->row||matrix2->col!=matrix1->col) {
        printf("不是同形矩阵，不能做加法运算\n");
        return NULL;
    }
    for (int i = 0; i < size_matrix(matrix1); ++i) {
        sum->data[i] = matrix1->data[i] - matrix2->data[i];
    }
}
void free_matrix(Matrix* matrix){
    assert(matrix != NULL);
    free(matrix->data);
    free(matrix);
}