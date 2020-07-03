//
// Created by LCX on 2020/7/1.
//
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct {
    int line;//行
    int row;//列
    int *data;
}Matirx;

//初始化
Matirx* initMatirx(Matirx *matirx,int line,int row);
//赋值
void inputMatirxValue(Matirx *matirx,int *array);
//获取矩阵大小
int getMatirxSize(Matirx *matirx);
//释放
void freeMatirx(Matirx *matirx);
//打印
void printMatirx(Matirx *matirx);
//加
Matirx* add(Matirx *matirx1,Matirx *matirx2);
//减
Matirx* subtract(Matirx *matirx1,Matirx *matirx2);
//乘
Matirx* multiply(Matirx *matirx1,Matirx *matirx2);
//除
Matirx* divide(Matirx *matirx1,Matirx *matirx2);

Matirx* initMatirx(Matirx *matirx,int line,int row)
{
    if(line>0 && row>0)
    {
        matirx = (Matirx*)malloc(sizeof(matirx));
        matirx->line = line;
        matirx->row = line;
        matirx->data = (int*)malloc(sizeof(int)*line*row);
        return matirx;
    }
    else
    {
        return NULL;
    }
}

void inputMatirxValue(Matirx *matirx,int *array)
{
    if(matirx->data!=NULL)
        memcpy(matirx->data,array,matirx->row*matirx->line*sizeof(int));
}

int getMatirxSize(Matirx *matirx)
{
    return matirx->line*matirx->row;
}


void freeMatirx(Matirx *matirx)
{
    free(matirx->data);
    free(matirx);
}

void printMatirx(Matirx *matirx)
{
    for (int i = 0; i < getMatirxSize(matirx); ++i) {
        printf("%d ",matirx->data[i]);
        if ((i+1)%matirx->line == 0)
            printf("\n");
    }
}

//矩阵加法
Matirx* add(Matirx *matirx1,Matirx *matirx2)
{
    if((matirx1->line==matirx2->line)&&(matirx1->row==matirx2->row))
    {
        Matirx *resMatirx;
        resMatirx = initMatirx(resMatirx,matirx1->line,matirx1->row);
        for (int i = 0; i < getMatirxSize(matirx1); ++i) {
            resMatirx->data[i] = matirx1->data[i]+matirx2->data[i];
        }
        return resMatirx;
    }
    return NULL;
}

//矩阵减法
Matirx* subtract(Matirx *matirx1,Matirx *matirx2)
{
    if((matirx1->line==matirx2->line)&&(matirx1->row==matirx2->row))
    {
        Matirx *resMatirx;
        resMatirx = initMatirx(resMatirx,matirx1->line,matirx1->row);
        for (int i = 0; i < getMatirxSize(matirx1); ++i) {
            resMatirx->data[i] = matirx1->data[i]-matirx2->data[i];
        }
        return resMatirx;
    }
    return NULL;
}

//矩阵乘法
Matirx* multiply(Matirx *matirx1,Matirx *matirx2)
{
    //左矩阵的列数等于右矩阵的行数才有意义
    if(matirx1->row == matirx2->line){
        Matirx *resMatirx;
        resMatirx = initMatirx(resMatirx,matirx1->line,matirx2->row);
        for (int i=0;i<matirx1->row;i++)
        {
            for (int j=0;j<matirx2->line;j++)
            {
                for (int k=0;k<matirx1->line;k++)
                {
                    resMatirx->data[i*resMatirx->line + j] = resMatirx->data[i*resMatirx->line + j]+
                            matirx1->data[i*matirx1->line + k] * matirx2->data[k*matirx2->row + j];
                }
            }
        }
        return resMatirx;
    }
    return NULL;
}

int main(void)
{
    int value[] = {1,2,3,4,5,6,7,8,9};
    int value2[] = {9,8,7,6,5,4,3,2,10};
    Matirx *matirx1;
    Matirx *matirx2;
    matirx1 = initMatirx(matirx1,3,3);
    matirx2 = initMatirx(matirx2,3,3);
    inputMatirxValue(matirx1,value);
    inputMatirxValue(matirx2,value2);
    printMatirx(matirx1);
    printf("------------\n");
    printMatirx(matirx2);
    printf("-------jia-----\n");
    Matirx *add_res = add(matirx1,matirx2);
    printMatirx(add_res);
    printf("-------jian-----\n");
    Matirx *sub_res = subtract(matirx1,matirx2);
    printMatirx(sub_res);
    printf("-------cheng-----\n");
    Matirx *mul_res = multiply(matirx1,matirx2);
    printMatirx(mul_res);
    return 0;
}





