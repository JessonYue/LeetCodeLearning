/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


bool isPalindrome(struct ListNode* head){
    if(head==NULL){
        return true;
    }
struct ListNode* fast = head;
struct	ListNode* slow = head;

//快慢指针
	while(fast->next!=NULL && fast->next->next !=NULL){
		fast = fast->next->next;
		slow = slow->next;
	}
struct	ListNode* firstHalfEnd = slow;
//反转 
struct	ListNode* pre = NULL;
struct	ListNode* curr = firstHalfEnd->next;

	while(curr!=NULL){
		struct ListNode* TMP = curr->next;
		curr->next = pre;
		pre = curr;
		curr = TMP;
	}
	struct ListNode* seconHalfStart = pre;


	//对比

	struct ListNode *p1 = head;
	struct ListNode *p2 = seconHalfStart;
	bool result = true;
	while(result && p2!=NULL){
		if(p1->val != p2->val){
			result=false;
		}
		p1 = p1->next;
		p2 = p2->next;
 	}

 return result;
}
