public class day28 {

    public static int numOfSubarrays(int arr[], int arrSize, int k, int threshold) {
        int count = 0;
        for (int i = 0; i < arrSize - k + 1; i++) {
            int num = 0;
            for (int j = i; j < i+k; j++) {
                num += arr[j];
            }
            if (num / k >= threshold) {
                count++;
            }
        }
        return count;
    }

    public static void main(String[] args) {
        int datas[] = {2, 2, 2, 2, 5, 5, 5, 8};
        System.out.println("=====" + numOfSubarrays(datas, 8, 3, 4));
    }
}
