#include <iostream>
#include <vector>

using namespace std;

void mergeArray(vector<int> &A, int m, vector<int> &B, int n);

int main() {
    cout << "Hello, World!" << endl;
    vector<int> A = {1, 2, 3, 0, 0, 0};
    vector<int> B = {2, 5, 6};
    mergeArray(A, 3, B, 3);

    return 0;
}


/**
 * 时间复杂度：O(m+n)O(m+n)
 *  指针移动单调递增，最多移动 m+nm+n 次，因此时间复杂度为 O(m+n)O(m+n)。
 * 空间复杂度：O(m+n)O(m+n)
 *  需要建立长度为 m+nm+n 的中间数组 sorted。
 */
void mergeArray1(vector<int> &A, int m, vector<int> &B, int n) {
    //定义两个指针,指向两个数组
    int pa = 0;
    int pb = 0;
    //定义一个新的数组进行存储
    int sorted[m + n];
    int cur;
    while (pa < m || pb < n) {
        if (pa == m) {
            cur = B[pb++];
        } else if (pb == n) {
            cur = A[pa++];
        } else if (A[pa] < B[pb]) {
            cur = A[pa++];
        } else {
            cur = B[pb++];
        }
        sorted[pa + pb - 1] = cur;
    }

    for (int i = 0; i < m + n; ++i) {
        A[i] = sorted[i];
        cout << "排序后的值为" << A[i] << endl;
    }
}

void mergeArray(vector<int> &A, int m, vector<int> &B, int n) {
    //定义两个指针
    int pa = m - 1;
    int pb = n - 1;
    //定义数组总长度
    int tail = m + n - 1;
    int cur;
    while (pa >= 0 || pb >= 0) {
        if (pa == -1)
            cur = B[pb--];
        else if (pb == -1)
            cur = A[pa--];
        else if (A[pa] > B[pb])
            cur = A[pa--];
        else
            cur = B[pb--];
        A[tail--] = cur;

    }

    for (int i = 0; i < m + n; ++i) {
        cout << "排序后的值：" << A[i] << endl;
    }
}