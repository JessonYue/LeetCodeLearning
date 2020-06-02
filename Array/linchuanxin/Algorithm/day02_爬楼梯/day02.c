#include <stdio.h>


/*
 * 递归
 * */

int climb1(int n){
    if(n == 1 || n == 2){
        return n;
    }else{
        return climb1(n-1)+climb1(n-2);
    }
}

/*
 * 遍历法
 *
 * */
int climb2(int n){
    if(n == 1 || n == 2){
        return n;
    }
    int temp = 0;
    int first = 1;
    int second = 2;
    for (int i = 3; i <= n; i++) {
        temp = first + second;
        first = second;
        second = temp;
    }
    return temp;
}

/*
 *
 * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

注意：给定 n 是一个正整数。
 * */

int main() {
    for (int i = 1; i < 10; i++) {
        //printf("%d\n",climb1(i));
        printf("%d\n",climb2(i));
    }
    return 0;
}


