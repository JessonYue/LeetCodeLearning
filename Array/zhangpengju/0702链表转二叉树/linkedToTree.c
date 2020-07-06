//方法一：使用有序数组构造高度平衡的二叉搜索树
//1,将有序链表转换为有序数组
//2,利用 sortedArrayToBst 的方法将有序数组转换为二叉搜索树
#define     MAX_NUM     20000

//函数一：例108
struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    int     iRoot       = 0;
    struct TreeNode*    pCurNode    = NULL;

    //1,结束条件
    if((NULL == nums) || (0 == numsSize)) return NULL;

    //2,初始化
    pCurNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));

    //3,定位根节点
    iRoot = numsSize / 2;

    //4,递归处理左右支
    pCurNode->val = nums[iRoot];
    pCurNode->left = sortedArrayToBST(&nums[0], iRoot);
    pCurNode->right = sortedArrayToBST(&nums[iRoot + 1], numsSize - iRoot - 1);
    return pCurNode;
}


struct TreeNode* sortedListToBST(struct ListNode* head){
    int     iNum        = 0;
    int*    pNum        = NULL;
    struct ListNode*    pListNode       = head;
    struct TreeNode*    pTreeNode       = NULL;

    pNum = (int*)malloc(sizeof(int) * MAX_NUM);
    memset(pNum, 0x00, sizeof(int) * MAX_NUM);

    //1,将有序链表转换成有序数组
    while(NULL != pListNode)
    {
        pNum[iNum++] = pListNode->val;
        pListNode = pListNode->next;
    }

    //2,将有序数组转换成高度平衡的二叉搜索树
    pTreeNode = sortedArrayToBST(pNum, iNum);

    //3,释放空间，返回
    free(pNum);
    return pTreeNode;
}