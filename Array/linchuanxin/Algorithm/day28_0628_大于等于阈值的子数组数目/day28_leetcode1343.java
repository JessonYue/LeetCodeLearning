package day28;

public class day28_leetcode1343 {

    public int numOfSubarrays(int[] arr, int k, int threshold) {

        int standSum = k * threshold;
        int count = 0,sum = 0;

        for (int i = 0; i < k; i++) {
            sum += arr[i];
        }

        if(sum >= standSum)
            count = 1;

        for (int j = k; j < arr.length; j++){
            sum -= arr[j-k];
            sum += arr[j];
            if(sum >= standSum){
                count++;
            }
        }

        return count;

    }
}
