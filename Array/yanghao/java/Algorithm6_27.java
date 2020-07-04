package jdbc.mvp;

public class Algorithm6_27 {
	
	public int numOfSubarrays(int[] arr, int k, int threshold) {
		int sum = 0 ,result=0;
	    int sumTarget = k*threshold;
	    for (int i = 0; i < k; i++) {
	        sum += arr[i];
	    }
	    int adder = sum - sumTarget;
	    if (adder >= 0) {
	        result++;
	    }
	    int pos = k;
	    for (int i = 0; i < arr.length-k; i++) {
	        adder = adder+arr[pos]-arr[i];
	        if (adder>=0){
	            result++;
	        }
	        pos++;
	    }
	    return result;
    }
	
}
