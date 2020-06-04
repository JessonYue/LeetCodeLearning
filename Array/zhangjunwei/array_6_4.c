/**
    * 2020.06.4
    * 面试题 10.01. 合并排序的数组 //https://leetcode-cn.com/problems/sorted-merge-lcci/
    * 给定两个排序后的数组 A 和 B，其中 A 的末端有足够的缓冲空间容纳 B。 编写一个方法，将 B 合并入 A 并排序。
    * <p>
    * 初始化 A 和 B 的元素数量分别为 m 和 n。
    * <p>
    * 示例:
    * <p>
    * 输入:
    * A = [1,2,3,0,0,0], m = 3
    * B = [2,5,6],       n = 3
    * <p>
    * 输出: [1,2,2,3,5,6]
    * 说明:
    * <p>
    * A.length == n + m
    */
#include <stdio.h>

void mergeArray(int *source, int const *target, int m, int n);

int main() {
    int A[] = {1, 2, 3, 7, 8, 45, 98, 0, 0, 0, 0, 0};
    int B[] = {2, 5, 6, 33, 99};
    int n = sizeof(B) / sizeof(int);
    int m = sizeof(A) / sizeof(int) - n;
    mergeArray(A, B, m, n);
    printf("%p", A);
    return 0;
}

void mergeArray(int *source, int const *target, int m, int n) {
    //利用3个指针
    //比较两数组元素大小  将大值放于 A数组末尾
    //插入数据的指针 指向 A数组的末尾
    int current = m + n - 1, ps = m - 1, pt = n - 1;
    while (ps >= 0 && pt >= 0)
        source[current--] = source[ps] >= target[pt] ? source[ps--] : target[pt--];
    //source 还有数据时
    while (ps >= 0)
        source[current--] = source[ps--];
    //target 还有数据时
    while (pt >= 0)
        source[current--] = target[pt--];
}