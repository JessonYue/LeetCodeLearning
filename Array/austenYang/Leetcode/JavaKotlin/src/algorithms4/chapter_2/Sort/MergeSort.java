package algorithms4.chapter_2.Sort;

/**
 * 归并排序：
 * 要将一个数组排序，可以先将它分成两半排序，然后将结果归并起来。
 */
public class MergeSort {
    private static int[] aux;

    public static void sort(int[] a) {
        aux = new int[a.length];
        sort(a, 0, a.length - 1);
    }

    private static void sort(int[] a, int lo, int hi) {
        if (lo >= hi) return;
        int mid = lo + (hi - lo) / 2;
        sort(a, lo, mid);
        sort(a, mid + 1, hi);
        merge(a, lo, mid, hi);
    }

    /**
     * @param a
     * @param lo
     * @param mid
     * @param hi
     */
    public static void merge(int[] a, int lo, int mid, int hi) {
        int i = lo;
        int j = mid + 1;

        if (hi + 1 - lo >= 0) System.arraycopy(a, lo, aux, lo, hi + 1 - lo);
        for (int k = lo; k <= hi; k++) {
            if (i > mid) a[k] = aux[j++]; // 1.左半部分用尽，
            else if (j > hi) a[k] = aux[i++];// 2. 右半部分用尽
            else if (aux[i] > aux[j]) a[k] = aux[j++];//3.右半部分的当前元素小于左半部分的当前元素
            else a[k] = aux[i++];//4. 左半部分的当前元素 小于 右半部分的当前元素
        }

    }

    public static void main(String[] args) {
        int[] arrays = new int[]{1, 3, 2, 1};
        sort(arrays);
        for (int array : arrays) {
            System.out.println(array);
        }
    }
}
