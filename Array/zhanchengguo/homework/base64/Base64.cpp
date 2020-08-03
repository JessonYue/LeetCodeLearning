#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <cstring>

using namespace std;

static unsigned char alphabet_map[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
static unsigned char reverse_map[] =
        {
                255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
                255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
                255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 62, 255, 255, 255, 63,
                52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 255, 255, 255, 255, 255, 255,
                255, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
                15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 255, 255, 255, 255, 255,
                255, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
                41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 255, 255, 255, 255, 255};

long base64_encode(const char *text, long text_len, char *encode) {
    long i, j;
    for (i = 0, j = 0; i + 3 <= text_len; i += 3) {
        //取出第一个字符的前6位并找出对应的结果字符
        encode[j++] = alphabet_map[text[i] >> 2];
        //将第一个字符的后2位与第二个字符的前4位进行组合并找到对应的结果字符
        encode[j++] = alphabet_map[((text[i] << 4) & 0x30) |
                                   (text[i + 1] >> 4)];
        //将第二个字符的后4位与第三个字符的前2位组合并找出对应的结果字符
        encode[j++] = alphabet_map[((text[i + 1] << 2) & 0x3c) |
                                   (text[i + 2] >> 6)];
        //取出第三个字符的后6位并找出结果字符
        encode[j++] = alphabet_map[text[i + 2] & 0x3f];
    }

    if (i < text_len) {
        long tail = text_len - i;
        if (tail == 1) {
            encode[j++] = alphabet_map[text[i] >> 2];
            encode[j++] = alphabet_map[(text[i] << 4) & 0x30];
            encode[j++] = '=';
            encode[j++] = '=';
        } else //tail==2
        {
            encode[j++] = alphabet_map[text[i] >> 2];
            encode[j++] = alphabet_map[((text[i] << 4) & 0x30) | (text[i + 1] >> 4)];
            encode[j++] = alphabet_map[(text[i + 1] << 2) & 0x3c];
            encode[j++] = '=';
        }
    }
    return j;
}

long base64_decode(const char *code, long code_len, char *plain) {
    assert((code_len & 0x03) == 0);  //如果它的条件返回错误，则终止程序执行。4的倍数。
    long i, j = 0;
    char quad[4];
    for (i = 0; i < code_len; i += 4) {
        for (long k = 0; k < 4; k++) {
            //分组，每组四个分别依次转换为base64表内的十进制数
            quad[k] = reverse_map[code[i + k]];
        }
        assert(quad[0] < 64 && quad[1] < 64);
        //取出第一个字符对应base64表的十进制数的前6位与第二个字符对应base64表的十进制数的前2位进行组合
        plain[j++] = (quad[0] << 2) | (quad[1] >> 4);
        if (quad[2] >= 64)
            break;
        else if (quad[3] >= 64) {
            //取出第二个字符对应base64表的十进制数的后4位与第三个字符对应base64表的十进制数的前4位进行组合
            plain[j++] = (quad[1] << 4) | (quad[2] >> 2);
            break;
        } else {
            plain[j++] = (quad[1] << 4) | (quad[2] >> 2);
            //取出第三个字符对应base64表的十进制数的后2位与第4个字符进行组合
            plain[j++] = (quad[2] << 6) | quad[3];
        }
    }
    return j;
}


int main() {
    //编码
//    char input[256];
//    printf("Please input string: ");
//    scanf("%s", input);
//    char *text = (char *) input;
//    long text_len = (long) strlen((char *) text);
//    char buffer[1024], buffer2[4096];
//    long size = base64_encode(text, text_len, buffer2);
//    buffer2[size] = 0;
//    printf("%s\n", buffer2);
//    size = base64_decode(buffer2, size, buffer);
//    buffer[size] = 0;
//    printf("%s\n", buffer);

    //解码
    char input[256];
    printf("Please input what you want to decode: ");
    scanf("%s", input);
    char *text = (char *) input;
    long text_len = (long) strlen((char *) text);
    char buffer[1024], buffer2[4096];

    long size = base64_decode(text, text_len, buffer);
    buffer[size] = 0;
    printf("Decoded content: %s\n", buffer);
    size = base64_encode(buffer, size, buffer2);
    buffer2[size] = 0;
    printf("Confirmation of the original content: %s\n", buffer2);

    return 0;
}