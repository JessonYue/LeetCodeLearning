//
// Created by 张佳男 on 2020/6/3.
//

#include <iostream>
#include <cstring>


int * merge(int *A, int ASize, int m, int *B, int BSize, int n) {
   int pa=0,pb=0;//指针起始
   int sorted[m+n];//重新申请数组
   int cur;//缓存值
    while (pa < m || pb < n) {
        if (pa==m) //A已经取完了
            cur=B[pb++];
        else if (pb==n) //B已经取完了
            cur=A[pa++];
        else if (A[pa]<B[pb])//缓存值小一点的值
            cur=A[pa++];//缓存值小一点的值
        else
            cur=B[pb++];//缓存值小一点的值
        sorted[pa+pb-1]=cur;//缓存值从头开始放  因为++了  所以-1
    }
    for (int i = 0; i !=m+n; ++i) {
        A[i]=sorted[i];
    }
}

int main() {
    int  A[] = {1, 2, 3, 0, 0, 0};
    int  B[]  = {2, 5, 6};
    merge(A, sizeof(A) / sizeof(int ), 3, B, sizeof(B) / sizeof(int), 3) ;
    return 0;
}