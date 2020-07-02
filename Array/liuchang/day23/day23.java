import java.lang.Math;

public class day23 {

    public static void main(String[] args) {
        int nums[] = {12, 345, 2, 6, 7896};
        System.out.println("=====" + findNumbers(nums, 5));
    }

    public static int findNumbers(int data[], int size) {
        int count = 0;
        for (int i = 0; i < size; ++i) {
            int n = 1;
            while (Math.pow(10, n) < data[i]) {
                n++;
            }
            if (n % 2 == 0) {
                count++;
            }
        }
        return count;
    }
}
