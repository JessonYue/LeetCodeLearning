
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>

/**
 * 1047. 删除字符串中的所有相邻重复项
 * 给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。
 * 在 S 上反复执行重复项删除操作，直到无法继续删除。
 * 在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。
 *
 * 自己单独建一个栈来保存数据
 */
char *removeDuplicates(char *S) {
    if (S == NULL) {
        return S;
    }

    int size = strlen(S);
    if (size == 0) {
        return S;
    }

    char *stack = malloc(sizeof(char) * (size + 1));
    int top = -1;
    for (int i = 0; i < size; i++) {
        if (top >= 0 && stack[top] == S[i]) {
            top--;
        } else {
            stack[++top] = S[i];
        }
    }
    //字符串最后需要一个尾标识，不然就可能会有问题
    stack[++top] = '\0';
    return stack;
}

/**
 * 1047. 删除字符串中的所有相邻重复项
 * 给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。
 * 在 S 上反复执行重复项删除操作，直到无法继续删除。
 * 在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。
 *
 * 在字符串自身上进行操作,这种写法在clion编译器上报错，S[++top] = S[i],原因是传递的参数如果是字符串常量const char *,
 * 就不能在原值上进行修改。如果传的是char[] 就可以正常运行
 */
char *removeDuplicates2(char *S) {
    if (S == NULL || S[0] == 0) {
        return S;
    }
    int top = 0;
    int i = 1;
    while (S[i]) {
        if (top >= 0 && S[top] == S[i]) {
            top--;
        } else {
            S[++top] = S[i];
        }
        i++;
    }

    S[top + 1] = 0;
    return S;
}


void main() {
    char *s = "abbaca";
    char s1[] = {'a','b','b','a','c','a'};
    printf("%s", removeDuplicates2(s1));
    return;
}