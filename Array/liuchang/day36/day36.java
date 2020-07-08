public class day36 {


    public static int count4One(int num) {
        int tmp, count = 0;
        while (num != 0) {
            tmp = num & 1;
            if (tmp == 1)
                count++;
            num = num >> 1;
        }
        return count;
    }

    public static void main(String[] args) {
        System.out.println( count4One(15));
    }
}
