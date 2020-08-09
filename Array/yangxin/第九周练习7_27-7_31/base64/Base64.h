//
// Created by 12 on 2020/8/1.
//

#ifndef LEETCODESTUDY_BASE64_H
#define LEETCODESTUDY_BASE64_H

static const char *base64EncodeChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
static const int base64DecodeChars[128] = {
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 62, -1, -1, -1, 63,
        52, 53, 54, 55, 56, 57, 58, 59, 60, 61, -1, -1, -1, -1, -1, -1,
        -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
        15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, -1, -1, -1, -1, -1,
        -1, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
        41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, -1, -1, -1, -1, -1};
//中文字符有问题得不到正确的编码,与编译器格式有关，改成gbk在编译器上就可以正常转码
void enBASE64code(char *charBuf, int charBufLen, char *base64Char) {
    int int63 = 0x3f; //  00111111 意图去掉8bit的两高位
    int int255 = 0xff;
    int a = 0;
    int i = 0;
    char b0;
    char b1;
    char b2;
    while (i < charBufLen) {
        b0 = charBuf[i++];
        b1 = (i == charBufLen) ? 0 : charBuf[i++];
        b2 = (i == charBufLen) ? 0 : charBuf[i++];
        //b0字符的高6bit   00+6bit 组成一个8bit十进制数 即BASE编码表号
        base64Char[a++] = base64EncodeChars[(b0 >> 2 & int63)];
        //b0字符取低4bit 或运算 b1字符高4位 组成一个8bit，最后与运算int63把高2位换成0 即满足BASE编码表号
        //用或运行的原因是b0的高4bit是实际值，低4bit为0，b1的高4bit为0，低4bit为实际值，或运算刚好把他们的实际值进行组合
        base64Char[a++] = base64EncodeChars[((b0 << 4) | ((b1 & int255) >> 4)) & int63];
        //b1字符取低6bit 或运算 b2字符高2位 组成一个8bit，最后与运算int63把高2位换成0 即满足BASE编码表号
        base64Char[a++] = base64EncodeChars[((b1 << 2) | ((b2 & int255) >> 6)) & int63];
        //b2字符直接与运行int63,获取低6bit，高2bit为0 即满足BASE编码表号
        base64Char[a++] = base64EncodeChars[(b2 & int63)];
    }
    //最后不够4个字符  补=，最多补两个 ==，因为不满足长度运算时补位为0，最后用=替换掉补位值不然都是A,=号在base64里表示没有实际值
    switch (charBufLen % 3) {
        case 1:
            base64Char[--a] = '=';
        case 2:
            base64Char[--a] = '=';
    }
}

void deBASE64code(char *base64Char, int base64CharLen, char *outStr) {
    int c0, c1, c2, c3;
    int int255 = 0xff;
    int index = 0;
    for (int i = 0; i < base64CharLen; i += 4) {
        c0 = base64DecodeChars[base64Char[i]];
        c1 = base64DecodeChars[base64Char[i + 1]];
        outStr[index++] = ((c0 << 2) | (c1 >> 4)) & int255;
        if (index >= base64CharLen) {
            return;
        }
        c2 = base64DecodeChars[base64Char[i + 2]];
        outStr[index++] = ((c1 << 4) | (c2 >> 2)) & int255;
        if (index >= base64CharLen) {
            return;
        }
        c3 = base64DecodeChars[base64Char[i + 3]];
        outStr[index++] = ((c2 << 6) | c3) & int255;
    }
}

#endif //LEETCODESTUDY_BASE64_H
