
//给你一个整数数组 nums，请你返回其中位数为 偶数 的数字的个数。
int findNumbers(int* nums, int numsSize){
    int result = 0;
    int count;
    for(int i = 0; i<numsSize; i++){
        int num = nums[i];
        count = 0;
        while(num > 0){
            num /= 10;
            count++;
        }
        if(!(count % 2)){
            result++;
        }
    }
    return result;

}

