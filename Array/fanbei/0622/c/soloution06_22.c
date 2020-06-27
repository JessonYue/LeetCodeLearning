#include <stdio.h>
#include <stdlib.h>

int arrayNesting(int *nums, int length);

//int main() {
//
//    int nums[] = {0, 1, 3, 2, 6, 5, 9, 11, 7, 5};
//    int result = arrayNesting(nums,10);
//    printf("%d",result);
//    return 0;
//
//}

int arrayNesting(int *nums, int length) {

    int result = 0;
    for (int i = 0; i < length; i++) {

        int j = i;
        int count = 0;
        while (*(nums + j) != -1) {
            count++;
            int tmp = *(nums + j);
            *(nums + j) = -1;
            j = tmp;
        }
        if (result < count) {
            result = count;
        }
    }
    return result;
}