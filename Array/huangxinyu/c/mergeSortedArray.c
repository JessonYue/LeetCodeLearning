//
// Created by hasee on 2020/6/4.
//

void merge(int *A, int ASize, int m, int *B, int BSize, int n) {
    int cur = m + n - 1;
    int ida = m - 1;
    int idb = n - 1;
    while (ida >= 0 && idb >= 0) {
        A[cur--] = A[ida] >= B[idb] ? A[ida--] : B[idb--];
    }
    while (idb >= 0) {
        A[cur--] = B[idb--];
    }
}