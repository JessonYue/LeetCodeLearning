char * removeDuplicates(char * S){
    int top = -1;
    int cur = 0;
    char curC;
    while(curC = S[cur++]) {
        if(top < 0) {
            // 栈中没有元素时
            top++;
            S[0] = curC;
        } else {
            if(S[top] == curC) {
                // 与栈顶元素相等，出栈；
                top--;
            } else {
                // 与栈顶元素不相等，入栈；
                S[++top] = curC;
            }
        }
    }
    S[++top] = 0;
    return S;
}