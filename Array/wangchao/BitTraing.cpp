//
// Created by xiaoyaowang on 2020/7/6.
//

#include <stdio.h>


int cout_bit(int n);

int main(){
    printf("二进制中1的个数为---%d", cout_bit(8));
}

/**
 *  统计二级制数中1的个数
 * */
int cout_bit(int n){
    int sum;
    while (n != 0){
        sum++;
        //n&(n-1)就是将低位的1消除掉
        n &= n-1;
    }
    return sum;
}
