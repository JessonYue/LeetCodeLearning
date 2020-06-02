public class ExampleUnitTest {
    @Test
    public void addition_isCorrect() {
        System.out.println(jumpPoint(5));//递归实现
        System.out.println(jumpPoint2(5));//非递归实现

    }

    /**
     * 70. 爬楼梯（递归法）
     * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
     *
     * 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
     *
     * 注意：给定 n 是一个正整数。
     *
     * 示例 1：
     *
     * 输入： 2
     * 输出： 2
     * 解释： 有两种方法可以爬到楼顶。
     * 1.  1 阶 + 1 阶
     * 2.  2 阶
     * 示例 2：
     *
     * 输入： 3
     * 输出： 3
     * 解释： 有三种方法可以爬到楼顶。
     * 1.  1 阶 + 1 阶 + 1 阶
     * 2.  1 阶 + 2 阶
     * 3.  2 阶 + 1 阶
     */
    public int jumpPoint(int range){
        if(range<0) {
            return 1;
        }else if(range == 1) {
            return 1;
        }else if(range == 2) {
            return 2;
        } else {
            return jumpPoint(range-1)+jumpPoint(range-2);
        }
    }
    //爬梯子（非递归法）
    public int jumpPoint2(int range){
        if (range == 1 || range == 2) {
            return range;
        }
        int n1 = 1;
        int n2 = 2;
        for(int i = 3; i <= range ; i++) {
            int temp = n2;
            n2 = n1 + n2;
            n1 = temp;
        }
        return n2;

        }
    }

    /**
     * 打印数组
     * @param arr
     */
    public void Sysou(int[] arr){
        for(int i = 0; i < arr.length; i++) {
            System.out.println(arr[i]);
        }
    }

    /**
     * 二分查找
     * @param list
     * @param item
     */
    public void BinarySearch(int[] list, int item){
        int low = 0;
        int high = list.length - 1;
        while (low <= high){
            int mid = (low + high) / 2;
            int guess = list[mid];
            if(guess == item) {
                System.out.println(guess + "的位置为" + mid);
            }
            if(guess > item) {
                high = mid - 1;
            }else {
                low = mid + 1;
            }
        }
    }




}