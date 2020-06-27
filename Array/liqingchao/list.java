 // 链表相关
 public static class ListNode {
        int val;
        ListNode next;

        public ListNode(int val) {
            this.val = val;
        }
    }

    public void print(ListNode listNode) {
        while (listNode != null) {
            System.out.print(listNode.val + " ");
            listNode = listNode.next;
        }
    }

 public ListNode reverseListRec(ListNode listNode) {
        if (listNode == null || listNode.next == null) {
            return listNode;
        }
        ListNode reHead = reverseListRec(listNode.next);
        listNode.next.next = listNode;
        listNode.next = null;
        return reHead;
    }

    public ListNode reverseList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode reHead = null;
        ListNode curr = head;
        while (curr != null) {
            ListNode preNode = curr;
            curr = curr.next;
            preNode.next = reHead;
            reHead = preNode;
        }
        return reHead;
    }

    public boolean isPalindrome(ListNode head) {


        return true;
    }

    /**
     * 查找单链表中的倒数第K个结点（k > 0）
     *
     * @param head
     * @param k
     * @return
     */
    public ListNode reGetKthNode(ListNode head, int k) {

        return null;
    }

    public boolean hasCycle(ListNode head) {
        ListNode slow = head;
        ListNode flow = head;

        while (slow != null && slow.next != null) {
            slow = slow.next.next;
            flow = flow.next;
            if (slow == flow) {
                return true;
            }
        }
        return false;
    }

    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if (l1 == null) {
            return l2;
        } else if (l2 == null) {
            return l1;
        } else if (l1.val > l2.val) {
            l2.next = mergeTwoLists(l1, l2.next);
            return l2;
        } else {
            l1.next = mergeTwoLists(l2, l1.next);
            return l1;
        }
    }