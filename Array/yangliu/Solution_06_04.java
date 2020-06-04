import java.lang.reflect.Array;
import java.util.Arrays;

public class Solution_06_04 {
    public static void main(String[] args) {
        int A[] = {1, 2, 3, 0, 0, 0};
        int B[] = {2, 5, 6};

        int C[] = getArray(A, B);
    }

    private static int[] getArray(int[] a, int[] b) {
        int aLength = a.length;

        for (int i = 0; i < b.length; i++) {
            a[aLength - i - 1] = b[i];
        }


        for (int i = 0; i < aLength; i++) {
            for (int j = i + 1; j <aLength; j++) {
                if (a[i] > a[j]) {
                    int tem = a[j];
                    a[j] = a[i];
                    a[i] = tem;
                }
            }

        }

        return a;
    }

}
