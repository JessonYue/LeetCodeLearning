public class HasAlternatingBits {

    public static boolean hasAlternatingBits(int n) {
        int i = n;
        System.out.println("== before ==" + i);
        System.out.println("== after ==" + (i >> 1));
        while (i != 0) {
            if (i % 2 == 0 && (i >> 1) % 2 == 0) {
                return true;
            } else if (i % 2 == 1 && (i >> 1) % 2 == 1){
                return true;
            } else {
                i = i>>1;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        System.out.println("=====" + hasAlternatingBits(5));
    }
}
