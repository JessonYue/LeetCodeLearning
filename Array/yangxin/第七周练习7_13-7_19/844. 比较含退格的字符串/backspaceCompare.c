#include <string.h>
#include <stdbool.h>
#include <stdio.h>

bool backspaceCompare(char * S, char * T){
    int i = strlen(S) - 1;
    int j = strlen(T) - 1;
    //确定最后有多少个剩余字符，辅助变量
    int skipS = 0, skipT = 0;
    while (i >= 0 || j >= 0) {
        while (i >= 0) {
            if (S[i] == '#') {
                skipS++;
                i--;
            } else if (skipS > 0) {//大于0说明还需要移除一个字符
                skipS--;
                i--;
            } else {
                break;
            }
        }
        while (j >= 0) {
            if (T[j] == '#') {
                skipT++;
                j--;
            } else if (skipT > 0) {
                skipT--;
                j--;
            } else {
                break;
            }
        }
        if (i >= 0 && j >= 0 && S[i] != T[j]) {
            return false;
        }
        //如果有一个字符串已经为null结束比较返回fasle
        if ((i >= 0) != (j >= 0)) {
            return false;
        }
        i--;
        j--;
    }

    return true;
}