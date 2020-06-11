/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* dummy1 = new ListNode(-1);
        ListNode* first = dummy1;
        ListNode* dummy2 = new ListNode(-1);  
        ListNode* second = dummy2;

        int flag = 1;//初始化为奇数
        while(head != nullptr)
        {
            if(flag == 1)
            {
                //奇数
                first->next = head;
                first = head;
                head = head->next;
                flag = 0;
            }
            else if(flag == 0)
            {
				 //偶数
                second->next = head;
                second = head;
                head = head->next;
                flag = 1;
            }
        }

        first->next = dummy2->next;
        second->next = nullptr;
        return dummy1->next;
    }   
};