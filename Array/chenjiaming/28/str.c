int strStr(char * haystack, char * needle){
    /*
     * i 枚举 needle，j 枚举 haystack
     * tmp 记录下当前字符开始尝试是否相等的下标
     */
    int i = 0, j = 0, tmp = j;
    int index = -1;

    // 由题意空字符串返回 0
    if(!strlen(needle))    return 0;

    // 两个串非末尾时才能枚举
    while(haystack[j] && needle[i]){
        // 枚举 haystack 直到遇到 needle 第一个字符
        if(needle[i] == haystack[j]){
            // 记录当前位置，如果与 needle 不同从这个位置开始重新枚举 haystack
            tmp = j;
            index = j;                                  // 先假设此处就是 index 

            while(needle[++i]){
                if(j < strlen(haystack) - 1)    j++;
                else    return -1;                      // 如果needle比haystack还要长

                // 只要有一个不相同就退出检索
                if(needle[i] != haystack[j])    break;
            }

            // 没有检索完 needle，说明与 needle 不是全部相同
            if(i != strlen(needle)){
                index = -1;                             // 与 needle 不同，假设失败
                i = 0;
                j = tmp;
            }
        }
        j++;
    }

    return index;
}
