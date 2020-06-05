public class Homework_004 {

    // 面试题10.01，合并排序数组
    public void homework_004_1001() {
        int m = 3, n = 3;
        int a[] = {1, 2, 3, 0, 0, 0};
        int b[] = {2, 5, 6};
        mergeArray(a, b, m, n);
        System.out.print("[");
        for (int i = 0; i < a.length; i++) {
            System.out.print(" " + a[i] + " ");
        }
        System.out.println("]");
    }

    private void mergeArray(int[] a, int[] b, int m, int n) {
        int i = 0, j = 0, k = a.length - 1, moveA = 0;
        while (i < a.length) {
            if (a[i] <= b[j] && moveA != m) {
                i++;
                moveA++;
            } else {
                while (moveA != m && k > i) {
                    a[k] = a[k - 1];
                    k--;
                }
                a[i++] = b[j++];
                if (j == n) {
                    break;
                }
                k = a.length - 1;
            }
        }
    }
}
