//
// Created by andylin on 2020/6/22.
//

#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

int arrayNesting(int* nums, int numsSize){
    bool *visited = (bool *)calloc(numsSize, sizeof(bool));
    int res = 0;
    for (int i = 0; i < numsSize; ++i) {
        if(!*(visited+i))
        {
            int start = *(nums+i);
            int count = 0;
            do
            {
                start = *(nums+start);
                count++;
                *(visited+start) = true;
            }
            while(*(nums+i) != start);
            res = (res >= count) ? res : count;
        }
    }
    return res;
}


int main()
{
    int num[] = {5,4,0,3,1,6,2};
    printf("out res is:%d\n",arrayNesting(&num,7));
    return 0;
}