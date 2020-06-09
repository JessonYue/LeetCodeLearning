package test;

import android.util.Log;


import java.util.NoSuchElementException;

public class SearchBinaryTree {
    //根节点
    public TreeNode root = null;
    int size = 0;


    /**
     * 添加节点
     */
    public TreeNode put(int data) {
        if (root == null) {
            TreeNode node = new TreeNode(data);
            root = node;
            return node;
        }
        TreeNode parent = null;
        TreeNode node = root;
        //找到要放入的位置
        while (node != null) {
            parent = node;
            if (data < node.data) {
                node = node.leftChild;
            } else if (data > node.data) {
                node = node.rightChild;
            } else {//是重复值 就不理会了
                return node;
            }
        }
        //生成一个节点放入
        TreeNode newNode = new TreeNode(data);
        if (data < parent.data) {
            parent.leftChild = newNode;
        } else {
            parent.rightChild = newNode;
        }
        newNode.parent = parent;

        size++;
        return newNode;
    }


    /**
     * 中序遍历
     */
    public void midOrderTraverse(TreeNode root) {
        if (root == null) {
            return;
        }
        //LDR
        midOrderTraverse(root.leftChild);
//        System.out.print("LDR "+root.data+" ");
        Log.e("LDR", root.data + " ");
        midOrderTraverse(root.rightChild);
    }

    /**
     * 查找一个节点
     */
    public TreeNode searchNode(int data) {
        if (root == null) {
            return null;
        }
        TreeNode node = root;
        while (node != null) {
            if (node.data == data) {
                return node;
            } else if (data > node.data) {
                node = node.rightChild;
            } else if (data < node.data) {
                node = node.leftChild;
            }
        }
        return null;
    }


    /**
     * 删除节点
     * 要删除的节点在树上是一定存在的才删除
     */
//    public void delNode(TreeNode node) {
//        if (node == null) {
//            throw new NoSuchElementException();
//        } else {
//            //先得到父亲，方便后面的操作
//            TreeNode parent = node.parent;
//            //1.叶子
//            if (node.leftChild == null && node.rightChild == null) {
//                //特别的情况:1.树上只有一个节点或是空树
//                if (parent == null) {
//                    root = null;
//                } else if (parent.rightChild == node) {
//                    parent.rightChild = null;
//                } else if (parent.leftChild == node) {
//                    parent.leftChild = null;
//                }
//                node.parent = null;
//            } else if (node.leftChild != null && node.rightChild == null) {
//                //2.只有左孩子
//                if (parent == null) {//如果要删除的是根
//                    node.parent = null;
//                    node.leftChild.parent = null;
//                    root = node.leftChild;
//                } else {
//                    if (parent.leftChild == node) {//要删除的节点是父亲的左边
//                        node.leftChild.parent = parent;
//                        parent.leftChild = node.leftChild;
//
//                    } else {//要删除的节点是父亲的右边
//                        node.leftChild.parent = parent;
//                        parent.rightChild = node.leftChild;
//
//                    }
//                    node.parent = null;
//                    node.leftChild = null;
//                }
//
//            } else if (node.leftChild == null && node.rightChild != null) {
//                //3.只有右孩子
//                if (parent == null) {//如果要删除的是根
//                    node.parent = null;
//                    node.rightChild.parent = null;
//                    root = node.rightChild;
//                } else {
//                    if (parent.leftChild == node) {//要删除的节点是父亲的左边
//                        node.rightChild.parent = parent;
//                        parent.leftChild = node.rightChild;
//                    } else {//要删除的节点是父亲的右边
//                        node.rightChild.parent = parent;
//                        parent.rightChild = node.rightChild;
//                    }
//                    node.parent = null;
//                    node.rightChild = null;//zjw
//                }
//            } else {//4。有左右两个孩子
//                if (node.rightChild.leftChild == null) {//1.如果被删除节点的右子树的左子树为空，就直接补上右子树
//                    node.rightChild.leftChild = node.leftChild;//被删除节点的左子树变为 被删除节点右节点的左子树
//                    if (parent == null) {//删除的节点为根节点
//                        root = node.rightChild;
//                    } else {
//                        if (parent.leftChild == node) {
//                            parent.leftChild = node.rightChild;
//                            //
//                        } else {
//                            parent.rightChild = node.rightChild;
//                            //
//                        }
//                        node.rightChild.parent = parent;
//                    }
//                    node.leftChild = null;//zjw
//                    node.rightChild = null;//zjw
//                    node.parent = null;
//                } else {//2.否则就要补上右子树的左子树上最小的一个
//                    TreeNode leftNode = getMinLeftTreeNode(node.rightChild);
//                    //1 将要删除结点的左子树变为 leftNode 的左子树
//                    leftNode.leftChild = node.leftChild;
//                    node.leftChild.parent = leftNode;
//                    //2
//                    TreeNode leftNodeP = leftNode.parent;
//                    leftNodeP.leftChild = leftNode.rightChild;//将 leftNode 的右子树做为 leftNodeP 的左子树 leftNode 与父结点断开
//
//                    //3
//                    leftNode.rightChild = node.rightChild;//将要删除结点的右子树做为 leftNode 的右子树
//                    node.rightChild.parent = leftNode;
//                    //4
//                    if (parent == null) {//要删除的结点为根结点时
//                        root = leftNode;
//                        leftNode.parent = null;//zjw
//                    } else {
//                        if (parent.leftChild == node) {
//                            parent.leftChild = leftNode;
//                            //
//                        } else {
//                            parent.rightChild = leftNode;
//                            //
//                        }
//                        leftNode.parent = parent;
//                    }
//                    //zjw
//                    node.parent = null;
//                    node.leftChild = null;
//                    node.rightChild = null;
//                }
//            }
//            size--;
//        }
//    }

