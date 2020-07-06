//
// Created by  wangchao on 2020/7/4.
//

/**
 * 矩阵的基本运算
 * */

#include "matrix.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

int array1[] = {1,2,3,4,5,6,7,8,9};
int array2[] = {11,12,13,14,15,16,17,18,19};

//矩阵初始化 初始化就是开辟内存空间,
Matrix* init_matrix(Matrix* matrix, int row, int col){
    assert(row > 0 && col > 0);
    matrix = (Matrix*)(malloc(sizeof(Matrix)));
    matrix -> row = row;
    matrix -> col = col;
    //data域也需要malloc，否则memcpy的时候会报错
    matrix->data = (int *)malloc(row * col * sizeof(int));
    return matrix;
}

void value_matrix(Matrix* matrix, int* array){
    assert(matrix->data != nullptr);
    //把array数组里面的数据copy到data指向的地址  实现初始化
    memcpy(matrix->data, array, matrix->row * matrix->col * sizeof(int)); //每个数值是int类型
}


int size_matrix(Matrix* matrix){
    return matrix->col * matrix->row;
}


void print_matrix(Matrix* matrix){
    for(int i = 0; i < size_matrix(matrix); i++){
        printf("%4d", matrix->data[i]);
        if ((i + 1)%matrix->row == 0)
            printf("\n");
    }
}

Matrix* add_matrix(Matrix* sum, Matrix* matrix1, Matrix* matrix2){
    for(int i = 0; i < size_matrix(matrix1); i++){
        sum->data[i] = matrix1->data[i] + matrix2->data[i];
    }
}

void free_matrix(Matrix* matrix){
    assert(matrix != nullptr);
    free(matrix->data);
    free(matrix);
}

int main(){
    Matrix* m1 = init_matrix(m1, 3, 3);
    Matrix* m2 = init_matrix(m2, 3, 3);
    Matrix* m3 = init_matrix(m3, 3, 3); //运算后的矩阵
    value_matrix(m1, array1);
    value_matrix(m2, array2);
    print_matrix(m1);
    printf("-----分割线-----\n");
    print_matrix(m2);
    add_matrix(m3, m1, m2);
    printf("-----相加后-----\n");
    print_matrix(m3);

    free_matrix(m1);
    free_matrix(m2);
    free_matrix(m3);

}

