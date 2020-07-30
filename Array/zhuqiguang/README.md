# Algorithm
数据结构和算法练习

## 收藏的一些github库，参考思路用
* [小浩算法](https://www.geekxh.com/0.0.%E5%AD%A6%E4%B9%A0%E9%A1%BB%E7%9F%A5/01.html)

## 70.爬楼梯
典型的递归问题，解决递归问题的关键
* 1.找到递归的公式
* 2.找出递归的退出条件，防止内存溢出

针对此题，爬楼梯要么是1步，要么是2步，所以递归公式为f(n-1)+f(n-2),当只有一个台阶时,有一种走法，
当有两种台阶时，有两种走法，所以退出条件为f(1)=1和f(2)=2

## [面试题 10.01. 合并排序的数组](https://leetcode-cn.com/problems/sorted-merge-lcci/)

解题思路：

* 开辟新的临时数组tmp,
* 分别为原有两个数组的最后一个index设置指针i和j,
* 如果A[i]<B[j],那么就把A[j]放到tmp，反之，则把A[i]放到tmp，这叫做双指针解法

## [面试题 02.07. 链表相交](https://leetcode-cn.com/problems/intersection-of-two-linked-lists-lcci/)
发现刷题重在思路，这道题首先要确定“链表相交”的概念，链表A和链表B相交与D，那么从D往后的链表都是相同的，
因为他们共用的next指针，假定两个指针分别指向两个链表的头结点，链表A指针从头走到尾，然后再从链表B头开始走，相同的速度，
相同的路径，所以两个链表会相遇

## [206. 反转链表](https://leetcode-cn.com/problems/reverse-linked-list/)
### 首先在刷题前要明白什么是链表
链表是一种天然的动态数据结构，何谓动态，就是可以增加数据，对比数组，数组是静态的，当然此处说的并不是数组的包装函数ArrayList
### 如何理解指针
链表是由n个节点组成的，而节点中包含数据元素和指针，指针指的就是数据元素存放在内存中的地址，那如何将某个数存到该内存上呢？
通过
```
a.next = b
```
表明将a指针指向b,意思是将b放到了叫做a的内存地址上，而
```
b = a.next
```
意思是指将a的内存地址等于b
再看反转链表这道题，引入两个指针pre和cur,pre是新添加指针，作为头结点的前继节点，cur作为当前节点，然后不断遍历当前节点，并将
cur指针指向后继节点，原cur节点作为pre,一直遍历到cur为空

## [21. 合并两个有序链表](https://leetcode-cn.com/problems/merge-two-sorted-lists/)
我咋没想到用递归呢？通过题解中的图就能明白如何解了
### 递归公式
比较两个链表的头结点，如果a小于b,则将a指向剩下的部分，同时a链表后移一位
## 终止条件
如果a为空，则证明a被遍历完全，则返回b

## [19. 删除链表的倒数第N个节点](https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/)
发现链表的题差不多都一个套路
* 创建空的节点作为哨兵或者哑结点指向头结点
* 用两个指针移动
此题就是这样，指针a先移动，当距指针b  n个单位时，同时后移，当a为空时，就证明b移到了需要删除指针的前一个指针

## [328. 奇偶链表](https://leetcode-cn.com/problems/odd-even-linked-list/)
1.一个指针用来指向head,作为奇链表，一个指针作为偶链表，也指向head,
一个指针用来暂存head,作为偶链表的head,然后分别排奇链表，偶链表

2.奇指针的下下指针指向奇数，偶的下下指向偶数

3.循环跳出条件：指针为空时

## [234. 回文链表](https://leetcode-cn.com/problems/palindrome-linked-list/)
1.将链表放到数组里

2.利用首尾两个指针往中间遍历，如果不相等就意味着不是回文

## [225. 用队列实现栈](https://leetcode-cn.com/problems/implement-stack-using-queues/)
首先理解什么是栈，栈是一种操作受限的链表，只能从一头操作数据，这头叫做栈顶
本题可以用两个链表linkedList，一个作为输入，一个作为输出，然后组成栈

## [20. 有效的括号](https://leetcode-cn.com/problems/valid-parentheses/)
遍历字符串，如果是左括号，则将对应的右括号入栈，如果是右括号，则出栈并与当前的字符比对，
如果不相同，则没有对应括号，因为总是成对出现，所以遍历后，如果栈为空，则证明有对应括号

## [面试题 03.04. 化栈为队](https://leetcode-cn.com/problems/implement-queue-using-stacks-lcci/)
首先要明白栈和队列各自的特点，同一段序列存到栈和队列里，输出的顺序是相反的，所以，可以
用两个栈，一个作为输入，一个作为输出，输入的栈先存入数据，然后pop到输出栈中，就可以实现
队列的出对和入队的操作

## [1047. 删除字符串中的所有相邻重复项](https://leetcode-cn.com/problems/remove-all-adjacent-duplicates-in-string/)
可以将字符串存到栈中，然后通过当前字符和栈顶比对，如果相等则出栈

## [565. 数组嵌套](https://leetcode-cn.com/problems/array-nesting/)
遍历数组，将出现过的数据置为-1,并作为循环的终止条件

## [1295. 统计位数为偶数的数字](https://leetcode-cn.com/problems/find-numbers-with-even-number-of-digits/)
遍历数组，统计每个数字位数，为2则为偶数

## [141. 环形链表](https://leetcode-cn.com/problems/linked-list-cycle/)
快指针走两步，慢指针走一步，如果有环，相当于环形跑道，快慢指针会相遇

## [面试题 02.08. 环路检测](https://leetcode-cn.com/problems/linked-list-cycle-lcci/)
暂时不会，先跳过

## [237. 删除链表中的节点](https://leetcode-cn.com/problems/delete-node-in-a-linked-list/)
可以将删除节点之前节点的指针指向删除节点之后之后的节点，但这个问题的难点在于不知道删除节点的之前节点，
所以可以通过将删除节点赋值为之后节点的值，然后删除之后的节点

## [1343. 大小为 K 且平均值大于等于阈值的子数组数目](https://leetcode-cn.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/)
此题掌握关键解法**滑动窗口法**

1.先取前k个数,大于k*threshold则+1

2.然后以k个数为单位不断后移，减去前一个数并加上后一个数，结果大于k*threshold则+1

## [123. 买卖股票的最佳时机 III](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/)
动态规划？先跳过

## [面试题 02.02. 返回倒数第 k 个节点](https://leetcode-cn.com/problems/kth-node-from-end-of-list-lcci/)
看了思路没看实现，自己做出来了，哈哈哈
貌似链表问题的通用思路就是**快慢指针**

1. 将cur先走k步

2. 然后head和cur同步走，cur走到空的时候，head正好走到k

## [109. 有序链表转换二叉搜索树](https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/)
二叉搜索树也叫二叉排序树，规则是每个节点都大于其左子树节点，都小于其右子树节点

1. 对链表使用快慢指针，快指针走两步，慢指针走一步，快指针走到尾节点的时候，慢指针指向中间节点，即可作为二次搜索树
的根节点，此时注意将左链表断开
2. 将原头节点作为左子树，将mid.next作为右子树，递归构建

## [61. 旋转链表](https://leetcode-cn.com/problems/rotate-list/)

1. 将原尾指向原头，组成环
2. 找到n-k%n-1为新尾，n-k%n为新头
3. 断开新尾和新头的指针

## [203. 移除链表元素](https://leetcode-cn.com/problems/remove-linked-list-elements/)
如果删除结点为中间结点，则可以直接将pre指向删除结点的下一个结点，但是如果删除的是头结点呢？
所以需要一个哨兵结点，哨兵结点是空值，只为了便于操作链表

* 从哨兵结点开始不断遍历链表，
    * 如果比对是删除的结点，则pre->next=cur->next;
    * 否则pre=cur;
* 返回哨兵结点->next
> 注意C语言中如何创建对象，其实就是开辟空间，通过malloc(sizeof(需要创建对象的类型))

## [94. 二叉树的中序遍历](https://leetcode-cn.com/problems/binary-tree-inorder-traversal/)
中序遍历指的是先遍历左子树，再遍历根结点，再遍历右子树，即左根右
* 中序遍历二叉搜索树的结果是排序后的结果
### 如何中序遍历
递归是最简单的方法，

```
public  void inorder(TreeNode root) {
    inorder(root.left);
    print(root.val);
    inorder(root.right);
} 
```
但递归是操作系统帮我们自动完成了函数的栈操作，所以尝试非递归方式,
从根结点开始入栈，不断找左子树，直到找到左子树，然后出栈，然后再找右子树

```java
class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> list = new ArrayList<>();
        Stack<TreeNode> stack = new Stack<>();
        while(stack.size() > 0 || root != null) {
            if(root != null) {
                stack.push(root);
                root = root.left;
            }else {
                TreeNode tmp = stack.pop();
                list.add(tmp.val);
                root = tmp.right;
            }
        }
        return list;
    }
}
```
## [1122. 数组的相对排序](https://leetcode-cn.com/problems/relative-sort-array/)
可以用计数排序，搞不太懂，先跳过

## [387. 字符串中的第一个唯一字符](https://leetcode-cn.com/problems/first-unique-character-in-a-string/)
字符“唯一”，保证字符唯一的数据结构想到散列表
1. 将每个字符put进散列表中作为key,出现的次数作为value
2. 重新遍历字符串，字符出现次数为1即表示唯一


## [283. 移动零](https://leetcode-cn.com/problems/move-zeroes/submissions/)
1. 通过指针j来遍历数组，将非0的值移到数组的左边，第一次遍历完后，指针j指向最后一个非0元素
2. 第二次遍历，将指针右边的非0元素全部置为0

## [844. 比较含退格的字符串](https://leetcode-cn.com/problems/backspace-string-compare/)
因为遇到“#”则退回一个字符，很符合栈的弹栈操作，所以此处重构字符串，可以将非“#”的字符入栈，如果是“#”则出栈

## [160. 相交链表](https://leetcode-cn.com/problems/intersection-of-two-linked-lists/)
利用双指针，从各自链表head开始遍历，如果到tail,则指向对方head开始遍历，如果有相交肯定会相遇

```c
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *aP = headA;
    struct ListNode *bP = headB;
    while(aP != bP) {
        aP = aP == NULL?headB:aP->next;
        bP = bP == NULL?headA:bP->next;
    }
    return aP;
}
```

## [146. LRU缓存机制](https://leetcode-cn.com/problems/lru-cache/)
LRU,最近最少使用算法，即如果超出链表的容量，则会将最近最少使用的元素删除，然后插入新元素
java中的实现是LinkedHashMap,实现原理是双向链表，关键方法是
```
protected boolean removeEldestEntry(Map.Entry<K,V> eldest) {
        return false;
    }
```
该方法表示删除缓存策略


