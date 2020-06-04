#include <iostream>
#include <vector>

using namespace std;

void mergeArray(vector<int> &A, int m, vector<int> &B, int n);

void mergeArray2(vector<int> &A, int m, vector<int> &B, int n);

int main() {
    int m = 3;
    int n = 3;
    int arrA[6] = {1, 2, 3, 0, 0, 0};
    int arrB[3] = {2, 5, 6};
    vector<int> a(arrA, arrA + 6);
    vector<int> b(arrB, arrB + 3);
    mergeArray(a, m, b, n);

    for (int i = 0; i < m + n; ++i) {
        printf("method 1 : i = %d\n", a[i]);
    }

    int arrC[6] = {3, 4, 6, 0, 0, 0};
    int arrD[3] = {2, 7, 8};
    vector<int> c(arrA, arrA + 6);
    vector<int> d(arrB, arrB + 3);

    mergeArray2(c, m, d, n);

    for (int i = 0; i < m + n; ++i) {
        printf("method 2 : i = %d\n", c[i]);
    }

    return 0;
}

/**
 * 方法一思路：把数组B的数组拼接到数组A中，在进行排序
 */
void mergeArray(vector<int> &A, int m, vector<int> &B, int n) {
    for (int i = 0; i < n; i++) {
        A[m + i] = B[i];
    }
    sort(A.begin(), A.end());
}

/**
 * 方法二思路：利用两个数组本身是已经排序好的数组，每次都取两个数组的第一个进行比较，放到新定义的一个数组中，
 * 最后把新定义的数组赋值给数组A
 */
void mergeArray2(vector<int> &A, int m, vector<int> &B, int n) {
    int pa = 0;
    int pb = 0;
    vector<int> C;
    while (pa < m || pb < n) {
        if (pa == m) {
            C.push_back(B[pb++]);
        } else if (pb == n) {
            C.push_back(A[pa++]);
        } else if (A[pa] > B[pb]) {
            C.push_back(B[pb++]);
        } else {
            C.push_back(A[pa++]);
        }
    }
    A = C;
}

