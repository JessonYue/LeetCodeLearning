//
// Created by 吴超 on 2020/6/22.
//
int mathMax(int a,int b);
int arrayNesting(int* nums, int numsSize){
    int max = 0;
    for(int i=0;i<numsSize;i++){
        int sItemIndex = i;
        int count = 0;
        while (nums[sItemIndex]!=-1){
            int temp = sItemIndex;
            sItemIndex = nums[sItemIndex];
            nums[temp] = -1;
            count++;
        }
        max = mathMax(count,max);
    }
    return max;
}

int mathMax(int a,int b){
    if(a>b){
        return a;
    }
    return b;
}

