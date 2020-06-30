//
// Created by Vashon on 2020/6/29.
//

#include <stdio.h>

#define ROW_1 2
#define COLUMN_1 2
#define ROW_2 2
#define COLUMN_2 3
typedef int ElemType;

// 两个矩阵相加
void matrixAdd(ElemType **matrix1, ElemType **matrix2, ElemType **destMatrix, unsigned int rows, unsigned int columns);

// 两个矩阵相减
void matrixSub(ElemType **matrix1, ElemType **matrix2, ElemType **destMatrix, unsigned int rows, unsigned int columns);

// 两个矩阵相乘
void matrixMul(
        ElemType **matrix1, unsigned int rows1, unsigned int columns1,
        ElemType **matrix2, unsigned int rows2, unsigned int columns2,
        ElemType **destMatrix);

// 两个矩阵相除
void matrixDiv(
        ElemType **matrix1, unsigned int rows1, unsigned int columns1,
        ElemType **matrix2, unsigned int rows2, unsigned int columns2,
        ElemType **destMatrix);

// 打印矩阵内的所有元素
void printfMatrix(ElemType **matrix, unsigned int rows, unsigned int columns);

void homework_matrix(void) {
//    ElemType a[ROW_1][COLUMN_1] = {{1, 2},
//                                   {1, -1}};
//    ElemType b[ROW_1][COLUMN_1] = {{1,  2},
//                                   {-1, 1}};
//    ElemType c[ROW_1][COLUMN_1] = {{0, 0},
//                                   {0, 0}};

    ElemType a[ROW_1][COLUMN_1] = {{1, 2},
                                   {1, -1}};
    ElemType b[ROW_2][COLUMN_2] = {{1,  2, -3},
                                   {-1, 1, 2}};
    ElemType c[ROW_1][COLUMN_2] = {{0, 0, 0},
                                   {0, 0, 0}};

    printfMatrix((ElemType **) a, ROW_1, COLUMN_1);
    printfMatrix((ElemType **) b, ROW_2, COLUMN_2);
    printfMatrix((ElemType **) c, ROW_1, COLUMN_2);
//    matrixAdd((ElemType **) a, (ElemType **) b, (ElemType **) c, ROW_1, COLUMN_1);
//    matrixSub((ElemType **) a, (ElemType **) b, (ElemType **) c, ROW_1, COLUMN_1);
    matrixMul((ElemType **) a, ROW_1, COLUMN_1, (ElemType **) b, ROW_2, COLUMN_2, (ElemType **) c);
//    matrixDiv((ElemType **) a, ROW_1, COLUMN_1, (ElemType **) b, ROW_2, COLUMN_2, (ElemType **) c);
    printfMatrix((ElemType **) a, ROW_1, COLUMN_1);
    printfMatrix((ElemType **) b, ROW_2, COLUMN_2);
    printfMatrix((ElemType **) c, ROW_1, COLUMN_2);
}

void matrixAdd(ElemType **matrix1, ElemType **matrix2, ElemType **destMatrix, unsigned int rows, unsigned int columns) {
    if (!matrix1 || !matrix2 || !destMatrix)
        return;
    // 由于 C 语言不支持隐式传递多维数组，所以这里需要使用指向单个元素大小的指针操作，这样的好处是省去了地址的计算，只需要指针自增操作即可
    ElemType *matr1 = (ElemType *) matrix1, *matr2 = (ElemType *) matrix2, *dest = (ElemType *) destMatrix;
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < columns; ++c, ++matr1, ++matr2, ++dest) {
            *dest = *matr1 + *matr2;
        }
    }
}

void matrixSub(ElemType **matrix1, ElemType **matrix2, ElemType **destMatrix, unsigned int rows, unsigned int columns) {
    if (!matrix1 || !matrix2 || !destMatrix)
        return;
    ElemType *matr1 = (ElemType *) matrix1, *matr2 = (ElemType *) matrix2, *dest = (ElemType *) destMatrix;
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < columns; ++c, ++matr1, ++matr2, ++dest) {
            *dest = *matr1 - *matr2;
        }
    }
}

void matrixMul(
        ElemType **matrix1, unsigned int rows1, unsigned int columns1,
        ElemType **matrix2, unsigned int rows2, unsigned int columns2,
        ElemType **destMatrix) {
    if (!matrix1 || !matrix2 || !destMatrix || (columns1 != rows2))
        return;
    ElemType *matr1, *matr2, *dest, *temp;
    // 这里是存放目标矩阵对应每行的列的值
    for (int i = 0; i < rows1; ++i) {
        dest = ((ElemType *) destMatrix) + (i * columns2);  // 计算出目标矩阵存放值的地址
        temp = ((ElemType *) matrix1) + (i * columns1);     // 计算出矩阵1对应元素的地址
        for (int j = 0; j < columns2; ++j, ++dest) {
            matr1 = temp;
            ElemType elem = 0;
            for (int k = 0; k < columns1; ++k, ++matr1) {
                matr2 = ((ElemType *) matrix2) + (k * columns2) + j;// 计算出矩阵2对应元素的地址
                elem += *matr1 * *matr2;
            }
            *dest = elem;
        }
    }
}

void matrixDiv(
        ElemType **matrix1, unsigned int rows1, unsigned int columns1,
        ElemType **matrix2, unsigned int rows2, unsigned int columns2,
        ElemType **destMatrix) {
    if (!matrix1 || !matrix2 || !destMatrix || (columns1 != rows2))
        return;
    ElemType *matr1, *matr2, *dest, *temp;
    // 这里是存放目标矩阵对应每行的列的值
    for (int i = 0; i < rows1; ++i) {
        dest = ((ElemType *) destMatrix) + (i * columns2);  // 计算出目标矩阵存放值的地址
        temp = ((ElemType *) matrix1) + (i * columns1);     // 计算出矩阵1对应元素的地址
        for (int j = 0; j < columns2; ++j, ++dest) {
            matr1 = temp;
            ElemType elem = 0;
            for (int k = 0; k < columns1; ++k, ++matr1) {
                matr2 = ((ElemType *) matrix2) + (k * columns2) + j;// 计算出矩阵2对应元素的地址
                if (*matr2 != 0)
                    elem += *matr1 / *matr2;
            }
            *dest = elem;
        }
    }
}

void printfMatrix(ElemType **matrix, unsigned int rows, unsigned int columns) {
    ElemType *matr = (ElemType *) matrix;
    printf("Matrix address is : %x : \n", matrix);
    for (int i = 0; i < rows; ++i) {
        printf("[");
        for (int j = 0; j < columns; ++j, matr++) {
            printf(" %d ", *matr);
        }
        printf("]\n");
    }
}