```
面试题 02.02. 返回倒数第 k 个节点
难度
简单

实现一种算法，找出单向链表中倒数第 k 个节点。返回该节点的值。

注意：本题相对原题稍作改动

示例：

输入： 1->2->3->4->5 和 k = 2
输出： 4
说明：

给定的 k 保证是有效的。
```



#### C

```c
// 方式一
int kthToLast(struct ListNode *head, int k) {
    struct ListNode *slow_pointer, *fast_pointer;
    fast_pointer = head;
    slow_pointer = head;
    int size = 0;
    while (fast_pointer != NULL && slow_pointer != NULL) {
        fast_pointer = fast_pointer->next;
        if (++size > k){
            slow_pointer = slow_pointer->next;
        }
    }
    return slow_pointer->val;
}

// 方式二
// 先走 k 部，然后再让 t 和 head 同步，head 到结尾，t 到目标，双指针变形
int kthToLast(struct ListNode *head, int k) {
  struct ListNode*t = head;
	while (k--){
		t = t->next;
	}
	while (t){
		t = t->next;
		head = head->next;
	}
	return head->val;
}
```

