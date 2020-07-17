//
// Created by LCX on 2020/7/15.
//

#include <stdio.h>
#include <string.h>
#include <malloc.h>

int mine_strlen(const char *str)
{
    int count = 0;
    if(str == NULL)
        return -1;
    while (*str++)
    {
        count++;
    }
    return count;

}


char* mine_strcpy(const char *str)
{
    char *s = str;
    return s;
}

char* mine_strcat(char *str1, char *str2)
{

    int a,b;
    a = mine_strlen(str1);
    b = mine_strlen(str2);
    char *temp = (char *)malloc(sizeof(a+b+1));
    for (int j = 0; j < a; ++j) {
        temp[j] = str1[j];
    }
    for (int i = 0; i < b; ++i) {
        temp[a+i] = str2[i];
    }
    temp[a+b] = '\0';
    return temp;
}


/*搜索字符串常量*/
char* mine_strstr(const char *src, const char *sub)
{
    const char *bp;
    const char *sp;
    if(!src || !sub)
    {
        return src;
    }
    while(*src)
    {
        bp = src;
        sp = sub;
        do
        {
            if(!*sp)
                return src;
        }while(*bp++ == *sp ++);
        src ++;
    }
    return NULL;

}
/*搜索字符*/
char *mine_strchr(const char *str,char ch)
{
//    while (*str && str!=c)
//        str++;
//    if(*str == c)
//        return str;
//    return NULL;
    while (*str && *str != (char)ch)

        str++;

    if (*str == (char)ch)

        return((char *)str);

    return(NULL);
}

//内存复制 可以复制任意类型
void *mine_memcpy(void *mento, const void *menFrom,int size)
{
    if(mento == NULL || menFrom == NULL)
        return NULL;
    char *tempFrom = (char*)menFrom;
    char *tempTo = (char*)mento;
    while (size-- > 0)
    {
        *tempTo++ = *tempFrom++;
    }
    return mento;
}

int main(void)
{
//    char *str = "qwe";
//    char *s = mine_strcpy(str);
//    printf("%s\n",s);
//
//    char *ss = mine_strcat(str,s);
//    printf("%s\n",ss);
//    printf("%s\n",str);
//    printf("%s\n",s);
//
//    char *strs = mine_strstr("zxcvb","v");
//    printf("%s\n",strs);
    printf("%s\n",mine_strchr("adb1111",'1'));

    return 0;
}