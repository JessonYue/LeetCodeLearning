package com.company;

/**
 * 合并排序数组
 * 给定两个排序后的数组 A 和 B，其中 A 的末端有足够的缓冲空间容纳 B。 编写一个方法，将 B 合并入 A 并排序。
 * <p>
 * 初始化 A 和 B 的元素数量分别为 m 和 n。
 * <p>
 * 示例:
 * <p>
 * 输入:
 * A = [1,2,3,0,0,0], m = 3
 * B = [2,5,6],       n = 3
 * <p>
 * 输出: [1,2,2,3,5,6]
 * 说明:
 * <p>
 * A.length == n + m
 * 通过次数24,160提交次数44,278
 * <p>
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/sorted-merge-lcci
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

import java.util.Arrays;

/**
 * 解题思路：
 * 1、可以先申请个容量为m+n的数组，初始化
 * 2、思路一：在循环中对比两个数组的值.以空间换取时间 思路二：将n的数据插入m中，然后m元素向后移动，保持顺序（空间太大）思路三：直接拿着A的空间完
 */
public class _0604 {
    public static void main(String args[]) {
//        int[]A = new int[10];
//        A[0] = 1;
//        A[1] = 3;
//        A[2] = 5;
//        A[3] = 7;
//        A[4] = 9;
//        int[]B = new int[5];
//        B[0] = 2;
//        B[1] = 4;
//        B[2] = 6;
//        B[3] = 8;
//        B[4] = 10;
//        int[]A = new int[7];
//        A[0] = 7;
//        A[1] = 10;
//        A[2] = 15;
//        int[]B = new int[3];
//        B[0] = 2;
//        B[1] = 5;
//        B[2] = 13;
        int[]A = new int[7];
        A[0] = 1;
        A[1] = 2;
        A[2] = 3;
        int[]B = new int[3];
        B[0] = 7;
        B[1] = 10;
        B[2] = 11;
        merge(A,3,B,3);
        printArray(A);
    }

    /**
     *  合并：固定数组要操作的容量，因为尾部可能会有0
     *  1、从固定的最末尾开始插入数据，A和B的元素都从尾部比较，谁大把谁扔进去
     * @param A
     * @param m 其中m表示非默认值数据
     * @param B
     * @param n 其中m表示非默认值数据
     */
    public static void merge(int[] A, int m, int[] B, int n) {
        int a = m-1;
        int b = n-1;
        for (;a>=0 && b>=0;){
            if (A[a]>=B[b]){
                A[a+b+1] = A[a];//因为尾部有足够大的容量插入数据，所以将排序的数据扔到尾部即可
                A[a]=0;//A[a]的数据被拿走了，只剩下垃圾数据，直接设置成默认值即可
                a--;
            }else{
                A[a+b+1] = B[b];
                b--;
            }
        }
        //如果b>0，说明B有剩余，造成这种情况是因为B中的部分数据小于A
        while(b>=0){
            A[b]=B[b--];
        }
        printArray(A);
    }

    /**
     * 此方法不可取，每次都要来一次全局移动，不合适
     * @param A
     */
//    public static void merge(int[] A, int m, int[] B, int n) {
//        int i = 0;
//        int j = 0;
//        m = m+n;
//        System.out.println(i+","+j+" ===");
//        //printArray(A);
//        for (; i < m && j < n; ) {
//            if (A[i]>=B[j] ){
//                //A中留一个空间给B[j]，其它都要往后移动
//                int index = m-1;
//                while(index>i){
//                  A[index] = A[index-1];
//                  index--;
//                }
//                A[index] = B[j];
//                i++;
//                j++;
//                printArray(A);
//                System.out.println("移动一下："+i+" "+j);
//            }else{
//                i++;
//            }
//            System.out.print(i+","+j+" ===");
//            printArray(A);
//        }
//    }
    private static void printArray(int A[]){
        for (int i:A) {
            System.out.print(i+",");
        }
        System.out.println();
    }

}
