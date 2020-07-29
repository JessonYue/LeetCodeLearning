//
// Created by Vashon on 2020/7/27.
//

#include "homework_base64.h"
#include <stdio.h>

void initSymbolTable(void) {
    for (int i = 0; i < BASELENGTH; ++i) {
        base64Alphabet[i] = -1;
    }
    for (int i = 'Z'; i >= 'A'; i--) {
        base64Alphabet[i] = (char) (i - 'A');
    }
    for (int i = 'z'; i >= 'a'; i--) {
        base64Alphabet[i] = (char) (i - 'a' + 26);
    }
    for (int i = '9'; i >= '0'; i--) {
        base64Alphabet[i] = (char) (i - '0' + 52);
    }

    base64Alphabet['+'] = 62;
    base64Alphabet['/'] = 63;

    for (int i = 0; i <= 25; i++) {
        lookUpBase64Alphabet[i] = (char) ('A' + i);
    }
    for (int i = 26, j = 0; i <= 51; i++, j++) {
        lookUpBase64Alphabet[i] = (char) ('a' + j);
    }
    for (int i = 52, j = 0; i <= 61; i++, j++) {
        lookUpBase64Alphabet[i] = (char) ('0' + j);
    }
    lookUpBase64Alphabet[62] = (char) '+';
    lookUpBase64Alphabet[63] = (char) '/';
}

bool isWhiteSpace(char octect) {
    return (octect == 0x20 || octect == 0xd || octect == 0xa || octect == 0x9);
}

bool isPad(char octect) {
    return (octect == PAD);
}

bool isData(char octect) {
    return (octect < BASELENGTH && base64Alphabet[octect] != -1);
}

int removeWhiteSpace(char data[], int length) {
    if (data == NULL) {
        return 0;
    }

    // 计算不是空格的字符
    int newSize = 0;
    int len = length;
    for (int i = 0; i < len; i++) {
        if (!isWhiteSpace(data[i])) {
            data[newSize++] = data[i];
        }
    }
    return newSize;
}

char *encode(const char *binaryData) {
    if (binaryData == NULL) {
        return NULL;
    }
    int length = strlen(binaryData);
    int lengthDataBits = length * EIGHTBIT;  // 一个字节 8 位，得到总二进制数据长度
    if (lengthDataBits == 0) {
        return "";
    }

    int fewerThan24bits = lengthDataBits % TWENTYFOURBITGROUP;
    int numberTriplets = lengthDataBits / TWENTYFOURBITGROUP;
    int numberQuartet = fewerThan24bits != 0 ? numberTriplets + 1 : numberTriplets;
    // 编码后的实际字符大小
    char *encodedData = malloc(((numberQuartet << 2) + 1) * sizeof(char));
    assert(encodedData != NULL);

    char k = 0, l = 0, b1 = 0, b2 = 0, b3 = 0;

    int encodedIndex = 0;
    int dataIndex = 0;

    for (int i = 0; i < numberTriplets; i++) {
        // 每次取出 3 个字节：24位
        b1 = binaryData[dataIndex++];
        b2 = binaryData[dataIndex++];
        b3 = binaryData[dataIndex++];
        // 从第 2 字节得到低 4 位
        l = (char) (b2 & 0x0f);
        // 从第 1 字节得到低 2 位
        k = (char) (b1 & 0x03);
        // 第 1 字节右移 2 位，若存在符号位，则异或 1100 0000
        // 假设是 F 对应的 ascii 为 0x46 : 0100 0110 -> 0001 0001 : 0x11
        char val1 = ((b1 & SIGN) == 0) ? (char) (b1 >> 2) : (char) ((b1) >> 2 ^ 0xc0);
        // 第 2 字节右移 4 位，若存在符号位，则异或 1111 0000
        // 假设是 E 对应的 ascii 为 0x45 : 0100 0101 -> 0000 0100 : 0x04
        char val2 = ((b2 & SIGN) == 0) ? (char) (b2 >> 4) : (char) ((b2) >> 4 ^ 0xf0);
        // 第 3 字节右移 6 位，若存在符号位，则异或 1111 1100
        // 假设是 F 对应的 ascii 为 0x46 : 0100 0101 -> 0000 0001 : 0x01
        char val3 = ((b3 & SIGN) == 0) ? (char) (b3 >> 6) : (char) ((b3) >> 6 ^ 0xfc);

        encodedData[encodedIndex++] = lookUpBase64Alphabet[val1];
        encodedData[encodedIndex++] = lookUpBase64Alphabet[val2 | (k << 4)];
        encodedData[encodedIndex++] = lookUpBase64Alphabet[(l << 2) | val3];
        encodedData[encodedIndex++] = lookUpBase64Alphabet[b3 & 0x3f];
    }

    // 形成 6 位组的整数
    if (fewerThan24bits == EIGHTBIT) {  // 普通字节，每 3 个字节，base64一下变成 4 个字节，所以普通字节多出 3:4 这样的比例为 8 位时
        b1 = binaryData[dataIndex];
        k = (char) (b1 & 0x03);

        char val1 = ((b1 & SIGN) == 0) ? (char) (b1 >> 2) : (char) ((b1) >> 2 ^ 0xc0);
        encodedData[encodedIndex++] = lookUpBase64Alphabet[val1];
        encodedData[encodedIndex++] = lookUpBase64Alphabet[k << 4];
        encodedData[encodedIndex++] = PAD;
        encodedData[encodedIndex++] = PAD;
    } else if (fewerThan24bits == SIXTEENBIT) { // 普通字节多出 3:4 这样的比例为 16 位时
        b1 = binaryData[dataIndex];
        b2 = binaryData[dataIndex + 1];
        l = (char) (b2 & 0x0f);
        k = (char) (b1 & 0x03);

        char val1 = ((b1 & SIGN) == 0) ? (char) (b1 >> 2) : (char) ((b1) >> 2 ^ 0xc0);
        char val2 = ((b2 & SIGN) == 0) ? (char) (b2 >> 4) : (char) ((b2) >> 4 ^ 0xf0);

        encodedData[encodedIndex++] = lookUpBase64Alphabet[val1];
        encodedData[encodedIndex++] = lookUpBase64Alphabet[val2 | (k << 4)];
        encodedData[encodedIndex++] = lookUpBase64Alphabet[l << 2];
        encodedData[encodedIndex++] = PAD;
    }

    encodedData[encodedIndex] = '\0'; // 字符串结束标记
    return encodedData;
}

