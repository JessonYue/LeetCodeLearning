

public class Solution_06_27 {

   public int numOfSubarrays(int[] arr, int k, int threshold) {
        int num = 0;
        int result = 0; 
        int j = 0,i = 0,index = 0;
        while(i<k){
            num+=arr[i++];
        }
        if(num >= k*threshold){
            result++;
        }
        for(j = i;j < arr.length;j++){
            num= num+arr[j]-arr[index++];
            if(num >= k*threshold){
                result++;
            }
        }
        return result;

}
