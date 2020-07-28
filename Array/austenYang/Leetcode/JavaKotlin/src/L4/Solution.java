package L4;


import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

public class Solution {
    public static double findMedianSortedArrays1(int[] nums1, int[] nums2) {
        ArrayList<Integer> arrayList1 = new ArrayList<>();
        ArrayList<Integer> arrayList2 = new ArrayList<>();
        for (int item : nums1) {
            arrayList1.add(item);

        }
        for (int value : nums2) {
            arrayList2.add(value);
        }

        arrayList1.addAll(arrayList2);
        arrayList1.sort((o1, o2) -> o2 - o1);
        int size = arrayList1.size();
        int sim = size / 2;
        boolean isEven = size % 2 == 0;
        if (isEven) {
            return (arrayList1.get(sim) + arrayList1.get(sim - 1)) / 2.0;
        } else {
            return arrayList1.get(sim);
        }

    }

    public static double findMedianSortedArrays2(int[] nums1, int[] nums2) {

        int p = 0;
        int q = 0;
        int l1 = nums1.length;
        int l2 = nums2.length;
        int n = l1 + l2;
        int curIndex = 0;
        int[] array = new int[n];
        while (p < l1 && q < l2) {
            array[curIndex++] = nums1[p] < nums2[q] ? nums1[p++] : nums2[q++];
        }

        if (p < l1) System.arraycopy(nums1, p, array, curIndex, l1 - p);
        if (q < l2) System.arraycopy(nums2, q, array, curIndex, l2 - q);

        boolean isEven = n % 2 == 0;
        if (isEven) return (array[n / 2 - 1] + array[n / 2]) / 2.0;
        else return array[n / 2];
    }





    public static void main(String[] args) {
        int[] ints1 = new int[]{1, 2};
        int[] ints2 = new int[]{3, 4};
        System.out.println(findMedianSortedArrays1(ints1, ints2));
        System.out.println(findMedianSortedArrays2(ints1, ints2));


    }
}
