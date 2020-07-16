
//旋转链表   先求出总长度，然后成环，然后遍历解环
struct ListNode* rotateRight(struct ListNode* head, int k) {
  if (k <= 0 || head == NULL) return head;
  int n = 1;
  struct ListNode* p = head;
  while (p->next != NULL) {  // 求长度
    p = p->next;
    n++;
  }
  if (n == k || n == 1)  // 求位置
    return head;
  else if (k > n)
    k = n - (k % n) - 1;
  else
    k = n - k - 1;
  p->next = head;  // 链表成环
  p = head;        // 重新搜索
  while (k > 0) {
    p = p->next;
    k--;
  }
  head = p->next;  
  p->next = NULL;
  return head;
}