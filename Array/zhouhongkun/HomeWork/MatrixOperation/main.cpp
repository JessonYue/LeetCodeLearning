#include <iostream>
#include <malloc.h>
#include <stdio.h>
#include "Matrix.h"
using namespace std;

Matrix createMatrix(int row, int col, int array[]);
Matrix initMatrix(int row, int col);
Matrix addMatrix(Matrix matrix1, Matrix matrix2);
Matrix subMatrix(Matrix matrix1, Matrix matrix2);
Matrix mulMatrix(Matrix matrix1, Matrix matrix2);
Matrix divMatrix(Matrix matrix1, Matrix matrix2);
Matrix numMulMatrix(Matrix matrix, int num);

/**
 * 创建矩阵
 * @param row
 * @param col
 * @param array
 * @return
 */
Matrix createMatrix(int row, int col, int array[]){
    int **matrixData = (int **)malloc(sizeof(int) * row);
    for(int i=0; i<row; i++){
        matrixData[i] = (int *)malloc(sizeof(int) * col);
    }

    for(int i=0; i<row; i++){
        for(int j=0; j < col; j++){
            matrixData[i][j] = array[i*3 + j];
        }
    }

    Matrix matrix;
    matrix.row = row;
    matrix.col = col;
    matrix.data = matrixData;
    return matrix;
}

/**
 * 初始化矩阵
 * @param row
 * @param col
 * @return
 */
Matrix initMatrix(int row, int col){
    int **matrixData = (int **)malloc(sizeof(int) * row);
    for(int i=0; i<row; i++){
        matrixData[i] = (int *)malloc(sizeof(int) * col);
    }

    for(int i=0; i<row; i++){
        for(int j=0; j < col; j++){
            matrixData[i][j] = 0;
        }
    }

    Matrix matrix;
    matrix.row = row;
    matrix.col = col;
    matrix.data = matrixData;
    return matrix;
}

/**
 *
 * @param matrix1
 * @param matrix2
 * @return
 */
Matrix addMatrix(Matrix matrix1, Matrix matrix2){
    Matrix tmpMatrix = initMatrix(matrix1.row, matrix1.col);
    for(int i=0; i<matrix1.row; i++){
        for(int j=0; j<matrix1.col; j++){
            tmpMatrix.data[i][j] = matrix1.data[i][j] + matrix2.data[i][j];
        }
    }
    return tmpMatrix;
}

/**
 *
 * @param matrix1
 * @param matrix2
 * @return
 */
Matrix subMatrix(Matrix matrix1, Matrix matrix2){
    Matrix tmpMatrix = initMatrix(matrix1.row, matrix1.col);;
    for(int i=0; i<matrix1.row; i++){
        for(int j=0; j<matrix1.col; j++){
            tmpMatrix.data[i][j] = matrix1.data[i][j] - matrix2.data[i][j];
        }
    }
    return tmpMatrix;
}

/**
 *
 * @param matrix1
 * @param matrix2
 * @return
 */
Matrix mulMatrix(Matrix matrix1, Matrix matrix2){
    if(matrix1.col == matrix2.row){
        Matrix tmpMatrix = initMatrix(matrix1.row, matrix2.col);
        for(int i=0; i<matrix1.row; i++){
            for(int j=0; j<matrix1.col; j++){
                for(int k=0; k<matrix2.col; k++){
                    tmpMatrix.data[i][k] += matrix1.data[i][j] * matrix2.data[j][k];
                }
            }
        }
        return tmpMatrix;
    } else {
        cout<<"Errow!!! First Matrix's Col Not Equals Second Matrix's Row..." << endl;
    }
}

/**
 * 矩阵除法
 * @param matrix1
 * @param matrix2
 * @return
 */
Matrix divMatrix(Matrix matrix1, Matrix matrix2){

}

/**
 * 数乘于矩阵
 * @param matrix
 * @param num
 * @return
 */
Matrix numMulMatrix(Matrix matrix, int num){
    Matrix tmpMatrix = initMatrix(matrix.row, matrix.col);
    for(int i=0; i<matrix.row; i++) {
        for (int j = 0; j < matrix.col; j++) {
            tmpMatrix.data[i][j] = matrix.data[i][j] * num;
        }
    }
    return tmpMatrix;
}

/**
 *
 * @param matrix
 */
void printMatrix(Matrix matrix){
    for(int i=0; i<matrix.row; i++){
        for(int j=0; j<matrix.col; j++){
            cout << matrix.data[i][j] << " ";
            if(j == 2){
                cout << endl;
            }
        }
    }
}

int main()
{
    cout<<"******First Matrix******" << endl;
    int array1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Matrix matrix1 = createMatrix(3, 3, array1);
    printMatrix(matrix1);

    cout<<"******Second Matrix******" << endl;
    int array2[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    Matrix matrix2 = createMatrix(3, 3, array2);
    printMatrix(matrix2);

    cout<<"******Add Matrix******" << endl;
    Matrix matrix3 = addMatrix(matrix1, matrix2);
    printMatrix(matrix3);

    cout<<"******Sub Matrix******" << endl;
    Matrix matrix4 = subMatrix(matrix1, matrix2);
    printMatrix(matrix4);

    cout<<"******Mul Matrix******" << endl;
    Matrix matrix5 = mulMatrix(matrix1, matrix2);
    printMatrix(matrix5);

    cout<<"******Num Mul Matrix******" << endl;
    Matrix matrix6 = numMulMatrix(matrix1, 2);
    printMatrix(matrix6);
    return 0;
}

