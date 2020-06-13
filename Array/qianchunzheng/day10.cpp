
struct Node_{
    int data;
    Node_* next;
};

/**
 * 思路：
 * 1.利用快慢指针，找到链表的反转节点
 * 2.将后半部分链表反转
 * 3.进行对比
 */
class Solution{
public:
    Node_ *endOfFirstHalf(Node_ *pNode) {
        Node_* slow = pNode;
        Node_* fast = pNode;
        while (fast->next != nullptr && fast->next->next!= nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    //双指针法反转链表
    Node_ *reverseList(Node_ *pNode) {
        Node_* pre = nullptr;
        while (pNode->next != nullptr){
            //获取下一个节点
            Node_ * next = pNode->next;
            //将前驱指针移动到当前位置
            pre = pNode;
            //将当前指针移动到下一个节点
            pNode = next;
        }

        return pre;
    }

    bool isPalindrome(Node_* head){
        //获取链表前半部分
        Node_* front = endOfFirstHalf(head);
        //对后半部分进行反转
        Node_* node = reverseList(front->next);
        //进行对比
        Node_* node1 = head;
        Node_* node2 = node;
        bool result = true;

        if (result && node2 != nullptr){
            if (node1->data != node2->data){
                result = false;
            }
            node1 = node1->next;
            node2 = node2->next;
        }
        return result;

    }
};



int main(){
    return 0;
}