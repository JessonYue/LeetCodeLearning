#include<stdlib.h>
int comp(const void*a,const void*b)//用来做比较的函数。
{
    return *(int*)a-*(int*)b;
}

void merge(int* A, int ASize, int m, int* B, int BSize, int n){
for(int i = 0;i<n;i++){
	A[m+i]=B[i];
}
qsort(A,m+n,sizeof(int),comp);//调用qsort排序
}



