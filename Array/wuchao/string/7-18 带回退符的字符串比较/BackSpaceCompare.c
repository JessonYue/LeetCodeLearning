//
// Created by 吴超 on 2020/7/18.
//
#include <stdbool.h>

bool backspaceCompare(char * S, char * T){
    int stackTopS = -1;
    int stackTopT = -1;
    int i = 0;
    while(S[i]!='\0'){
        if(S[i]=='#'){
            i++;
            if(stackTopS==-1){
                continue;
            }
            stackTopS--;
        } else {
            S[++stackTopS] = S[i++];
        }
    }
    i=0;
    while(T[i]!='\0'){
        if(T[i]=='#'){
            i++;
            if(stackTopT==-1){
                continue;
            }
            stackTopT--;
        } else {
            T[++stackTopT] = T[i++];
        }
    }
    if(stackTopS!=stackTopT) return false;
    i=0;
    while(i<=stackTopS){
        if(S[i]!=T[i]){
            return false;
        }
        i++;
    }
    return true;
}
