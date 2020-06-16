
/**
 *给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 *
 * 有效字符串需满足：
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 注意空字符串可被认为是有效字符串。
 *
 */
bool isValid(char * s){
    if(s != NULL){
        int length = strlen(s);
        char* stack=(char*) malloc(length);
        int stackCount = 0;
        for(int i = 0; i < length; i++){
            if(stackCount == 0){
                stack[0] = s[i];
                stackCount++;
            }else{
                char comp = stack[stackCount-1];
                if(comp == '(' && s[i] == ')' || comp == '{' && s[i] == '}' || comp == '[' && s[i] == ']'){
                    stack[--stackCount] = 0;
                }else{
                    stack[stackCount++] = s[i];
                }
            }
        }
        if(stackCount != 0){
            return false;
        }

    }
    return true;
}
