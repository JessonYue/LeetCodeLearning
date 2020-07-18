//
// Created by 刘畅 on 2020/7/18.
//

#include "classLearn.h"
#include <stdio.h>
#include <stdlib.h>

//哈希数组大小
#define HASH_ARR_MAX 1024
//哈希节点
struct Hash{
    char *Key;	//关联Key
    int Data; //数据
    bool State; //特征值用来表示此空间是否被赋予值
};

//定义哈希数组
struct Hash *Node[HASH_ARR_MAX];

//初始化
int init() {
    for (int i = 0; i <= HASH_ARR_MAX - 1; ++i) {
        Node[i] = NULL;
    }
    return 1;
}

//计算哈希
signed int SetHashIndex(char* Key){
    if (Key == NULL){
        return -1;
    }
    signed int HashData = 0;//哈希值
    for (int i = 0; Key[i] != '\0'; ++i){
        HashData = HashData+33 * Key[i];//计算
    }
    return HashData%HASH_ARR_MAX;//取余返回
}
//查找
signed int GetIndex(char* Key){
    if (Key == NULL){
        return -2;
    }
    signed int HashIndex = SetHashIndex(Key);
    //没有计算出哈希值
    if (HashIndex == -1){
        return -1;
    }
    //判断是否为NULL
    if (Node[HashIndex] == NULL){
        return -1;
    }
    //判断是否赋予值
    if (Node[HashIndex]->State == 0){
        return -1;
    }
    return HashIndex;    //返回已经开辟空间了得值
}

//压入
int Input(char* Key,int Data) {
    if (Key == NULL || Data < 0) {
        return 0;
    }
    signed int Yoi = GetIndex(Key);
    //此哈希空间没有被赋予值或者开辟空间
    if (Yoi == -1) {
        signed int Ind = SetHashIndex(Key);
        //没有开辟空间则开辟空间，否则修改值
        if (Node[Ind] == NULL) {
            Node[Ind] = (struct Hash *) malloc(sizeof(struct Hash));
        }
        Node[Ind]->Data = Data;
        Node[Ind]->State = true;
        return 1;
    }
    return 0;
}

//删除
void Delete(char* Key) {
    if (Key == NULL) {
        return;
    }
    //获取哈希值然后判断是否为NULL不为NULL则释放并指向NULL
    signed int Ind = SetHashIndex(Key);
    if (Node[Ind] != NULL) {
        free(Node[Ind]);
        Node[Ind] = NULL;
    }
    return;

}

//获取
signed int GetData(char* Key){
    if (Key == NULL){
        return -1;
    }
    signed int Yoi = GetIndex(Key);
    if (Yoi != -1){
        return Node[Yoi]->Data;
    }
    return -1;
}

int main() {
    init();
    Input("test", 2);
    Input("test1", 4);
    printf("%d", GetData("test1"));
    getchar();
    return 0;

}
