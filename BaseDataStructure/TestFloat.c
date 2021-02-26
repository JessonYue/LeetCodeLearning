//
// Created by Jesson on 2021/2/9.
//

#include <stdio.h>

void main(){
    int num =9;
    float* pFloat = &num;
    printf("num的数值是%d\n",num);
    printf("pFloat的数值是%p\n",pFloat);

    *pFloat = 9.0;
    printf("num的数值是%d\n",num);
    printf("pFloat的数值是%p\n",pFloat);
}