package com.test.ktapplication;


import android.util.Log;

public class Main {

    void main() {

        int[] a = {2, 2, 2, 2, 5, 5, 5, 8};
        int result = numOfSubarrays(a, 3, 4);
        Log.e("result is", result + "");
    }

    public int numOfSubarrays(int[] arr, int k, int threshold) {
        int length = arr.length;
        int sum = 0;
        int count = 0;
        for (int i = 0; i < k; i++) {
            sum += arr[i];
        }
        if (sum >= k * threshold) {
            count++;
        }
        if (k == length) {
            return count;
        }
        for (int j = 0; j < length - k; j++) {
            sum -= arr[j];
            sum += arr[j + k];
            if (sum >= k * threshold) {
                count++;
            }
        }
        return count;
    }

}
