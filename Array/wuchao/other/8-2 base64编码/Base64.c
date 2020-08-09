//
// Created by 吴超 on 2020/8/1.
//
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char base64code[65] = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
        'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
        'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7',
        '8', '9', '+', '/', '='
};
char* base64encode(char*  source,char* code);
char* base64encode(char*  source,char* code){
    size_t length = strlen(source);
    if(length<=0) return source;
    int resultLen = (length/3)*4+(length%3==0?0:1)*4;
    char* result = malloc(sizeof(char)*resultLen);
    int k = 0;
    for(int i = 0;i<length;i=i+3){
        if(length - i<=2){
            if(length - i == 1){
                result[k]=code[source[i]>>2];
                unsigned int s = source[i];
                result[k+1] = code[s<<30>>26];
                result[k+2] = code[64];
                result[k+3] = code[64];
            } else if(length - i == 2){
                unsigned int word2 = (source[i]<<8) + source[i+1];
                result[k] = code[word2>>10];
                result[k+1] = code[word2<<22>>26];
                result[k+2] = code[word2<<28>>26];
                result[k+3] = code[64];
            }
            k = k+4;
        } else {
            unsigned int word3 = (source[i]<<16)+(source[i+1]<<8)+source[i+2];
            int j=0;
            while(j<4){
                unsigned int word = word3<<(8+j*6);
                unsigned int index = word>>26;
                char a = code[index];
                result[k] = a;
                j++;
                k++;
            }
        }
    }
    return result;
}
int main() {
    char* test = "ManManBC";
    printf("Base64:%s",base64encode(test,base64code));
}
