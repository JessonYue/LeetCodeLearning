package algorithms4.chapter_2.Sort;

public class QuickSort {
    public static void sort(int[] a) {

    }

    private static void sort(int[] a, int lo, int hi) {
        if (hi >= lo) return;
        int j = partition(a, lo, hi);
        sort(a, lo, j - 1);
        sort(a, j + 1, hi);
    }

    /**
     * 快速排序的切分 函数
     * 1. 对于某个 j, a[j] 已经排定
     * 2. a[lo] 到 a[j - 1] 中所有的元素都小于 a[j]
     * 3. a[j + 1] 到 a[hi] 中所有的元素都大于 a[j]
     */
    private static int partition(int[] a, int lo, int hi) {
        int i = lo, j = hi + 1;
        int v = a[lo];
        while (true) {
            while (a[++i] < v) if (i == hi) break;
            while (a[--j] > v) if (j == lo) break;
            if (i >= j) break;
            swap(a, i, j);
        }
        swap(a, lo, j);
        return j;
    }

    private static void swap(int[] a, int i, int j) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    public static void main(String[] args) {

    }
}
