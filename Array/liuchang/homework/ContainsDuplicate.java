import java.util.Arrays;

public class ContainsDuplicate {

    public static void main(String[] args) {
        System.out.println("=====" + containsDuplicate(new int[]{1, 2, 3, 1}));
    }

    public static boolean containsDuplicate(int[] arr) {
        Arrays.sort(arr);
        for (int i = 0; i < arr.length - 1; ++i) {
            if (arr[i] == arr[i + 1]) return true;
        }
        return false;
    }

}
