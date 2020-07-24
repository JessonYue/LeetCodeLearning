void moveZeroes(int* nums, int numsSize){
    int j=0;
    for(int i=0;i<numsSize;i++){
        if(nums[i]!=0){
            int temp=nums[i];
            nums[i]=nums[j];
            nums[j++]=temp;
        }
    }
}

void moveZeroes2(int* nums, int numsSize){
    int j=0;
    for(int i=0;i<numsSize;i++){
        if(nums[i]!=0){
            nums[j++]=nums[i];
        }
    }
    for(;j<numsSize;j++){
        nums[j]=0;
    }
}