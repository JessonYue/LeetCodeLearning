


#include <stdbool.h>
#include <string.h>
/**
 * 在 ASCII中
 * （  == 40
 *  ） == 41
 *  [ == 91
 *  ] == 93
 *  { == 123
 *  } == 125
 */
bool isValid(char *s) {
    int len = strlen(s);
    if(len==0)return true;
    //() [] {} 必须是成对出现的  len 必须为偶数
    if (len&1==1)return false; //len%2==1
    char stack[len];
    int top = -1;//表示栈空
    for (int i=0;i<len;i++){
        if (s[i]=='(' || s[i]=='['||s[i]=='{'){//是左括号时 入栈
            stack[++top] = s[i];
        } else if (top==-1)// 不是左括号们，栈空则无法配对，不符合
            return false;
        else if (s[i] == stack[top]+1 || s[i]==stack[top]+2){//s[i]是栈顶元素的右括号们
            stack[top--] = 0;
        }
    }
    return top==-1;
}
