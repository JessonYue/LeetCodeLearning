class Solution {
    public int numOfSubarrays(int[] arr, int k, int threshold) {
        int sum = k * threshold ;
        int subSum = 0;
        for(int i =0 ;i < k; i++){
            subSum += arr[i];
        }
        int count = 0;
        if(subSum >= sum){
            count = 1;
        }
        for(int j = k; j< arr.length; j++){
            subSum -= arr[j-k];
            subSum += arr[j];
            if(subSum >= sum){
                count ++;
            }

        }
        return count;
    }
}
