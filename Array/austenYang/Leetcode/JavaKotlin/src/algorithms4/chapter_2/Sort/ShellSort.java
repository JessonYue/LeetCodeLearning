package algorithms4.chapter_2.Sort;

public class ShellSort {
    /**
     * 是数组中任意间隔为 h 的元素有序。
     * 这样的数组被称为 h 有序数组
     *
     * @param a
     */
    public static void sort(int[] a) {
        int N = a.length;
        int h = 1;
        while (h < N / 3) h = h * 3 + 1;
        while (h >= 1) {
            for (int i = h; i < N; i++) {
                for (int j = h; j >= h && a[j] < a[j - h]; j = j - h) {
                    int temp = a[j - h];
                    a[j - h] = a[j];
                    a[j] = temp;
                }
            }
            h = h / 3;
        }
    }
}
