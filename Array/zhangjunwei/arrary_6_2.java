
public class arrary_6_2 {
    @Test
    public void useAppContext() {
        // Context of the app under test.
//        System.out.println("共计 "+climbStairs(0, 5)+" 种");
        int[] res = new int[]{0,0,0};
        System.out.println("共计 "+climbStairs(0, 3, res));
//        for (int i = 0; i < res.length; i++) {
//
//            System.out.println(i+" 共计 "+res[i]);
//        }

    }

/**
 * 2020.06.2
 * 70. 爬楼梯
 * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
 *
 * 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 *
 * 注意：给定 n 是一个正整数。
 *
 * 示例 1：
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
 *
 * （i,n)   i已爬了多少台阶   n 要爬多少台阶
 *
 *                (0,3)
 *            /           \
 *       (1,3)            (2,3)
 *        / \             /    \
 *    (2,3)  (3,3)      (3,3)  (4,3)
 *     /  \
 *  (3.3) (4,3)
 *
 *  从根节点出发  到 每个叶子节点  若 i==n  则是一种可行的爬到楼顶的方案  1
 *  若 i>n 则爬到楼顶的方案不可行  0
 *  采用 LRD  后序遍历二叉树
 */


    public int climbStairs(int i, int n) {
        if (i==n)return 1;
        if (i>n)return 0;
        int left = climbStairs(i+1,n);
        int right = climbStairs(i+2, n);
        return  left+right;
    }


    public int climbStairs(int i, int n, int[] result){
        if (i==n)return 1;
        if (i>n) return 0;
        if (result[i]>0){
            System.out.println(i+" ~~共计 "+result[i]);
            return result[i];
        }

        int left = climbStairs(i+1,n,result);
        int right = climbStairs(i+2, n,result);
        //把从第 i 个台阶到 n 台阶的结果保存下来
        result[i] = left+right;
        System.out.println(i+" 共计 "+result[i]);
        return result[i];
    }

}
