//
// Created by 张俊伟 on 2020/6/30.
//
#include <cstdlib>
#include <iostream>

#define Type int
typedef struct  _matrix{
    int row;//行数
    int col;//列数
    Type **matrix_items;
} Matrix;

//加减乘除操作
typedef void (*callback)(Matrix *result, Matrix matrix1, Matrix matrix2);

//创建矩阵
void matrix_create(Matrix **matrix, int row, int col);

//创建矩阵 by arr
void matrix_create_by(Matrix **matrix, Type arr[], int row, int col);

//销毁 matrix
void matrix_free(Matrix *matrix);

/*** 以下函数会创建 Matrix  不用时 需要调用matrix_free 销毁*/
//矩阵加法 不用时 需要调用matrix_free 销毁
Matrix *matrix_plus(Matrix matrix1, Matrix matrix2);

//矩阵减法
Matrix *matrix_minus(Matrix matrix1, Matrix matrix);

//两个矩阵乘法
Matrix *matrix_multiply(Matrix matrix1, Matrix matrix);

//矩阵与数的乘法
Matrix *matrix_multiply_num(Matrix matrix1, int num);

void matrix_view(Matrix *matrix);

/******************************************************/

void matrix_create(Matrix **matrix, int row, int col) {
    *matrix = static_cast<Matrix *>(malloc(sizeof(Matrix)));
    if (*matrix == nullptr) {
        std::cout << "matrix memory alloc failed" << std::endl;
        return;
    }
    (*matrix)->row = row;
    (*matrix)->col = col;
    (*matrix)->matrix_items = static_cast<Type **>(malloc(sizeof(Type *) * row));
    if ((*matrix)->matrix_items == nullptr) {
        std::cout << "matrix_items memory alloc failed" << std::endl;
        free(matrix);
        return;
    }
    for (int i = 0; i < row; ++i) {
        (*matrix)->matrix_items[i] = static_cast<Type *>(malloc(sizeof(Type) * col));
        if ((*matrix)->matrix_items[i] != nullptr) {
            memset((*matrix)->matrix_items[i], 0, col);
        } else {//内存分配失败时
            std::cout << "matrix_items[%d] memory alloc failed" << i << std::endl;
            for (int j = 0; j <= i; ++j) {
                free((*matrix)->matrix_items[j]);
            }
            free((*matrix)->matrix_items);
            free((*matrix));
            return;
        }
    }
}

void matrix_create_by(Matrix **matrix, Type arr[], int row, int col) {
    matrix_create(matrix, row, col);
    if (matrix != nullptr) {
        int size = row * col;
        for (int k = 0; k < size; ++k) {
            int i = k / col;
            int j = k - i*col;
            (*matrix)->matrix_items[i][j] = arr[k];
        }
    }
}

void matrix_free(Matrix *matrix) {
    if (matrix== nullptr)return;
    int row = matrix->row;
    for (int j = 0; j < row; ++j) {
        free(matrix->matrix_items[j]);
    }
    free(matrix->matrix_items);
    free(matrix);
}

static bool matrix_is_fit_plus_minus(Matrix matrix1, Matrix matrix2) {
    return matrix1.row == matrix2.row && matrix1.col == matrix2.col;
}

void plus(Matrix *matrix, Matrix matrix1, Matrix matrix2) {
    int row = matrix1.row;
    int col = matrix1.col;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            matrix->matrix_items[i][j] = matrix1.matrix_items[i][j] + matrix2.matrix_items[i][j];
        }
    }
}

void minus(Matrix *matrix, Matrix matrix1, Matrix matrix2) {
    int row = matrix1.row;
    int col = matrix1.col;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            matrix->matrix_items[i][j] = matrix1.matrix_items[i][j] - matrix2.matrix_items[i][j];
        }
    }
}

static Matrix *matrix_operation(Matrix matrix1, Matrix matrix2, callback operation) {
    if (!matrix_is_fit_plus_minus(matrix1, matrix2)) {
        std::cout << "两个矩阵 不符合 矩阵加减的操作要求" << std::endl;
        return nullptr;
    }
    Matrix *matrix = nullptr;
    matrix_create(&matrix, matrix1.row, matrix1.col);
    if (matrix != nullptr && operation != nullptr) {
        operation(matrix, matrix1, matrix2);
    }
    return matrix;
}

Matrix *matrix_plus(Matrix matrix1, Matrix matrix2) {
//    if (!matrix_is_fit_plus_minus(matrix1,matrix2))return nullptr;
//    Matrix *matrix;
//    matrix_create(matrix, matrix1.row, matrix1.col);
//    if (matrix!= nullptr){
//        int row =matrix1.row;
//        int col =matrix1.col;
//
//        for (int i = 0; i <row ; ++i) {
//            for (int j = 0; j < col; ++j) {
//                matrix->matrix_items[i][j] = matrix1.matrix_items[i][j]+matrix2.matrix_items[i][j];
//            }
//        }
//    }
//    return matrix;

    return matrix_operation(matrix1, matrix2, plus);
}

Matrix *matrix_minus(Matrix matrix1, Matrix matrix2) {
    return matrix_operation(matrix1, matrix2, minus);
}

void multiply_num(Matrix *matrix, Matrix matrix1, int num) {
    int row = matrix1.row;
    int col = matrix1.col;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            matrix->matrix_items[i][j] = matrix1.matrix_items[i][j] * num;
        }
    }
}

//row 为matrix1.row  col 为matrix2.col
static int cal_row_col(Matrix matrix1, Matrix matrix2, int row, int col) {
    int size = matrix1.col;
    int res = 0;
    for (int i = 0; i < size; ++i) {
//        int m1 = matrix1.matrix_items[row][i];
//        int m2 = matrix2.matrix_items[i][col];
//        res += m1 * m2;
        res += matrix1.matrix_items[row][i] * matrix2.matrix_items[i][col];
    }
    return res;
}

Matrix *matrix_multiply(Matrix matrix1, Matrix matrix2) {
    Matrix *matrix;
    int row = matrix1.row;
    int col = matrix2.col;
    matrix_create(&matrix, row, col);
    if (matrix != nullptr) {
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                matrix->matrix_items[i][j] = cal_row_col(matrix1, matrix2, i, j);
            }
        }
    }
    return matrix;
}


Matrix *matrix_multiply_num(Matrix matrix1, int num) {
    Matrix *matrix;
    matrix_create(&matrix, matrix1.row, matrix1.col);
    if (matrix != nullptr) {
        int row = matrix1.row;
        int col = matrix1.col;

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                matrix->matrix_items[i][j] = matrix1.matrix_items[i][j] * num;
            }
        }
    }
    return matrix;
}

void matrix_view(Matrix *matrix) {
    if (matrix != nullptr) {
        int row = matrix->row;
        int col = matrix->col;
        std::cout << "-------------matrix---------------" << std::endl;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {

                std::cout << matrix->matrix_items[i][j];

            }
            std::cout << " " << std::endl;
        }

    }
}

