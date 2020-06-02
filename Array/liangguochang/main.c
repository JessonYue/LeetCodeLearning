#include <stdio.h>


void getIndex(int *array, int target) {

    int len = sizeof(array);

    for (int i = 0; i < len; ++i) {

        int a = *(array + i);

        for (int j = i; j < len; ++j) {

            int b = *(array + j);

            if (a + b == target) {

                printf("[%d,%d]\n", i + 1, j + 1);

                break;
            }

        }

    }


}


int main() {

    printf("Hello, World!\n");

    int array[] = {2, 7, 11, 15};

    int target = 9;


    getIndex(array, target);


    return 0;

}