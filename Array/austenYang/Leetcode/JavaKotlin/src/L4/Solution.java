package L4;


public class Solution {
    public static double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int n1 = nums1.length;
        int n2 = nums2.length;
        int n = n1 + n2;
        int sim = n / 2;
        int[] array = new int[n];
        boolean isEven = (sim % 2 == 0);

        int p = 0;
        int q = 0;
        int i = 0;
        while (p < n1 || q < n2) {
            int result = 0;
            if (nums1[p] < nums2[q]) {
                result = p;
                p++;
            } else {
                result = q;
                q++;
            }

            array[i] = result;
            if (isEven) {
                if (i == sim) {
                    return array[i];
                }
            } else {
                if (i == sim) {
                    return (array[i - 1] + array[i]) / 2.0;
                }
            }
            i++;
        }
       throw new IllegalArgumentException("");
    }

    public static void main(String[] args) {
        int[] ints1= new int[]{1,2,3};
        int[] ints2 = new int[]{1,2,3};
        double medianSortedArrays = findMedianSortedArrays(ints1, ints2);
        System.out.println(medianSortedArrays);

    }
}
