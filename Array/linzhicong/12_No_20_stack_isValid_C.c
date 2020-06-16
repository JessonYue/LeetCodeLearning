bool isValid(char * s){
    if(!s) return false;
    int len = strlen(s);
    if(len == 0) return true;
    if(len % 2) return false;
    int stacklen = len/2; // 数组长度只需要一半即可，因为括号匹配了就可以移出数组，不占空间
    char stack[stacklen];
    int top = -1;
    for(int i = 0; i < len; i++) {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
            if(top >= stacklen - 1) return false;
            stack[++top] = s[i];
        } else if(top == -1) {
            return false;
        } else if(s[i] == stack[top]+1 || s[i] == stack[top]+2) {
            stack[top--] = 0;
        } else {
            return false;
        }
    }
    return top == -1;
}