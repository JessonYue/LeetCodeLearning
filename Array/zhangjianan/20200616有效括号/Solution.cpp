bool isValid(char * s){
if(*s==0) return true;//空字符串显然符合
int len=strlen(s);
if(len&1) return false;//奇数长度的字符串显然不符合
len>>1;
char stack[len];
int top=-1;
for(int i=0;i<len;i++){
    if(s[i]=='{'||s[i]=='('||s[i]=='['){
        stack[++top]=s[i];//如果是左括号，入栈
    }else if(top==-1){
        return false;// 不是左括号们，栈空则无法配对，不符合
    }else if(s[i]==stack[top]+1||s[i]==stack[top]+2){
        stack[top--]=0;// 不是左括号们，栈非空，当前和栈顶配对，出栈
    }else {
        return false;// 不是左括号们，栈非空，当前和栈顶不配对，不符合
    }
}
    return top==-1; // 最后栈为空则符合，不为空则不符合
}