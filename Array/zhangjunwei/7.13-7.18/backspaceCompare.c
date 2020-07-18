//
// Created by 张俊伟 on 2020/7/16.
//
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int deletebackspace1(char *str, int size) {
    //字符串本身做为栈来操作
    if (str == NULL || size == 0)return 0;
    int index = 0;
    for (int i = 0; i < size; ++i) {
        if (str[i] != '#') {
            str[index] = str[i];
            index++;
        } else {
            index = index > 0 ? index - 1 : 0;
        }
    }
    return index;//返回 index最后定位的下标  即有经过退格之后还剩多少元素
}
int deletebackspace(char *str, int size) {
    //字符串本身做为栈来操作
    if (str == NULL || size == 0)return 0;
    int top = 0;//即是栈顶下标 又是 栈内元素的个数
    for (int i = 0; i < size; ++i) {
        if (str[i] != '#') {//入栈
            str[top++] = str[i];
        } else  if (top>0){//出栈
            top--;
        }
    }
    return top;//栈内元素个数
}
bool backspaceCompare(char *S, char *T) {
    int slen = deletebackspace(S, strlen(S));
    int tlen = deletebackspace(T, strlen(T));
    if (slen != tlen) return false;

    for(int i=0;i<slen;i++)
    {
        if(S[i] != T[i])
        {
            return false;
        }
    }
    return true;

}

//bool backspaceCompare1(char *S, char *T) {
//    int len1 = strlen(S);
//    int len2 = strlen(S);
//    char *s1 = (char *) calloc(len1, sizeof(char));
//    char *t1 = (char *) calloc(len1, sizeof(char));
//
//    int j = 0;
//    for (int i = 0; i < len1; ++i) {
//        if ((s1[j] = S[i]) == '#') {
//            j = j == 0 ? 0 : j - 1;
//        } else {
//            j++;
//        }
//    }
//    j = 0;
//    for (int i = 0; i < len2; ++i) {
//        if ((t1[j] = T[i]) == '#') {
//            j = j == 0 ? 0 : j - 1;
//        } else {
//            j++;
//        }
//    }
//
//    bool res = strcmp(s1, t1) == 0;
//    free(s1);
//    free(t1);
//
//    return res;
//}

int main(){
    char s[] = {'a','#','\0'};
    char t[] = {'b','#','\0'};
    backspaceCompare(s,t);
    return 0;
}