public class ExampleUnitTest {
    @Test
    public void addition_isCorrect() {
        int[] A = new int[]{1,2,3,0,0,0};
        int[] B = new int[]{2,5,6};
        Sysou(sortAdd(A,3, B,3));
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
     * 2020.06.4
     * 面试题 10.01. 合并排序的数组 //https://leetcode-cn.com/problems/sorted-merge-lcci/
     * 给定两个排序后的数组 A 和 B，其中 A 的末端有足够的缓冲空间容纳 B。 编写一个方法，将 B 合并入 A 并排序。
     *
     * 初始化 A 和 B 的元素数量分别为 m 和 n。
     *
     * 示例:
     *
     * 输入:
     * A = [1,2,3,0,0,0], m = 3
     * B = [2,5,6],       n = 3
     *
     * 输出: [1,2,2,3,5,6]
     * 说明:
     *
     * A.length == n + m
     * @param first
     * @param second
     * @return
     */
    public int[] sortAdd(int[] first,int length1,int[] second,int length2){
        if(second.length == 0) {
            return first;
        }
        int sum[] = new int[length1+length2];
        int i = 0,j = 0,current = 0;
        while (i<length1||j<length2){
            if(i==length1) {
                current = second[j];
                j++;
            }
            else if(j==length2) {
                current = first[i];
                i++;
            }
            else if(first[i]<second[j]) {
                current = first[i];
                i++;
            }
            else {
                current = second[j];
                j++;
            }
            sum[i+j-1] = current;
        }
        for(int i1 = 0; i1< length1+length2 ; i1++) {
            first[i1] = sum[i1];
        }
        return first;

    }



}