##### 找出2个链表的焦点

* C++
```c++
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

public: 
     ListNode *reverseList(ListNode *head) {
        if(head == NULL){
            return head;
        }
        ListNode *pre = NULL;
        ListNode *nexts = head->next;
        while(head != NULL){
           head->next = pre;
           pre = head;
           head = nexts;
           nexts = (nexts == NULL ? NULL : nexts->next);
        }
         return pre;
     }
```

* Kotlin
```kotlin
  class ListNode internal constructor(var values: Int) {
      var next: ListNode? = null
  }
  
  fun reverseList(head: ListNode?): ListNode? {
      var listNode:ListNode? = null
      var current = head
      var nexts = current?.next
      while(current!=null){
          current.next = listNode
          listNode = current
          current = nexts
          nexts = nexts?.next
      }
      return listNode
  }  
```

* JAVA
```java
  public class ListNode {
     int val;
     ListNode next;
     ListNode(int x) {
     	val = x;
     }
  }
  
  public ListNode reverseList(ListNode head) {
  	if(head == null){
          return head;
      }
      ListNode list = null
      ListNode nexts = head.next;
      while(head != null){
          head.next = list;
          list =head;
          head = nexts;
          nexts = next.next;
      }
      return list;
  }
```
##### 归并2个有序链表

* C++
```c++
  struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
   
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
      if(l1 == NULL){
          return l2;
      }
      if(l2 == NULL){
          return l1;
      }
      ListNode *prehead = new ListNode(-1);
      ListNode *resultNode = prehead;
      while(l1 && l2){
          if(l1->val < l2->val){
              resultNode->next = l1;
          	l1 = l1->next;
          }else{
           	resultNode->next = l2;   
          	l2 = l2->next;
          }
          resultNode = resultNode->next; 
      }
      if(l1 == NULL){
          resultNode->next = l2;
      }else{
      	resultNode->next = l1;
      }
      
      return prehead->next;
  }
```

* KT
```kotlin
  class ListNode(var `val`: Int) {
     var next: ListNode? = null
  }
  
  fun mergeTwoLists(l1: ListNode?, l2: ListNode?): ListNode? {
      if (l1 == null) return l2
      if (l2 == null) return l1
      var curr1 = l1
      var curr2 = l2
      var resultNode = ListNode(-1)
      var tmp = resultNode
      while (curr1 != null && curr2 != null) {
          if (curr1.`val` < curr2.`val`) {
              tmp.next = curr1
              curr1 = curr1.next
          } else {
              tmp.next = curr2
              curr2 = curr2.next
          }
          tmp = tmp.next!!
      }
      tmp.next = curr1 ?: curr2
      return  resultNode;
  }
```

* Java
```java
  public class ListNode {
     int val;
     ListNode next;
  
     ListNode(int val) {
              this.val = val;
     }
  }
  
  public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
          if(l1 == null) return l2;
          if(l2 == null) return l1;
          ListNode resultNode = new ListNode(-1);
          ListNode temp = resultNode;
          while( l1 != null && l2 !=null){
              if(l1.val<l2.val){
                  temp.next = l1;
                  l1 =l1.next;
              }else{
                  temp.next = l2;
                  l2 =l2.next;
              }
              temp = temp.next;
          }
          temp.next = l1==null?l2:l1;
          return resultNode.next;
      }
```
##### 删除链表中倒数第N个元素
* C++
```c++
  struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
   ListNode removeNthFromEnd(ListNode head, int n) {
   ListNode *dummy = new ListNode(-1);
     dummy->next = head;
     ListNode *quick = dummy;
     ListNode *slow = dummy;
     for (int i = 0; i <= n; i++) {
         quick = quick->next;
     }
     while (quick != NULL) {
         quick = quick->next;
         slow = slow->next;
     }
     slow->next = slow->next->next;
     return dummy->next;
   }
```
* KT

 ```kotlin
fun removeNthFromEnd(head: ListNode?, n: Int): ListNode? {
    var dummy = ListNode(-1)
    dummy.next = head
    var quick = head
    var slow = head
    for (index in 0..n) {
        quick = quick?.next
    }
    while (quick != null) {
        quick = quick?.next
        slow = slow?.next
    }
    slow?.next = slow?.next?.next
    return dummy.next
}
 ```

* Java

​ ```java
     ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        ListNode quick = dummy;
        ListNode slow = dummy;
        for (int i = 0; i <= n; i++) {
            quick = quick.next;
        }
        while (quick != null) {
            quick = quick.next;
            slow = slow.next;
        }
        slow.next = slow.next.next;
        return dummy.next;
    }

```

```