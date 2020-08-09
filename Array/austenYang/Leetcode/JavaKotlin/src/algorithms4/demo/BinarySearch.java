package algorithms4.demo;

public class BinarySearch {
    /**
     * @param key   在有序数组中要查找的数字
     * @param array 有序数组
     * @return key 在 a 数组中的索引位置
     */
    public static int rank(int key, int[] array) {
        //
        int lo = 0;
        int hi = array.length - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (key == array[mid]) return mid;
            else if (key < array[mid]) hi = mid - 1;
            else lo = mid + 1;
        }
        return -1;
    }

    public static void main(String[] args) {
        int[] array = new int[]{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18};
        System.out.println(rank(4, array));
        System.out.println(rank(16, array));

    }
}
