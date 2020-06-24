#define MAX(a, b) ((a > b) ? a : b )
int arrayNesting(int* nums, int numsSize){
    int result1=0;
    for(int i=0;i<numsSize;i++) {
        int tmp = i;
        int cyCount = 0;
        while(nums[tmp] != -1) {
            int k = nums[tmp];
            nums[tmp]=-1;
            tmp = k;
            cyCount++;
        }
        result1 = MAX(result1, cyCount);
    }
    return result1;
}