#include <iostream>

#define GET_ARRAY_LEN(array, len){len = (sizeof(array) / sizeof(array[0]));}



int* array(int pInt[], int size, int i);

int main() {
    int len;
    int a[] = { 2, 7,11, 15};
    GET_ARRAY_LEN(a, len)
    int * result = array(a, len, 9);
    std::cout << *(result) << std::endl;
    std::cout << *(result+1) << std::endl;
    return 0;
}

int * array(int pInt[], int size_t, int target) {
   static int a[2];
    for (int i = 0; i < size_t; i++) {
        for (int j = i + 1; j < size_t; j++) {
            if (pInt[i] + pInt[j] == target) {
                a[0]=i+1;
                a[1]=j+1;
                return a;
            }

        }
    }
    return 0;
}
