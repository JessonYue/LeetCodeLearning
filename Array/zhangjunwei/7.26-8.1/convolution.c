
#include <stdio.h>
#include <stdlib.h>

int min(int x, int y) {
    return x < y ? x : y;
}

int max(int x, int y) {
    return x > y ? x : y;
}

void convolution(int *input1, int *input2, int *output, int inlen1, int inlen2) {
    int size = inlen1 + inlen2 - 1;
    int *tmp = (int *) calloc(0, sizeof(int) * size);
    if (tmp == NULL)return;
    for (int i = 0; i < size; ++i) {
        //以位数最少的卷积作为卷积次数
        for (int j = 0; j < min(inlen1, inlen2); ++j) {
            //第一个卷积比第二个卷数积少执行
            if (inlen1 <= inlen2) {
                if (i - j >= 0 && i - j < max(inlen1, inlen2)) {
                    tmp[i] += input1[j] * input2[i - j];
                }
            } else{
                if (i - j >= 0 && i - j < max(inlen1, inlen2)) {
                    tmp[i] += input2[j] * input1[i - j];
                }
            }
        }
    }
    for (int k = 0; k < size; ++k) {
        output[k] = tmp[k];
    }
    free(tmp);
}

int main(){
    int input1[] = {1,2,3,4};
    int input2[] = {1,2,3,4};
    int size = 7;
    int *out = (int *) calloc(0, sizeof(int) * size);
    convolution(input1, input2, out, 4,4);
    printf("卷积结果\n");
    for (int i = 0; i <size; i++)
    {
        printf("%d ", out[i]);
    }
    return 0;
}
