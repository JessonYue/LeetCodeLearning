//
// Created by Vashon on 2020/7/27.
//

#ifndef C_HOMEWORK_BASE64_H
#define C_HOMEWORK_BASE64_H

#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

const int BASELENGTH = 128;
const int LOOKUPLENGTH = 64;
const int TWENTYFOURBITGROUP = 24;
const int EIGHTBIT = 8;
const int SIXTEENBIT = 16;
const int FOURBYTE = 4;
const int SIGN = -128;
const char PAD = '=';
char base64Alphabet[128];
char lookUpBase64Alphabet[64];

// 初始化符号数组
void initSymbolTable(void);

bool isWhiteSpace(char octect);

bool isPad(char octect);

bool isData(char octect);

int removeWhiteSpace(char data[], int length);

// base64 编码
char *encode(const char *binaryData);

// base64 解码
char *decode(const char *encoded);

#endif //C_HOMEWORK_BASE64_H
