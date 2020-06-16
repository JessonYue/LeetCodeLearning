bool isValid(char *s) {
    if (s == NULL || s[0] == '\0') {
        return true;
    }

    int len = strlen(s);
    int index = -1;
    char stack[len];

    for (int i = 0; i < len; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack[++index] = s[i];
        } else if (index == -1) {
            return false;
        } else if ((stack[index] + 1) == s[i] || (stack[index] + 2) == s[i]) {
            stack[index--] = 0;
        } else {
            stack[++index] = s[i];
        }
    }

    return index == -1;
}