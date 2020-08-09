package algorithms4.chapter_2.Sort;

/**
 * 1. 将待排序序列的第一个元素看做有序序列，把第二个元素到最后一个元素当成是未排序序列。
 * 2. 从头到尾依次扫描未排序序列，将扫描到的每个元素插入有序序列的适当位置。
 * （如果待插入的元素与有序序列中的某个元素相等，则将待插入元素插入到相等元素的后面。）
 */
public class InsertSort {

    public static void sort(int[] a) {
        for (int i = 1; i < a.length; i++) {
            for (int j = i; j > 0 && a[j - 1] < a[j]; j--) {
                int t = a[j - 1];
                a[j - 1] = a[j];
                a[j] = t;
            }
        }
    }

    public static void main(String[] args) {
        int[] ints = {1, 3, 2};
        sort(ints);
        for (int anInt : ints) {
            System.out.println(anInt);
        }
    }
}
