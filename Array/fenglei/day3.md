```
2020.06.3
28. 实现 strStr() //https://leetcode-cn.com/problems/implement-strstr/
实现 strStr() 函数。

给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

示例 1:

输入: haystack = "hello", needle = "ll"
输出: 2
示例 2:

输入: haystack = "aaaaa", needle = "bba"
输出: -1
说明:

当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。

对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
```



##### Java

```java
class Solution {
    public int strStr(String haystack, String needle) {
        int needleSize = needle.length();
        int haySize = haystack.length();
		if (needleSize <= 0) {
			return 0;
		}
		char head = needle.charAt(0);
		for (int i = 0; i < haySize; i++) {
			char h = haystack.charAt(i);
			if (head == h) {
				// 如果相等就比其他的 char
				for (int j = 0; j < needleSize; j++) {
					int index  = i + j;
					if (index > haySize - 1) {
						return -1;
					}
					if (needle.charAt(j) != haystack.charAt(index)) {
						break;
					}
					if (j == needleSize - 1) {
						return i;
					}
				}
			}
		}
		return -1;
   }
}
```

通过时长

```
提交结果	执行用时	内存消耗		语言
通过			4ms			 38.5MB			java
```



##### C

```c
int strStr(char * haystack, char * needle){
    int nLen = strlen(needle);
    int hLen = strlen(haystack);
    if (nLen <= 0){
        return 0;
    }
    char first = needle[0];
    for (int i = 0; i < hLen; ++i) {
        char h = haystack[i];
        if (h == first){
            for (int j = 0; j < nLen; ++j) {
                int index = i + j;
                if (index > hLen - 1){
                    return -1;
                }
                if (needle[j] != haystack[index]){
                    break;
                }
                if (j == nLen -1){
                    return i;
                }
            }
        }
    }
    return -1;
}
```

通过时长

```
提交结果	执行用时	内存消耗		语言
通过			4ms			 5.6MB			 C
```

