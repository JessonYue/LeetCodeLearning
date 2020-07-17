//
// Created by Administrator on 2020/7/17.
//

// https://leetcode-cn.com/problems/first-unique-character-in-a-string/
//387. 字符串中的第一个唯一字符
//给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。

//示例：
//s = "leetcode"
//返回 0
//s = "loveleetcode"
//返回 2

int firstUniqChar(char * s){
    int comp = 1;
    int start = 0;
    bool lastRep = false;
    while(s[comp]){
        if(s[comp] == s[start]){
            start++;
            if(!s[comp]){
                lastRep = true;
            }
            comp = 0;
        }else{
            comp++;
            if(comp == start){
                comp++;
            }
        }
    }
    if(start < comp-1 || !lastRep){
        return start;
    }
    return -1;

}


//https://leetcode-cn.com/problems/convert-a-number-to-hexadecimal/
//405. 数字转换为十六进制数
//给定一个整数，编写一个算法将这个数转换为十六进制数。对于负整数，我们通常使用 补码运算 方法。

//注意:

//十六进制中所有字母(a-f)都必须是小写。
//十六进制字符串中不能包含多余的前导零。如果要转化的数为0，那么以单个字符'0'来表示；对于其他情况，十六进制字符串中的第一个字符将不会是0字符。
//给定的数确保在32位有符号整数范围内。
//不能使用任何由库提供的将数字直接转换或格式化为十六进制的方法。
//示例 1：

//输入:
//26

//输出:
//"1a"
//示例 2：

//输入:
//-1

//输出:
//"ffffffff"

char * toHex(int num){
    char table[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    bool isNeg = num<0;
    if(isNeg){
        char* res = (char*)malloc(9*sizeof(char));
        for(int i=0;i<8&&num;i++){
            res[7-i]=table[num & 0xf];
            num>>=4;
        }
        res[8] = '\0';
        return res;
    }else{
        int c = 0;
        int num2 = num;
        while(num2 >= 16){
            num2 /= 16;
            c ++;
        }
        num2 = num;
        char* res2 = (char*)malloc((c+2)*sizeof(char));
        res2[c+1] ='\0';
        while(num2>0){
            int n2 = num2%16;
            res2[c] = table[n2];
            c--;
            num2 /= 16;
        }
        return res2;
    }

}

//https://leetcode-cn.com/problems/move-zeroes/

//283. 移动零
//给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

//示例:

//输入: [0,1,0,3,12]
//输出: [1,3,12,0,0]
void moveZeroes(int* nums, int numsSize){
    int validIndex = 0;
    for(int i=0; i< numsSize; i++){
        if(nums[i]){
            if(validIndex == i){
                validIndex++;
                continue;
            }
            nums[validIndex++] = nums[i];
        }
    }
    for(;validIndex<numsSize;){
        nums[validIndex++] = 0;
    }
}

//https://leetcode-cn.com/problems/backspace-string-compare/
//844. 比较含退格的字符串
//给定 S 和 T 两个字符串，当它们分别被输入到空白的文本编辑器后，判断二者是否相等，并返回结果。 # 代表退格字符。

//注意：如果对空文本输入退格字符，文本继续为空。

//示例 1：

//输入：S = "ab#c", T = "ad#c"
//输出：true
//解释：S 和 T 都会变成 “ac”。

bool backspaceCompare(char * S, char * T){
    int sSize = getRealSize(S, strlen(S));
    int tSIze = getRealSize(T, strlen(T));
    if(sSize == tSIze){
        for(int i=0; i<sSize; i++){
            if(S[i] != T[i]){
                return false;
            }
        }
        return true;
    }
    return false;
}

int getRealSize(char * tg, int size){
    int count =0;
    for(int i=0; i<size; i++){
        if(tg[i] == '#'){
            if(count>0){
                count--;
            }
        }else{
            tg[count++] = tg[i];
        }
    }
    return count;

}


//https://leetcode-cn.com/problems/intersection-of-two-linked-lists/
//160. 相交链表
//编写一个程序，找到两个单链表相交的起始节点。

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *one = headA;
    struct ListNode *two = headB;
    while(one != two){
        one = one->next;
        two = two->next;
        if(!one){
            one = headB;
        }
        if(!two){
            two = headA;
        }
    }
    return one;

}