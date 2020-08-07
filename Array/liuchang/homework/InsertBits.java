public class InsertBits {

    public static int insertBits(int N, int M, int i, int j) {
        for (int distance = i; distance < j + 1; distance++)
            N = N & Integer.rotateLeft(~1, distance);
        return N | (M << i);
    }

    public static void main(String[] args) {
        System.out.println(insertBits(1024,19,2,6));
    }

}
