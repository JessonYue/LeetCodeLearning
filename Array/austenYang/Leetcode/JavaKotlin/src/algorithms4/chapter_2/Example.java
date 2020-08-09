package algorithms4.chapter_2;

public class Example {
    public static void sort(Comparable[] a) {

    }

    public static boolean less(Comparable v, Comparable w) {
        return v.compareTo(w) < 0;
    }

    public static void exch(Comparable[] a, int i, int j) {
        Comparable t = a[i];
        a[i] = a[j];
        a[j] = t;
    }

    private static void show(Comparable[] a) {
        for (Comparable comparable : a) {
            System.out.println(a + "--");
        }
        System.out.println();
    }

    /**
     * 从小到大
     *
     * @param a
     * @return
     */
    public static boolean isSort(Comparable[] a) {
        for (int i = 0; i < a.length - 1; i++) {
            if (a[i].compareTo(a[i + 1]) > 0) {
                return false;
            }
        }
        return true;
    }

    public static boolean isSort2(Comparable[] a) {

        for (int i = 1; i < a.length; i++) {
            if (less(a[i],a[i-1])) {
                return false;
            }
        }
        return true;
    }


}
