public class Homework_021 {

    // 大小为 K 且平均值大于等于阈值的子数组数目，LeetCode第1343题
    void homework_021_1343() {
        int[] arr = {2, 2, 2, 2, 5, 5, 5, 8};
        int k = 3, threshold = 4;
        System.out.println(String.format("accord arr num is : %d\n", numOfSubarrays(arr, k, threshold)));
    }

    private int numOfSubarrays(int[] arr, int k, int threshold) {
        if (arr == null || arr.length <= 0 || arr.length < k) {
            return 0;
        }
        int sum = 0, targetSum = k * threshold, count = arr.length - k, accord = 0, left = 0, right = k;
        for (int i = 0; i < k; i++) {
            sum += arr[i];
        }
        if (sum >= targetSum)
            accord++;
        while ((count--) > 0) {
            sum = (sum - arr[left++] + arr[right++]);
            if (sum >= targetSum)
                accord++;
        }
        return accord;
    }
}
