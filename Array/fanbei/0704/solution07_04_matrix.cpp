#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct Matrix {
    int row;
    int column;
    int *data;
} Matrix;

Matrix *initMatrix(int row, int column);

int addMatrix(struct Matrix *a, struct Matrix *b, struct Matrix *c);

int minusMatrix(struct Matrix *a, struct Matrix *b, struct Matrix *c);

int multiplyMatrix(struct Matrix *a, struct Matrix *b, struct Matrix *c);

void printfMatrix(const Matrix *m);

int main() {
    int a[2][3] = {{1, 2, -3},
                   {4, 5, 6}};
    int b[2][3] = {{7,  8,  9},
                   {10, 11, -2}};
    //加减法矩阵行列必须一致
    Matrix *m1 = initMatrix(2, 3);
    Matrix *m2 = initMatrix(2, 3);
    Matrix *m3 = initMatrix(m1->row, m1->column);
    m1->data = a[0];
    m2->data = b[0];
    addMatrix(m1, m2, m3);
    printfMatrix(m3);
    minusMatrix(m1, m2, m3);
    printfMatrix(m3);
    free(m1);
    free(m2);
    free(m3);
    //乘法a行必须等于b列
    int a1[2][2] = {{1,  1},
                    {-1, -1}};
    int b1[2][2] = {{1,  -1},
                    {-1, 1}};
    Matrix *m4 = initMatrix(2, 2);
    Matrix *m5 = initMatrix(2, 2);
    Matrix *m6 = initMatrix(m4->row, m5->column);
    m4->data = a1[0];
    m5->data = b1[0];
    multiplyMatrix(m4, m5, m6);
    printfMatrix(m6);
    multiplyMatrix(m5, m4, m6);
    printfMatrix(m6);
    free(m4);
    free(m5);
    free(m6);

    return 0;
}

/**
 * 打印矩阵
 * @param m
 */
void printfMatrix(const Matrix *m) {
    if (m == NULL) {
        return;
    }
    for (int i = 0, count = m->row; i < count; i++) {
        for (int j = 0, countColumn = m->column; j < countColumn; j++) {
            int index = i * countColumn + j;
            printf("%d->", m->data[index]);
        }
        printf("\n");
    }
}

/**
 * 初始化矩阵
 * @param row
 * @param column
 * @return
 */
Matrix *initMatrix(int row, int column) {
    Matrix *m = static_cast<Matrix *>(malloc(sizeof(Matrix)));
    m->data = static_cast<int *>(malloc(sizeof(int) * row * column));
    m->row = row;
    m->column = column;
    return m;
}

/**
 * 矩阵加法
 * @param a
 * @param b
 * @param c
 * @return
 */
int addMatrix(struct Matrix *a, struct Matrix *b, struct Matrix *c) {
    if (a == NULL || b == NULL || c == NULL) {
        return -1;
    }

    if (a->row != b->row || a->column != b->column) {
        return -1;
    }

    for (int i = 0, count = a->row; i < count; i++) {
        for (int j = 0, countColumn = a->column; j < countColumn; j++) {
            int index = i * countColumn + j;
            c->data[index] = a->data[index] + b->data[index];
        }
    }
    return 0;
}

/**
 * 矩阵减法
 * @param a
 * @param b
 * @param c
 * @return
 */
int minusMatrix(struct Matrix *a, struct Matrix *b, struct Matrix *c) {
    if (a == NULL || b == NULL || c == NULL) {
        return -1;
    }

    if (a->row != b->row || a->column != b->column) {
        return -1;
    }
    for (int i = 0, count = a->row; i < count; i++) {
        for (int j = 0, countColumn = a->column; j < countColumn; j++) {
            int index = i * countColumn + j;
            c->data[index] = a->data[index] - b->data[index];
        }
    }
    return 0;
}

/**
 * 矩阵乘法
 * @param a
 * @param b
 * @param c
 * @return
 */
int multiplyMatrix(struct Matrix *a, struct Matrix *b, struct Matrix *c) {
    if (c == NULL) {
        return -1;
    }

    if (a == NULL && b == NULL) {
        return -1;
    }

    if (a->row != b->column) {
        return -1;
    }

    if (a == NULL) {
        for (int i = 0, count = b->row; i < count; i++) {
            for (int j = 0, countColumn = b->column; j < countColumn; j++) {
                int index = i * countColumn + j;
                c->data[index] = b->data[index];
            }
        }
        return 0;
    }

    if (b == NULL) {
        for (int i = 0, count = a->row; i < count; i++) {
            for (int j = 0, countColumn = a->column; j < countColumn; j++) {
                int index = i * countColumn + j;
                c->data[index] = a->data[index];
            }
        }
        return 0;
    }

    for (int i = 0, count = a->row; i < count; i++) {
        for (int j = 0, countColumn = b->column; j < countColumn; j++) {
            int sum = 0;
            for (int k = 0, countM = a->column; k < countM; k++) {
                sum += a->data[i * countM + k] * b->data[k * countM + j];
            }
            c->data[i * countColumn + j] = sum;
        }
    }
    return 0;
}

