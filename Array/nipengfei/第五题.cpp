//理解力扣的答案，默写出来的
class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode *ha = headA, *hb = headB;
		////链表指针总会相遇，一种是相交，一种不相交但都指向null
		while (ha != hb) {
			//如果ha为空，则到链表尾部，将其指向headB的头,否则继续指下去
			ha = ha ? ha->next : headB;
			hb = hb ? hb->next : headA;
		}
		return ha;
	};
};