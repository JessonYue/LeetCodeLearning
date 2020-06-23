//
// Created by 张俊伟 on 2020/6/22.
//
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <stdio.h>
int arrayNesting(int *nums, int numsSize) {
    bool *visted = (bool *) calloc(numsSize, sizeof(bool));
    assert(visted!=NULL);
    int maxSize = 0;
    for (int i = 0; i < numsSize; ++i) {
        if (!*(visted + i)) {
            int count =0, start = *(nums + i);
            do {
                *(visted + start) = true;
                count++;
                start = *(nums + start);
            } while (start != *(nums + i));
            if (maxSize < count)
                maxSize = count;
        }
    }
    free(visted);
    return maxSize;
}
int main(){
    int nums[] = {5,4,0,3,1,6,2};
  int res = arrayNesting(nums, 7);
  printf("res: %d ",res);
}