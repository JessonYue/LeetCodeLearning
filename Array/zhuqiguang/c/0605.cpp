/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
//    if(headA == NULL || headB == NULL) return NULL;
//    struct ListNode *nodeA = headA;
//    struct ListNode *nodeB = headB;
//    while(nodeA != nodeB) {
//        nodeA = nodeA == NULL ? headA : nodeA -> next;
//        nodeB = nodeB == NULL ? headB : nodeB -> next;
//    }
//    return nodeA;
//}