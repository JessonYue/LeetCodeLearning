链表窗口滑动时，并且要建立新的链表时，

当前在窗口中的 结点为 ListNode curNode，要建立虚拟头节点 dummyHead

curNode 的起始值 

就是在链表窗口滑动时，操作是形成新的链表，链表的头应该的 dummyHead.next

起始操作的是 curNode = dummHead.

循环中 ，curNode.next = new ListNode();

curNode = curNode.next;



一些灵感的总结





