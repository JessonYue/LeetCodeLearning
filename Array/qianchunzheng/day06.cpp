
#include <clocale>
/**
 * 题目：列表反转
 *
 */
struct Node_{
    //值
    int data;
    //指向下一个元素
    Node_* next;

}Node;

struct Linklist_{
    int length;
    Node_* head;
    Node_* tail;
}linklist;


/**
 * 思路：
 * 取两个指针，一个记录当前元素，一个记录前驱
 * 进行遍历，移动指针
 */
class Solution{
public:
    Node_* reverseList(Linklist_ * linklist){
        //用来指向前驱
        Node_* pre = NULL;
        //用来指向当前节点
        Node_* current = linklist->head;
        while (current != NULL){
            //获取下一个节点
            Node_ * next = current->next;
            //将前驱指针移动到当前位置
            pre = current;
            //将当前指针移动到下一个节点
            current = next;
        }
        //遍历完成后返回前驱指针，即反转后的头指针
        return pre;
    }
};



int main(int i){


    return 0;

}