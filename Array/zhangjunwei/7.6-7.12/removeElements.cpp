//
// Created by 张俊伟 on 2020/7/11.
//

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *removeElements(ListNode *head, int val) {
        ListNode **p = &head;
        while (*p) {
            if ((*p)->val == val) {
                if ((*p)->next) {
                    (*p)->val = (*p)->next->val;
                    (*p)->next = (*p)->next->next;
                } else {
                    *p = nullptr;
                }
            } else{

                p = &(*p)->next;
            }

        }
        return head;
    }
};
ListNode* add_node(ListNode *head, int val){
    ListNode **p = &head;

    while (*p){
       p = &(*p)->next;
    }

        *p = new ListNode(val);

    return head;
}
int main() {
    int arr[] = {1, 2, 6, 3, 4, 5, 6};
//    int arr[] = {1, 1};
    int n = 6;
    ListNode *head;
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            head = new ListNode(arr[i]);
        } else{
            add_node(head, arr[i]);
        }
    }

   Solution solution = Solution();
    solution.removeElements(head, 6);
head;
}