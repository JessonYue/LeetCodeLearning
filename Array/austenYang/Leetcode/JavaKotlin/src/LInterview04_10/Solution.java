package LInterview04_10;


import Base.TreeNode;

public class Solution {

    public static boolean checkSubTree(TreeNode t1, TreeNode t2) {
        if(t1 == null && t2 == null){
            return true;
        }
        if (t1 == null || t2 == null) return t2 == null;
        return isSub(t1,t2) || checkSubTree(t1.left,t2) || checkSubTree(t1.right,t2);
    }

    private static boolean isSub(TreeNode node1, TreeNode node2){
        if (node2 == null){
            return true;
        }
        if (node1 == null){
            return false;
        }

        if (node1.val != node2.val){
            return false;
        }
        return isSub(node1.left,node2.left) && isSub(node1.right,node2.right);
    }


    public static void main(String[] args) {

    }

}