char *decode(const char *encoded) {
    if (encoded == NULL) {
        return NULL;
    }

    int length = strlen(encoded);
    char *base64Data = malloc(length * sizeof(char) + 1);
    assert(base64Data != NULL);
    strcpy(base64Data, encoded);
    base64Data[length] = '\0';

    // 移除空格
    int len = removeWhiteSpace(base64Data, length);

    if (len % FOURBYTE != 0) {
        return NULL;// 应该能被 4 整除
    }

    int numberQuadruple = (len / FOURBYTE);

    if (numberQuadruple == 0) {
        return "";
    }

    length = numberQuadruple * 3;
    char *decodedData = malloc(length * sizeof(char) + 1);;
    assert(decodedData != NULL);
    char b1 = 0, b2 = 0, b3 = 0, b4 = 0;
    char d1 = 0, d2 = 0, d3 = 0, d4 = 0;

    int i = 0;
    int encodedIndex = 0;
    int dataIndex = 0;

    for (; i < numberQuadruple - 1; i++) {
        if (!isData((d1 = base64Data[dataIndex++]))
            || !isData((d2 = base64Data[dataIndex++]))
            || !isData((d3 = base64Data[dataIndex++]))
            || !isData((d4 = base64Data[dataIndex++]))) {
            return NULL;
        }// 如果发现没有数据就返回 NULL

        b1 = base64Alphabet[d1];
        b2 = base64Alphabet[d2];
        b3 = base64Alphabet[d3];
        b4 = base64Alphabet[d4];

        decodedData[encodedIndex++] = (char) (b1 << 2 | b2 >> 4);
        decodedData[encodedIndex++] = (char) (((b2 & 0xf) << 4) | ((b3 >> 2) & 0xf));
        decodedData[encodedIndex++] = (char) (b3 << 6 | b4);
    }

    if (!isData((d1 = base64Data[dataIndex++]))
        || !isData((d2 = base64Data[dataIndex++]))) {
        return NULL;// 如果发现没有数据就返回 NULL
    }

    b1 = base64Alphabet[d1];
    b2 = base64Alphabet[d2];

    d3 = base64Data[dataIndex++];
    d4 = base64Data[dataIndex++];

    if (!isData((d3)) || !isData((d4))) {// 检查这些字符，看是否是 PAD
        if (isPad(d3) && isPad(d4)) {
            if ((b2 & 0xf) != 0)// 最后的 4 位应该是 0
                return NULL;

            length = i * 3;
            char *tmp = malloc(sizeof(char) * length + 1 + 1);
            assert(tmp != NULL);
            strncpy(tmp, decodedData, length);
            tmp[encodedIndex++] = (char) (b1 << 2 | b2 >> 4);
            tmp[encodedIndex] = '\0';
            // 记得回收资源
            free(base64Data);
            free(decodedData);
            return tmp;
        } else if (!isPad(d3) && isPad(d4)) {
            b3 = base64Alphabet[d3];
            if ((b3 & 0x3) != 0)// 最后的 2 位应该是 0
                return NULL;

            length = i * 3;
            char *tmp = malloc(sizeof(char) * length + 2 + 1);
            assert(tmp != NULL);
            strncpy(tmp, decodedData, length);
            tmp[encodedIndex++] = (char) (b1 << 2 | b2 >> 4);
            tmp[encodedIndex++] = (char) (((b2 & 0xf) << 4) | ((b3 >> 2) & 0xf));
            tmp[encodedIndex] = '\0';
            // 记得回收资源
            free(base64Data);
            free(decodedData);
            return tmp;
        } else {
            return NULL;
        }
    } else { // No PAD e.g 3cQl
        b3 = base64Alphabet[d3];
        b4 = base64Alphabet[d4];
        decodedData[encodedIndex++] = (char) (b1 << 2 | b2 >> 4);
        decodedData[encodedIndex++] = (char) (((b2 & 0xf) << 4) | ((b3 >> 2) & 0xf));
        decodedData[encodedIndex++] = (char) (b3 << 6 | b4);
    }

    free(base64Data);
    decodedData[encodedIndex] = '\0';
    return decodedData;
}

void homework_base64(void) {
    initSymbolTable();
    char *test1 = "FEFEFE", *encodeStr = NULL, *decodeStr = NULL;
    char *test2 = "测试";
    encodeStr = encode(test2);
    printf("encode string is : %s\n", encodeStr);
    decodeStr = decode(encodeStr);
    printf("decode string is : %s\n", decodeStr);
    free(encodeStr);
    free(decodeStr);
}