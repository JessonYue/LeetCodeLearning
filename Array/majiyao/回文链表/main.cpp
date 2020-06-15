#include <iostream>

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) :val(x), next(NULL){}
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL)
            return true;
        //定义快慢指针
        ListNode *fast = head->next;
        ListNode *slow = head;
        while (fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;//每次走两步
            slow = slow->next;//每次走一步
        }
        /**
         * 当fast指针走到最后的时候，此时slow指针正好走到链表的中间位置
         * 此时slow指向的位置正好是需要断开的位置，此时需要将slow指针的next节点指向nullptr,
         * 然后反转后半部分的链表，与前面的链表进行对比
         */
        ListNode *temp;
        ListNode *p = slow->next;
        ListNode *pre = nullptr;
        //将链表断开
        slow->next = nullptr;
        while ( p != nullptr){
            //将链表反转
            temp = p->next;
            p->next = pre;
            pre = p;
            p = temp;
        }
        while (head != nullptr && pre != nullptr){
            if (head->val != pre->val){
                return false;
            }
            head->next;
            pre->next;
        }
        return true;

    }
};