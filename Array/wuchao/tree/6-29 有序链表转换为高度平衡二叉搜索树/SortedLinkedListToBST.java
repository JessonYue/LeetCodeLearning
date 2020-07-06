package com.slow.lib.practice.tree;

/**
 * 升序链表转换为平衡二叉查找树
 * @Author wuchao
 * @Date 2020/6/29-2:19 PM
 * @description
 * @email 329187218@qq.com
 * @see
 */
public class SortedLinkedListToBST {

    public class ListNode {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
    }

    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }

    //方法一
    //1.先用快慢指针定位到链表的中点,算出链表的长度
    //2.由于给定的链表是升序的，跟二叉查找树中序遍历出来的结果是一样的。我们递归的去构建平衡二叉树，需要链表的中点作为根节点。
    //相应的子树的根节点也应该是子链表的中点。这样构建出来的二叉搜索树就必定是高度平衡的。
     private ListNode head;
     public int countSize(ListNode node){
         ListNode slow = node;
         ListNode fast = node;
         int count = 0;
         while(fast!=null&&fast.next!=null){
             slow = slow.next;
             fast = fast.next.next;
             count++;
         }
         if(fast!=null){
             count=count*2+1;
         }else{
             count=2*count;
         }
         return count;
     }

     public TreeNode linkedListToBST(int start,int end){
         if(start>end){
             return null;
         }
         int middle = start + ((end-start)>>1);
         TreeNode left = linkedListToBST(start,middle-1);
         TreeNode root = new TreeNode(this.head.val);
         root.left = left;
         this.head = this.head.next;
         root.right = linkedListToBST(middle+1,end);
         return root;
     }

     public TreeNode sortedListToBST(ListNode head) {
         this.head = head;
         int countSize = countSize(head);
         return linkedListToBST(0,countSize-1);
     }
     //方法2
    //每次获取子链表中间节点作为子树的根节点，递归构建，这样出来的树一定是高度平衡的
    //相比第一个方法，更容易理解，但是效率会低些
    public ListNode getMiddleNode(ListNode head,ListNode tail){
        ListNode slow = head;
        ListNode fast = head;
        while(fast!=tail&&fast.next!=tail){
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }

    public TreeNode toBST(ListNode head,ListNode tail){
        if(head==tail){
            return null;
        }
        ListNode middleNode = getMiddleNode(head,tail);
        TreeNode root = new TreeNode(middleNode.val);
        root.left = toBST(head,middleNode);
        root.right = toBST(middleNode.next,tail);
        return root;
    }

    public TreeNode sortedListToBST(ListNode head) {
        return toBST(head,null);
    }
}
