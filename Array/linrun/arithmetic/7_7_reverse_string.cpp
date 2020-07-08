//
// Created by Administrator on 2020/7/7.
//

void reverseString(char* s, int sSize){
    int i = 0;
    int temp = 0;
    while(i<sSize - 1 -i){
        temp = s[i];
        s[i] = s[sSize - 1 -i];
        s[sSize - 1 -i] = temp;
        i++;
    }
}