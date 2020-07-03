package com.lanfairy.md.july;

import org.junit.Test;

import java.util.LinkedList;

public class AVLBTree<E extends Comparable<E>> {
    private static final int LH = 1;//左子树深度深  左高
    private static final int RH = -1;//右高
    private static final int EH = 0;//平衡
    private TreeNode<E> root = null;
    int size = 0;

    //左旋
    public void leftRotate(TreeNode<E> t) {
        if (t == null) return;
        TreeNode<E> tr = t.right;
        //tr 占据原来 t 的位置
        tr.parent = t.parent;
        if (t.parent == null) {
            root = tr;
        } else {
            if (t.parent.left == t)
                t.parent.left = tr;
            else
                t.parent.right = tr;
        }

        t.right = tr.left;
        if (tr.left != null)
            tr.left.parent = t;

        tr.left = t;
        t.parent = tr;
    }

    //右旋
    public void rightRotate(TreeNode<E> t) {
        if (t == null) return;

        TreeNode<E> tl = t.left;
        tl.parent = t.parent;
        if (t.parent == null) {
            root = tl;
        } else {
            if (t.parent.left == t)
                t.parent.left = tl;
            else
                t.parent.right = tl;
        }

        TreeNode<E> tlr = tl.right;
        t.left = tlr;
        if (tlr != null)
            tlr.parent = t;
        tl.right = t;
        t.parent = tl;
    }

    public boolean insertElement(E element) {
        if (root == null) {
            root = new TreeNode<E>(element, null);
            size = 1;
            return true;
        }

        TreeNode<E> t = root;
        int cmp = 0;
        Comparable<? super E> e = (Comparable<? super E>) element;
        //找到要插入的点
        TreeNode<E> parent;
        do {
            parent = t;
            cmp = e.compareTo(t.element);
            if (cmp < 0) {
                t = t.left;
            } else if (cmp > 0) {
                t = t.right;
            } else {
                return false;
            }

        } while (t != null);

        TreeNode<E> newNode = new TreeNode<E>(element, parent);
        if (cmp < 0) {
            parent.left = newNode;
        } else {
            parent.right = newNode;
        }
        //节点已经放到了树上
        //检查平衡，回溯查找
        while (parent != null) {
            cmp = e.compareTo(parent.element);
            if (cmp < 0) {
                parent.balance++;
            } else {
                parent.balance--;
            }
            if (parent.balance == 0) {//parent 为平衡 不需要进行平衡调整
                break;
            }

            if (Math.abs(parent.balance) == 2) {
                fixAfterInsertion(parent);
                break;
            } else {
                parent = parent.parent;
            }
        }

        size++;
        return true;
    }

    private void fixAfterInsertion(TreeNode<E> parent) {
        if (parent.balance == 2) {//左边深
            leftBalance(parent);
        }
        if (parent.balance == -2) {//右边深
            rightBalance(parent);
        }
    }

    //左平衡
    public void leftBalance(TreeNode<E> t) {
        TreeNode<E> tl = t.left;
        switch (tl.balance) {
            case LH: //新的结点插入到t的左孩子的左子树中
                t.balance = EH;
                tl.balance = EH;
                rightRotate(t);
                break;
            case RH://新的结点插入到t的左孩子的右子树中
                TreeNode<E> tlr = tl.right;

                switch (tlr.balance) {//3种插入的情况
                    case LH:
                        t.balance = RH;
                        tl.balance = EH;
                        tlr.balance = EH;
                        break;
                    case RH:
                        t.balance = EH;
                        tl.balance = LH;
                        tlr.balance = EH;
                        break;
                    case EH:
                        t.balance = EH;
                        tl.balance = EH;
                        tlr.balance = EH;
                        break;
                }
                leftRotate(tl);//tl左旋
                rightRotate(t);//t 右旋
                break;
        }

    }

    //右平衡操作
    public void rightBalance(TreeNode<E> t) {
        TreeNode<E> tr = t.right;
        switch (tr.balance) {
            case RH: //新的结点插入到t的右孩子的右子树中
                t.balance = EH;
                tr.balance = EH;
                leftRotate(t);
                break;
            case LH://新的结点插入到t的右孩子的左子树中
                TreeNode<E> trl = tr.left;

                switch (tr.balance) {//3种插入的情况
                    case LH:
                        t.balance = EH;
                        tr.balance = RH;
                        trl.balance = EH;
                        break;
                    case RH:
                        t.balance = LH;
                        tr.balance = EH;
                        trl.balance = EH;
                        break;
                    case EH:
                        t.balance = EH;
                        tr.balance = EH;
                        trl.balance = EH;
                        break;
                }
                rightRotate(tr);//tr右旋
                leftRotate(t);//t 左旋
                break;
        }
    }
    public void showAVL(TreeNode<E> root) {
        LinkedList<TreeNode<E>> queue = new LinkedList<>();
        queue.offer(root);
        while (!queue.isEmpty()){
            TreeNode<E> t = queue.poll();
            System.out.println(t.element);
            if (t.left!=null)
                queue.offer(t.left);
            if (t.right!=null)
                queue.offer(t.right);
        }


    }
    public class TreeNode<E extends Comparable<E>> {
        protected E element;
        protected TreeNode<E> parent;
        protected TreeNode<E> left;
        protected TreeNode<E> right;
        protected int balance;//平衡因子

        public TreeNode(E element, TreeNode<E> parent) {
            this.element = element;
            this.parent = parent;
            balance = 0;
            parent = null;
            left = null;
            right = null;
        }


        public E getElement() {
            return element;
        }

        public TreeNode<E> getParent() {
            return parent;
        }

        public TreeNode<E> getLeft() {
            return left;
        }

        public TreeNode<E> getRight() {
            return right;
        }

        public int getBalance() {
            return balance;
        }

        public void setElement(E element) {
            this.element = element;
        }

        public void setParent(TreeNode<E> parent) {
            this.parent = parent;
        }

        public void setLeft(TreeNode<E> left) {
            this.left = left;
        }

        public void setRight(TreeNode<E> right) {
            this.right = right;
        }

        public void setBalance(int balance) {
            this.balance = balance;
        }
    }


    @Test
    public void test(){
        Integer[] nums={5,8,2,0,1,-2};
        AVLBTree<Integer> tree=new AVLBTree<>();
        for(int i=0;i<nums.length;i++){
            tree.insertElement(nums[i]);
        }
        showAVL((TreeNode<E>) tree.root);
    }
}
