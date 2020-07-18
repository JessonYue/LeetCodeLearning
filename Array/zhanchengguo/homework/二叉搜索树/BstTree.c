#include <stdlib.h>
#include <stdio.h>

typedef int DATA;
typedef struct TreeNode {
    DATA data;
    struct TreeNode *leftChild;
    struct TreeNode *rightChild;
} TreeNode;

//创建树
TreeNode *createTree();

//插入树
void insertNode(TreeNode **treeNode, DATA value);

//打印树
void printTree(TreeNode **treeNode);

//删除树节点
int deleteTree(TreeNode **treeNode, DATA value);

//销毁树
void destroyTreeNode(TreeNode **treNode);

TreeNode *createTree() {
    TreeNode *node = malloc(sizeof(TreeNode));
    node->data = 0;
    node->leftChild = NULL;
    node->rightChild = NULL;
    return node;
}

void insertNode(TreeNode **treeNode, DATA value) {
    TreeNode *root = *treeNode;
    TreeNode *parent = NULL;
    while (root != NULL) {
        if(root->data == value){
            return;
        }
        parent = root;
        if (root->data > value) {
            root = root->leftChild;
        } else {
            root = root->rightChild;
        }
    }
    TreeNode *node = malloc(sizeof(TreeNode));
    node->data = value;
    node->leftChild = NULL;
    node->rightChild = NULL;
    if (parent == NULL) {
        parent = node;
    } else if (value < parent->data) {
        parent->leftChild = node;
    } else {
        parent->rightChild = node;
    }
}

void printTree(TreeNode **treeNode) {
    if (*treeNode == NULL) {
        return;
    }
    printTree(&((*treeNode)->leftChild));
    printf("value is %d\n", (*treeNode)->data);
    printTree(&((*treeNode)->rightChild));
}

int deleteTree(TreeNode **treeNode, DATA value){
    TreeNode *temp = *treeNode;
    if(temp ==NULL){
        return 0;
    }
    if(value < temp->data){
        return deleteTree(&(temp->leftChild),value);
    }
    if(value > temp->data){
        return deleteTree(&(temp->rightChild),value);
    }
    if(temp->leftChild == NULL){
        temp = temp->rightChild;
        free(temp);
        return 1;
    }else if(temp->rightChild == NULL){
        temp = temp->leftChild;
        free(temp);
        return 1;
    }else{
        if(temp->leftChild->rightChild == NULL){
            temp->data = temp->leftChild->data;
            return deleteTree(&(temp->leftChild),temp->data);
        }else{
            TreeNode *p1 = temp,*p2 = p1->leftChild;
            while(p2->rightChild !=NULL){
                p1 = p2;
                p2 = p2->rightChild;
            }
            temp->data = p2->data;
            return deleteTree(&(p1->rightChild),p2->data);
        }
    }

}

void destroyTreeNode(TreeNode **treNode){
    if(*treNode != NULL){
        destroyTreeNode(&((*treNode)->leftChild));
        destroyTreeNode(&((*treNode)->rightChild));
        free(*treNode);
        *treNode = NULL;
    }
}

int main() {
    TreeNode *tree = createTree();
    insertNode(&(tree), 3);
    insertNode(&(tree), 5);
    insertNode(&(tree), 4);
    insertNode(&(tree), 2);
    insertNode(&(tree), 6);
    insertNode(&(tree), 8);
    insertNode(&(tree), 7);
    insertNode(&(tree), 10);
    insertNode(&(tree), 11);
    insertNode(&(tree), 1);

    printTree(&tree);
    printf("\n");
    deleteTree(&tree, 3);
    printTree(&tree);
    printf("\n");
    destroyTreeNode(tree);
    printTree(&tree);


    return 0;
}

