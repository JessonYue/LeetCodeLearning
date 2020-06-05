//
// Created by qianchunzheng on 2020/6/4.
//
#include <iostream>
#include <vector>
using namespace std;
/**
 * 2020.06.4
 * ������ 10.01. �ϲ����������
 * ������������������ A �� B������ A ��ĩ�����㹻�Ļ���ռ����� B�� ��дһ���������� B �ϲ��� A ������
 * ��ʼ�� A �� B ��Ԫ�������ֱ�Ϊ m �� n��
 * ʾ��:
 * ����:
 * A = [1,2,3,0,0,0], m = 3
 * B = [2,5,6],       n = 3
 * ���: [1,2,2,3,5,6]
 * ˵��:
 * A.length == n + m
 */

/**
 * ˼·��
 * ��Ϊ����������Ѿ�����������A��������B�Ŀռ�
 * ��ô�����ǿ��Դ�������β����ʼȡֵ����ȡ���ֵ�����бȽ�
 * ���ݱȽϵĽ��������Ԫ�ش�ŵ�λ��
 */
class Solution{
public:
    void merge(vector<int>& A,int m,vector<int>& B,int n){
        //��ȡ����A�����ֵ��ָ��
        int pointA = m-1;
        //��ȡ����B�����ֵ��ָ��
        int pointB = n-1;

        //��ȡ������Aβ��ָ��
        int length = m + n -1;
        //���ó��������ձȽϵ�ֵ
        int curr;
        while (pointA > 0 || pointB >0){
            if(A[pointA] > B[pointB]){
                curr = A[pointA];
                pointA --;
            }else if(pointA == -1){//����-1��˵������A��ֵ�Ѿ�ȡ���ˣ�ʣ�µ�ȫb��ֵ��
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