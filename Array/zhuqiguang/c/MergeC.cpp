#include <stdio.h>

void merge(int* A, int ASize, int m, int* B, int BSize, int n){
	int k = m + n - 1;
	int i = m - 1;
	int j = n - 1;
	while(i >=0 && j>= 0) {
		if(A[i] < B[j]) {
			A[k--] = B[j--];
		}else {
			A[k--] = A[i--];
		}
	}
	while(j >= 0) A[k--] = B[j--];
}

int main() {
	int A[] = {1, 2, 3};
	int B[] = {2, 5, 6};
	int m = 3, n= 3;
	merge(A, m, m, B, n, n);
	return 0;
}


