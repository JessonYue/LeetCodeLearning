int findNumbers(int* nums, int numsSize){
    if(!nums || numsSize <= 0) return 0;
    int count = 0;
    for(int i = 0; i < numsSize; i++) {
        int bitNum = 0;
        int iVal = nums[i];
        do {
            bitNum++;
            iVal = iVal / 10;
        } while(iVal > 0);

        if(bitNum % 2 == 0) count++;
    }
    return count;
}