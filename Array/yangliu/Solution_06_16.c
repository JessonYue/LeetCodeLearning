
int main() {

    return 0;
}

bool isValid(char * s){
    int len = strlen(s);
    if (len == 0)return true;
    if (len %2!=0) return false;
    char stack[len];
    int stackIndex = -1;
    for (int i = 0; i < len; i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            stack[++stackIndex] = s[i];
        else {
            if (stackIndex == -1) { return false; }
            else {
                if (stack[stackIndex] =='('&& s[i] == ')' || stack[stackIndex] =='['&& s[i] == ']' ||
                    stack[stackIndex] =='{'&& s[i] == '}') {
                    --stackIndex;
                }
            }
        }
    }
    return stackIndex == -1;
}
