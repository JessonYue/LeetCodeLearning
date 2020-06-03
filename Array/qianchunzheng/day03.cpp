//
// Created by qianchunzheng on 2020/6/3.
//
#include <iostream>
using namespace std;


/**
 * ����һ�� haystack �ַ�����һ�� needle �ַ������� haystack
 * �ַ������ҳ� needle �ַ������ֵĵ�һ��λ�� (��0��ʼ)����������ڣ��򷵻�  -1��
 * ʾ�� 1:
 * ����: haystack = "hello", needle = "ll"
 * ���: 2
 * ʾ�� 2:
 * ����: haystack = "aaaaa", needle = "bba"
 * ���: -1
 * ˵��:
 * �� needle �ǿ��ַ���ʱ������Ӧ������ʲôֵ�أ�����һ���������кܺõ����⡣
 * ���ڱ�����ԣ��� needle �ǿ��ַ���ʱ����Ӧ������ 0 ������C���Ե� strstr() �Լ� Java�� indexOf() ���������
 */



/**
 * ˼·��
 * ��ȡ��Ŀ���ַ����ĳ��� length
 * ����haystack��ÿ�λ�ȡlength���ȵ��ַ�����Ŀ���ַ������бȽ�
 */

class Test{
public:
    int getIndex(string haystack,string needle){
        //��needle�ǿյķ���0
        if(needle.empty()){
            return 0;
        }
        //��ȡĿ���ַ�������
        int len = needle.length();
        //�����ַ���
        for (int i = 0; i < haystack.length(); ++i) {
            //�ж���i+len ����haystack�ĳ��ȣ�����Կ϶�haystack������needle
            if((i+len)<= haystack.length()){
                string ss =haystack.substr(i,len);
                if(needle == ss){

                    return i;
                }
            }

        }

        return -1;
    }


};

int main(){
    string haystack = "hello";
    string needle = "ll";

    Test test;
    int i =test.getIndex(haystack,needle);
    cout<<i<<endl;
}

