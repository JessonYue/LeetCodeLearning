package algorithms4.chapter_2.Sort;

/**
 * 1. 找到数组中最小的那个元素
 * 2.将它和数组的第一个元素交换位置（如果第一个元素就是最小元素那么它和自己交换）
 * 3.再次，在剩下的元素中找到最小元素，将它与第二元素交换位置，如此反复，直到整个数组排序。
 * <p>
 * 这种方法叫做 选择排序 因为它在不断地选择剩余元素之中的最小者
 */
public class SelectSort {

    public static void sort(int[] a) {
        for (int i = 0; i < a.length; i++) {
            int minIndex = i;
            for (int j = i + 1; j < a.length; j++) {
                if (a[minIndex] > a[j]) {
                    minIndex = j;
                }
            }
            int t = a[i];
            a[i] = a[minIndex];
            a[minIndex] = t;
        }
    }

    public static void main(String[] args) {
        int[] arrays = new int[]{1,2,4,3};
        sort(arrays);
        for (int array : arrays) {
            System.out.println(array);
        }
    }
}
