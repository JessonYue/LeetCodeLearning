//
// Created by Vashon on 2020/7/27.
//

#include "Homework_005.h"
#include <iostream>

void Homework_005::merge(vector<int> &A, int m, vector<int> &B, int n) {
    if (B.empty())
        return;
    int length = m + n, indexA = 0, indexB = 0, surplusA = m;
    int currLenA = 0;   // 当前数组 A 已经使用的长度
    while (indexA < length && indexB < n) { // 索引越界判断
        while (A[indexA] <= B[indexB] && surplusA)  // 过滤不需要处理的元素
            indexA++, surplusA--;   // A 的索引移动，剩余需要处理的数组 A 的元素个数
        currLenA = indexA + surplusA;   // 得到数组 A 实际归并后的长度
        for (int i = currLenA - 1; i >= indexA; A[i + 1] = A[i], --i);  // 将数组 A 比数组 B 大的元素后移
        A[indexA++] = B[indexB++];
    }
}

void Homework_005::homework_005_1001() {
    vector<int> vectorA, vectorB;
//    vectorA = {1, 2, 3, 0, 0, 0};
//    vectorB = {2, 5, 6};
    vectorA = {2, 0};
    vectorB = {1};
    cout << "VectorA : ";
    for (int i : vectorA) {
        cout << i << " ";
    }
    cout << endl;
    cout << "VectorB : ";
    for (int i : vectorB) {
        cout << i << " ";
    }
    cout << endl;
//    merge(vectorA, 3, vectorB, 3);
    merge(vectorA, 1, vectorB, 1);
    cout << "VectorA : ";
    for (int i : vectorA) {
        cout << i << " ";
    }
    cout << endl;
}