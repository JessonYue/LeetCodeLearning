//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//typedef unsigned char uchar;
//typedef unsigned int  uint;
//
//void Exchange(const uchar *Temp, uint *pOut, uchar length)
//{
//    int i = 0;
//    uchar *source;
//    if(length &1){//奇数
//        source = (uchar *)malloc(sizeof(uchar ) * (length+1));
////        memcpy(source,Temp,length);
////        int i = 0;
////        for (; i < length / 2  + 1; i++)
////        {
////            //小端序，直接按原来的顺序拷贝过去
////            //如果是大端序，则可以改变一下字节序
////            memcpy(pOut, source, 2);
////            pOut++;//int型指针后移一位
////            source+=2;//字符型字节后移两位
////        }
//        source++;
//        free(source);
//        printf("====");
//    }
//    else{ //偶数
//        for (; i < length / 2; i++)
//        {
//            //小端序，直接按原来的顺序拷贝过去
//            //如果是大端序，则可以改变一下字节序
//            memcpy(pOut, Temp, 2);
//            pOut++;//int型指针后移一位
//            Temp+=2;//字符型字节后移两位
//        }
//    }
//
//}
//
//int main(void)
//{
//    int i;
//    uint array[20] = {0};
//    uchar Start[] = {0x80,0xF1,0x58,0x03,0xC1,0xEA,0x8F,0x06,0x06};
//    Exchange(Start, array, sizeof(Start));
//    for (i = 0; i < 20; i++)
//    {
//        if (array[i] != 0)
//        {
//            printf("%4x ", htonl(array[i]));
//        }
//    }
//    printf("a=%4x",10000000);
//    printf("\n");
//    return 0;
//}
