package L1343;

public class Solution {

    /**
     * @param arr
     * @param k
     * @param threshold
     * @return
     */
    public int numOfSubarrays1(int[] arr, int k, int threshold) {
        int length = arr.length;
        int count = length - k + 1;
        int number = 0;
        for (int i = 0; i < count; i++) {
            int j = k;
            int sum = 0;
            while (j > 0) {
                sum += arr[i + j - 1];
                j--;
            }
            if ((sum / k) >= threshold) {
                number++;
            }
        }
        return number;

    }

    public int numOfSubarrays2(int[] arr, int k, int threshold) {
        int count = 0;
        for (int i = 0; i < arr.length - k + 1; i++) {
            int sum = 0;
            for (int j = 0; j < k; j++) {
                sum += arr[i + j];
            }
            if (sum / k >= threshold) {
                count++;
            }
        }
        return count;

    }

    /**
     * 滑动窗口
     *
     * @return
     */
    public int numOfSubarrays3(int[] arr, int k, int threshold) {
        int sum = 0, result = 0;
        int sumTarget = k * threshold;
        for (int i = 0; i < k; i++) {
            sum += arr[i];
        }
        int adder = sum - sumTarget;
        if (adder >= 0) {
            result++;
        }
        int pos = k;
        for (int i = 0; i < arr.length - k; i++) {
            adder = adder + arr[pos] - arr[i];
            if (adder >= 0) {
                result++;
            }
            pos++;
        }
        return result;
    }
}
