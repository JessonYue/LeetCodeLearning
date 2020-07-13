#include <iostream>
#include <vector>
using namespace std;

int numOfSubarrays(vector<int>& arr,int k,int threshold){
    int ans=0;//记录最终结果
    int sum=0;//记录每个子数组元素和

    for (int i = 0; i < k; ++i) {
        sum += arr[i];
    }
    if(sum >= threshold*k) ans++;

    int len = arr.size();

    for (int j = 0; j < len - k; ++j) {
        sum -= arr[j];
        sum += arr[k+j];
        if(sum >= threshold*k) ans++;
    }
    return ans;
}



/**
 * 字符串反转
 * @param str
 */
void Reverse(char* str){
    char* p=NULL;
    char* q=NULL;

    p=str;
    q=str+strlen(str)-1;
    char a;

    while (p<q){
        a = *p;
        *p=*q;
        *q = a;
        p++;
        q--;
    }

}
//void revstring(char *test)
//{
//    int length = strlen(test);
//    int step = length - 1;
//    char *s1 = test;
//    char *s2 = test + step;
//    char temp;
//    while (s1 < s2)
//    {
//        temp = *s1;
//        *s1 = *s2;
//        *s2 = temp;
//        *s1++;
//        *s2--;
//    }
//}

int CompareBinary(int num){
    int count;
    while(num != 0){
        if(num % 2 == 1){
            count++;
        }
        num /=2;
    }
    return count;
}

int main() {
//    std::cout << "Hello, World!" << std::endl;
//    vector<int> t;
//    t.push_back(2);
//    t.push_back(2);
//    t.push_back(2);
//    t.push_back(2);
//    t.push_back(5);
//    t.push_back(5);
//    t.push_back(5);
//    t.push_back(8);
//    printf("%d", numOfSubarrays(t,3,4));
//char a[12] = "abcdefghigk";
//    revstring(a);
//    Reverse(a);
//printf("%s",a);
printf("%d",CompareBinary(-3));
    return 0;
}