    public void delNode(TreeNode node) {
        if (node == null) {
            throw new NoSuchElementException();
        } else {
            if (node.leftChild != null && node.rightChild != null) {//有左右两个孩子
                TreeNode successor = successor(node);
                node.data = successor.data;
                //node 指向后继节点
                node = successor;
            }
            TreeNode replacement = node.leftChild != null ? node.leftChild : node.rightChild;
            if (replacement != null) {
                replacement.parent = node.parent;
                if (node.parent == null) {
                    //找到的后继为根节点
                    root = replacement;
                } else {
                    if (node.parent.leftChild == node) {
                        node.parent.leftChild = replacement;
                    } else {
                        node.parent.rightChild = replacement;
                    }
                }
                node.parent = node.leftChild = node.rightChild = null;
            }
            else if (node.parent == null) { // 删除的是根节点
                root = null;
            } else { //  要删除的节点是叶子节点 No children. Use self as phantom replacement and unlink.

                if (node.parent != null) {
                    if (node == node.parent.leftChild)
                        node.parent.leftChild = null;
                    else if (node == node.parent.rightChild)
                        node.parent.rightChild = null;
                    node.parent = null;
                }
            }
            size--;
        }

    }

    //查找t结点的后继结点  相当于链表上查找next 结点
    private TreeNode successor(TreeNode t) {
        if (t == null)
            return null;
        else if (t.rightChild != null) {//若t有右孩子
            TreeNode p = t.rightChild;
            while (p.leftChild != null)//在 t 的右子树上 向左下循环查找
                p = p.leftChild;
            return p;
        } else {//若t 没有右孩子
            TreeNode p = t.parent;
            TreeNode ch = t;
            while (p != null && ch == p.rightChild) {//向左上查找
                ch = p;
                p = p.parent;
            }
            return p;
        }
    }

    private TreeNode getMinLeftTreeNode(TreeNode node) {
        TreeNode curRoot = null;
        if (node == null) {
            return null;
        } else {
            curRoot = node;
            while (curRoot.leftChild != null) {
                curRoot = curRoot.leftChild;
            }
        }
        return curRoot;
    }

    //孩子 双亲表示法
    public static class TreeNode {
        int data;
        TreeNode leftChild;
        TreeNode rightChild;
        TreeNode parent;

        public TreeNode(int data) {
            this.data = data;
            this.leftChild = null;
            this.rightChild = null;
            this.parent = null;
        }
    }
}














