# Algorithm
数据结构和算法练习

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