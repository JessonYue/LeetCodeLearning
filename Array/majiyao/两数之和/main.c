#include <stdio.h>

void sumArray(int* array, int target);

//1. 两数之和
int main() {
    printf("Hello, World!\n");
    int array[] = {2, 7, 11, 15};
    int target = 9;
    sumArray(array, target);
    return 0;
}

void sumArray(int* array, int target) {
    //获取数组的长度
    int size = sizeof(array) / sizeof(int);
    for (int i = 0; i < size; ++i) {
        //取值
        int a = array[i];
        for (int j = 0; j < size; ++j) {
            int b = array[j];
            if (a != b && a + b == target && i < j){
                printf("index value is %d, %d\n", i+1, j+1);
                break;
            }
        }
    }
}

