### [面试题 02.02. 返回倒数第 k 个节点](https://leetcode-cn.com/problems/kth-node-from-end-of-list-lcci/)

思路一：

1. 遍历节点共有 length 个节点。
2. 再从头遍历 (length - k + 1) 次，返回当前节点。

**注意边界条件：** 第二次遍历找值是，记录遍历从 i = 1 开始，其实也很好理解。



思路二：

1. 反转链表。
2. 编译返回地 k 个节点。



思路三：

总体思路是可以利用递归，对于链表在递归触底返回时，便可以倒序访问链表。

```java
private int step = 1; 
public int kthToLast(ListNode head, int k) {
		if(head.next == null) head.val;
   	int val = kthToLast(head.next,k);
  	// 大于 = k 就是在倒序的时候第几次访问 ，那么就是要找的书
   	if(step++ >= k){
      return val;
    }else{
      // 不然再找下一个
      return head.val;
    }
 }
```

