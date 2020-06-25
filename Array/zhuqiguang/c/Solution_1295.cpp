int findNumbers(int* nums, int numsSize){
    int digt, i, count = 0;
    for(i =0;i<numsSize;i++){
        digt=0;
        while(nums[i] !=0) {
            digt++;
            nums[i] = nums[i] / 10;
        }
        if(digt % 2 == 0) {
            count++;
        }
    }
    return count;
}