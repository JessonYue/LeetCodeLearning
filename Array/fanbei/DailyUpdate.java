package com.example.coordinatorlayoutdemo;

import org.junit.Test;
import static org.junit.Assert.*;


public class ExampleUnitTest {
    // @Test
    // public void addition_isCorrect() {
        
    //     //第一天的暂时没想法，后面会补上.
    //     ClimbStairs climbStairs = new ClimbStairs();//第二天(0602)
    //     System.out.println(climbStairs.get(6));

    // }

     /**
     * 2020.06.1
     * 167. 两数之和 II - 输入有序数组
     * 给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。
     * 函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。
     * 说明:
     * 返回的下标值（index1 和 index2）不是从零开始的。
     * 你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
     * 示例:
     * 输入: numbers = [2, 7, 11, 15], target = 9
     * 输出: [0,1]
     * 解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2。
     */

    /**
     *
     * @param array 数组
     * @param target 目标值
     * @return
     */
    private int[] fetchingArrayIndex(int[] array,int target) {

        int[] defaultValue ={-1,-1};

        for (int i=0;i<array.length-1;i++) {
            for (int j=i+1;j<array.length;j++){
                 if(array[i]+array[j]==target){
                      defaultValue[0] = array[i];
                      defaultValue[1] = array[j];
                      break;
                 }
            }
        }
        return defaultValue;
    }

    /**
     * 2020.06.2
     * 70. 爬楼梯
     * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
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
    public class ClimbStairs {
        private int get(int total) {
            if (total <= 0) {
                return 0;
            }
            if (total == 1) {
                return 1;
            }
            if (total == 2) {
                return 2;
            }
            return get(total - 1)  + get(total - 2);
        }
    }

     /**
     * 2020.06.3
     * 28. 实现 strStr() //https://leetcode-cn.com/problems/implement-strstr/
     * 实现 strStr() 函数。
     * <p>
     * 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。
     * <p>
     * 示例 1:
     * <p>
     * 输入: haystack = "hello", needle = "ll"
     * 输出: 2
     * 示例 2:
     * <p>
     * 输入: haystack = "aaaaa", needle = "bba"
     * 输出: -1
     * 说明:
     * <p>
     * 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
     * <p>
     * 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
     *
     */
    private static int findStringIndex(String haystack, String needle) {
        char[] needFindChar = needle.toCharArray();
        int target = -1;
        if (needle == null || needle.equals("")) {
            return 0;
        }
        for (int i = 0; i <= haystack.length() - needFindChar.length; i++) {
            if (haystack.charAt(i) != needFindChar[0]) {
                while (++i <= haystack.length() && haystack.charAt(i) != needFindChar[0]) ;
            }
            if (i < haystack.length()) {
                int j = i + 1;
                int end = j + needFindChar.length - 1;
                for (int k = 1; j < end && haystack.charAt(j) == needFindChar[k]; k++, j++) ;
                if (j == end) {
                    return i;
                }
            }
        }
        return target;
    }

    /**
     * 2020.06.4
     * 面试题 10.01. 合并排序的数组 //https://leetcode-cn.com/problems/sorted-merge-lcci/
     * 给定两个排序后的数组 A 和 B，其中 A 的末端有足够的缓冲空间容纳 B。 编写一个方法，将 B 合并入 A 并排序。
     * <p>
     * 初始化 A 和 B 的元素数量分别为 m 和 n。
     * <p>
     * 示例:
     * <p>
     * 输入:
     * A = [1,2,3,0,0,0], m = 3
     * B = [2,5,6],       n = 3
     * <p>
     * 输出: [1,2,2,3,5,6]
     * 说明:
     * <p>
     * A.length == n + m
     */
    private int[] onMergeArray(int[] a, int[] b, int m, int n) {
        int i = 0, j = 0, k = a.length - 1, moveA = 0;
        while (i < a.length) {
            if (a[i] <= b[j] && moveA != m) {
                i++;
                moveA++;
            } else {
                while (moveA != m && k > i) {
                    a[k] = a[k - 1];
                    k--;
                }
                a[i++] = b[j++];
                if (j == n) {
                    break;
                }
                k = a.length - 1;
            }
        }
        return a;
    }

 /**
     * 2020.06.5
     * 面试题 02.07. 链表相交 //https://leetcode-cn.com/problems/intersection-of-two-linked-lists-lcci/
     * 给定两个（单向）链表，判定它们是否相交并返回交点。请注意相交的定义基于节点的引用，而不是基于节点的值。
     * 换句话说，如果一个链表的第k个节点与另一个链表的第j个节点是同一节点（引用完全相同），则这两个链表相交。
     * 示例 1：
     * 输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
     * 输出：Reference of the node with value = 8
     * 输入解释：相交节点的值为 8 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，
     * 链表 A 为 [4,1,8,4,5]，链表 B 为 [5,0,1,8,4,5]。在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。
     * <p>
     * 示例 2：
     * 输入：intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
     * 输出：Reference of the node with value = 2
     * 输入解释：相交节点的值为 2 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [0,9,1,2,4]
     * 链表 B 为 [3,2,4]。在 A 中，相交节点前有 3 个节点；在 B 中，相交节点前有 1 个节点。
     * <p>
     * 示例 3：
     * 输入：intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
     * 输出：null
     * 输入解释：从各自的表头开始算起，链表 A 为 [2,6,4]，链表 B 为 [1,5]。由于这两个链表不相交，
     * 所以 intersectVal 必须为 0，而 skipA 和 skipB 可以是任意值。
     * 解释：这两个链表不相交，因此返回 null。
     * 注意：
     * 如果两个链表没有交点，返回 null 。
     * 在返回结果后，两个链表仍须保持原有的结构。
     * 可假定整个链表结构中没有循环。
     * 程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。
     */

    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if (headA == null || headB == null) return null;
        ListNode a = headA;
        ListNode b = headB;
        /**
         * 思路：a+b的路径与b+a的路径相等；
         *      所以在第二遍的时候，
         *      如果有相交的点，则a==b的时候，就是该节点；
         *      如果没有相交的点，则a和b在第二遍跑完的时候，会同时为null，也满足 a==b 的条件，跳出循环，返回的a=null
         */
        while (a != b) {
            if (a != null) {
                a = a.next;
            } else {
                a = headB;
            }
            if (b != null) {
                b = b.next;
            } else {
                b = headA;
            }
        }
        return a;
    }

    public class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
            next = null;
        }
    }

    /**
     * 2020.06.8
     * 链表反转
     *
     * @param head
     * @return
     */
    public ListNode reverseList(ListNode head) {
        ListNode prev = null;
        ListNode current = head;
        while (current != null) {
            ListNode nextTemp = current.next;
            current.next = prev;
            prev = current;
            current = nextTemp;
        }
        return prev;
    }

    public class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
            next = null;
        }
    }

}