//
//  homework_003.c
//  BaseBuild
//
//  Created by mac on 2020/6/2.
//  Copyright © 2020 mingxi. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

// 实现 strStr() 函数，LeetCode第28题
void homework_003_028(void)
{
    char haystack[64], needle[16];
    printf("请输入字符串 haystack ：");
    scanf("%s", haystack);
    printf("请输入字符串 needle ：");
    scanf("%s", needle);
    printf("字符串 haystack 为：%s\n字符串 needle 为：%s\n", haystack, needle);
    int strStr(char *haystack, char *needle);
    int resultCode = strStr(haystack, needle);
    if(resultCode == -1)
        printf("字符串 haystack 中不存在子字符串 needle\n");
    else
        printf("字符串 haystack 中子字符串 needle 所在位置的索引为：%d\n", resultCode);
}

int strStr(char *haystack, char *needle)
{
    if(haystack == NULL)
        return -1;
    if(needle == NULL)
        // 与c与java保持一致，但我个人认为，空集为任何集合子集，所以为 0
        return 0;
    long haystackLen = strlen(haystack);
    long needleLen = strlen(needle);
    if(haystackLen < needleLen)
        return -1;
    else
    {
        int i, j = 0;
        for(i = 0; i < haystackLen;)
        {
            if(haystack[i] != needle[j])
            {
                if(j == 0)  // 当字符不匹配重置后才需要将长串索引后移，否则将会跳过了一个字符
                    i++;
                // 不符合条件，重置小串的索引
                j = 0;
            }
            else
            {
                i++;
                // 当小串的索引与小串长度相等，则为匹配成功
                if(++j == needleLen)
                    return i - j;
            }
        }
    }
    return -1;
}

// 两数相加，LeetCode第2题
void homework_003_002(void)
{
    int i = 0;
    struct ListNode *l1 = NULL, *l2 = NULL, *l;
    void listInsert(struct ListNode **list, int e);
    void displayList(struct ListNode *list);
    void destroyList(struct ListNode **list);
    struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);
    printf("请输入第一个数的倒叙，大于等于 10 为结束：\n");
    while(i < 10)
    {
        scanf("%d", &i);
        if(i < 10)
            listInsert(&l1, i);
    }
    printf("请输入第二个数的倒叙，大于等于 10 为结束：\n");
    i = 0;
    while(i < 10)
    {
        scanf("%d", &i);
        if(i < 10)
            listInsert(&l2, i);
    }
    printf("第一个数为：");
    displayList(l1);
    printf("第二个数为：");
    displayList(l2);
    l = addTwoNumbers(l1, l2);
    printf("合并的数为：");
    displayList(l);
    
    destroyList(&l1);
    destroyList(&l2);
    destroyList(&l);
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    int bit = 1, sum = 0;
    struct ListNode* sumList = NULL, *list1 = l1, *list2 = l2, *temp1 = NULL, *temp2;
    // 当表一或者表二还存在数据位，就要进行扫描
    while(list1 != NULL || list2 != NULL)
    {
        // 获取对应的数据位并还原成对应的大小并存入合计数
        if(list1 != NULL)
        {
            sum += list1->val * bit;
            list1 = list1->next;
        }
        if(list2 != NULL)
        {
            sum += list2->val * bit;
            list2 = list2->next;
        }
        // 当为个位时，为了防止进位变成两位数，所以对10取模
        if(sumList == NULL)
        {
            sumList = malloc(sizeof(struct ListNode));
            sumList->next = NULL;
            sumList->val = sum % 10;
            temp1 = sumList;
        }
        // 后面的数一律除bit就可得到对应的合计位
        else
        {
            temp2 = malloc(sizeof(struct ListNode));
            temp2->next = NULL;
            temp2->val = sum / bit;
            temp1->next = temp2;
            temp1 = temp2;
        }
        // 进位
        bit *= 10;
    }
    // 当最后一位正好进位，这里就肯定不会为 0
    if(sum / bit)
    {
        temp2 = malloc(sizeof(struct ListNode));
        temp2->next = NULL;
        temp2->val = sum / bit;
        temp1->next = temp2;
    }
    
    return sumList;
}

// 输出线性表
void displayList(struct ListNode *list)
{
    while(list->next != NULL)
    {
        printf("%d -> ", list->val);
        list = list->next;
    }
    printf("%d\n", list->val);
}

// 销毁单链表
void destroyList(struct ListNode **list)
{
    struct ListNode *prior = *list, *next = (*list)->next;
    while(next != NULL)
    {
        free(prior);
        prior = next;
        next = prior->next;
    }
    free(prior);
}

// 插入数据元素
void listInsert(struct ListNode **list, int e)
{
    struct ListNode *prior = *list, *next;
    if(*list == NULL)
    {
        (*list) = malloc(sizeof(struct ListNode));
        (*list)->val = e;
        (*list)->next = NULL;
    }
    else
    {
        // 找到目标位置的前一个位置
        while(prior->next != NULL)
            prior = prior->next;
        next = malloc(sizeof(struct ListNode));
        next->val = e;
        next->next = prior->next;
        prior->next = next;
    }
}
