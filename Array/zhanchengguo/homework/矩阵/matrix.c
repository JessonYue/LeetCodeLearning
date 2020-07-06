#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int row;//行
    int col;//列
    int *data;
} Matirx;

// ------------- 声明 --------------------

//初始化
Matirx *init(Matirx *matirx, int row, int col);

//初始化数据
void initData(Matirx *matirx, int *array);

int getMatirxSize(Matirx *matirx);

//释放
void freeMatirx(Matirx *matirx);

//打印
void printMatrix(Matirx *matirx);

//加
Matirx *add(Matirx *matirx1, Matirx *matirx2);

//减
Matirx *subtract(Matirx *matirx1, Matirx *matirx2);

//乘
Matirx *multiplyNum(Matirx *matirx, int num);

Matirx *multiply(Matirx *matirx1, Matirx *matirx2);


// ------------- 实现 --------------------

Matirx *init(Matirx *matirx, int row, int col) {
    if (row > 0 && col > 0) {
        matirx = (Matirx *) malloc(sizeof(Matirx));
        matirx->row = row;
        matirx->col = col;
        matirx->data = (int *) malloc(sizeof(int) * row * col);
        return matirx;
    } else {
        return NULL;
    }
}

void initData(Matirx *matirx, int *array) {
    if (matirx->data != NULL) {
        memcpy(matirx->data, array, matirx->row * matirx->col * sizeof(int));
    }
}

void freeMatirx(Matirx *matirx) {
    free(matirx->data);
    free(matirx);
}

int getMatirxSize(Matirx *matirx) {
    return matirx->row * matirx->col;
}


void printMatrix(Matirx *matirx) {
    for (int i = 0; i < getMatirxSize(matirx); ++i) {
        printf("%d ", matirx->data[i]);
        if ((i + 1) % matirx->row == 0) {
            printf("\n");
        }
    }
}

Matirx *add(Matirx *matirx1, Matirx *matirx2) {
    //注意：只有对于两个行数、列数分别相等的矩阵（即同型矩阵），加减法运算才有意义，即加减运算是可行的．
    if (matirx1->row == matirx2->row && matirx1->col == matirx2->col) {
        Matirx *resMatrix;
        resMatrix = init(resMatrix, matirx1->row, matirx1->col);
        for (int i = 0; i < getMatirxSize(matirx1); i++) {
            resMatrix->data[i] = matirx1->data[i] + matirx2->data[i];
        }
        return resMatrix;
    }
    return NULL;
}

Matirx *subtract(Matirx *matirx1, Matirx *matirx2) {
    //注意：只有对于两个行数、列数分别相等的矩阵（即同型矩阵），加减法运算才有意义，即加减运算是可行的．
    if (matirx1->row == matirx2->row && matirx1->col == matirx2->col) {
        Matirx *resMatrix;
        resMatrix = init(resMatrix, matirx1->row, matirx1->col);
        for (int i = 0; i < getMatirxSize(matirx1); i++) {
            resMatrix->data[i] = matirx1->data[i] - matirx2->data[i];
        }
        return resMatrix;
    }
    return NULL;
}

Matirx *multiplyNum(Matirx *matirx, int num) {
    Matirx *resMatrix;
    resMatrix = init(resMatrix, matirx->row, matirx->col);
    for (int i = 0; i < getMatirxSize(matirx); i++) {
        resMatrix->data[i] = matirx->data[i] * num;
    }
    return resMatrix;
}

Matirx *multiply(Matirx *matirx1, Matirx *matirx2) {
    //注意：matirx1的列数（col）必须要与matirx2的行数（row）相等
    if (matirx1->col == matirx2->row) {
        Matirx *resMatrix;
        resMatrix = init(resMatrix, matirx1->row, matirx2->col);
        for (int i = 0; i < matirx1->col; i++) {
            for (int j = 0; j < matirx2->row; j++) {
                for (int k = 0; k < matirx1->row; k++) {
                    resMatrix->data[i * resMatrix->row + j] = resMatrix->data[i * resMatrix->row + j] +
                                                              matirx1->data[i * matirx1->row + k] *
                                                              matirx2->data[k * matirx2->row + j];
                }
            }
        }
        return resMatrix;
    }
    return NULL;
}


int main() {
    int value[] = {2, 4, 5, 6, 7, 9, 11, -4, 9};
    int value2[] = {9, 8, 7, 6, 5, 4, 3, 2, 10};
    Matirx *matirx1;
    Matirx *matirx2;
    matirx1 = init(matirx1, 3, 3);
    matirx2 = init(matirx2, 3, 3);
    initData(matirx1, value);
    initData(matirx2, value2);
    printf("-------init-----\n");
    printf("-------matirx1-----\n");
    printMatrix(matirx1);
    printf("-------matirx2-----\n");
    printMatrix(matirx2);
    printf("-------加法-----\n");
    Matirx *add_res = add(matirx1, matirx2);
    printMatrix(add_res);
    printf("-------减法-----\n");
    Matirx *sub_res = subtract(matirx1, matirx2);
    printMatrix(sub_res);
    printf("-------乘法 矩阵与数-----\n");
    Matirx *mul_num = multiplyNum(matirx1, 3);
    printMatrix(mul_num);
    printf("-------乘法 矩阵与矩阵-----\n");
    Matirx *mul_res = multiply(matirx1, matirx2);
    printMatrix(mul_res);
    return 0;
}
