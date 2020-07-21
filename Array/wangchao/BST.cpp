//
// Created by xiaoyaowang on 2020/7/15.
//

#include <stdio.h>
#include <stdlib.h>
#include "BST.h"


int main(){
    node* root = buildTree(50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    inorder(root);

    delete_bst(root, 40);

    printf("----------删除以后-----------\n");

    inorder(root);
}



node* newNode(int key){
    node* new_node = static_cast<node *>(malloc(sizeof(node)));
    new_node->key = key;
    new_node->left = nullptr;
    new_node->right = nullptr;
    return new_node;
}

void print_tree(node* item){

}

//中序遍历
void inorder(node* root){
    if (root != nullptr){
        inorder(root->left);
        printf("%d\n", root->key);
        inorder(root->right);
    }
}

//新建一颗bst
node* buildTree(int key){
    node* root = newNode(key);
    return root;
}


//插入bst
node* insert(node* node, int key){

    if (node == nullptr)return newNode(key);

    if (key < node->key){
        node->left = insert(node->left, key);
    } else{
        node->right = insert(node->right, key);
    }
    return node;
}

void free_node(node* node){
    free(node);
    node == nullptr;
}

void delete_bst(node* root, int key){
    if (root == nullptr)
        return ;
    //先找到这个node
    node* tmp = root;
    node* dst = nullptr;
    while (tmp != nullptr){
        if (key < tmp->key){
            tmp = tmp->left;
        } else if (key > tmp->key){
            tmp = tmp->right;
        } else if(key == tmp->key) {
            dst = tmp;
            break;
        }
    }

    if (dst != nullptr){
        if (dst->left == nullptr && dst->right == nullptr){
            free_node(dst);
        } else if (dst->left == nullptr){
            dst->key = dst->right->key;
            free_node(dst->right);
        } else if (dst->right == nullptr){
            dst->key = dst->left->key;
            free_node(dst->left);
        } else{
            //找右子树的最左节点
            node* r_tree = dst->right;
            while (r_tree->left != nullptr){
                r_tree = r_tree->left;
            }

            dst->key = r_tree->key;
            free_node(r_tree);
        }
    }

}




