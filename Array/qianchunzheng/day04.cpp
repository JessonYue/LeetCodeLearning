//
// Created by qianchunzheng on 2020/6/4.
//
#include <iostream>
#include <vector>
using namespace std;
/**
 * 2020.06.4
 * 面试题 10.01. 合并排序的数组
 * 给定两个排序后的数组 A 和 B，其中 A 的末端有足够的缓冲空间容纳 B。 编写一个方法，将 B 合并入 A 并排序。
 * 初始化 A 和 B 的元素数量分别为 m 和 n。
 * 示例:
 * 输入:
 * A = [1,2,3,0,0,0], m = 3
 * B = [2,5,6],       n = 3
 * 输出: [1,2,2,3,5,6]
 * 说明:
 * A.length == n + m
 */

/**
 * 思路：
 * 因为两个数组均已经排序，且数组A中有容纳B的空间
 * 那么，我们可以从两数组尾部开始取值（即取最大值）进行比较
 * 根据比较的结果，安排元素存放的位置
 */
class Solution{
public:
    void merge(vector<int>& A,int m,vector<int>& B,int n){
        //获取数组A的最大值的指针
        int pointA = m-1;
        //获取数组B的最大值的指针
        int pointB = n-1;

        //获取到数组A尾部指针
        int length = m + n -1;
        //利用常量来接收比较的值
        int curr;
        while (pointA > 0 || pointB >0){
            if(A[pointA] > B[pointB]){
                curr = A[pointA];
                pointA --;
            }else if(pointA == -1){//等于-1，说明数组A的值已经取完了，剩下的全b的值了
                curr = B[pointB];
                pointB --;
            }else if (pointB == -1){
                curr = A[pointA];
                pointA --;
            }else {
                curr = B[pointB];
                pointB --;
            }

            A[length] = curr;
            length--;
        }
        for (int i = 0; i < A.size(); ++i) {
            cout << A[i] << ",";
        }
    }
};

int main(){
    int m = 3;
    int n =3;
    vector <int> vectorA,vectorB;
    vectorA.push_back(1);
    vectorA.push_back(2);
    vectorA.push_back(3);
    vectorA.push_back(0);
    vectorA.push_back(0);
    vectorA.push_back(0);
    vectorB.push_back(2);
    vectorB.push_back(5);
    vectorB.push_back(6);

    Solution solution;
    solution.merge(vectorA, m, vectorB, n);


    return 0;
}