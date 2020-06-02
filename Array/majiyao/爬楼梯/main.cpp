#include <iostream>

using namespace std;

int climbStairs(int n);

int main() {
    cout << "Hello, World!" << endl;

    int number = 15;
    int value = climbStairs(number);
    cout << "返回值为："<< value << endl;
    return 0;
}

int climbStairs(int n) {

    if( n == 0 || n == 1 || n == 2){
        return n;
    }
    int num[] = {1,2};
    for (int i = 2; i < n; ++i) {
        num[i] = num[i-1] + num[i-2];
        cout << "当前值为：" << num[i] <<endl;
    }

    return num[n-1];

}
