# [28. 实现 strStr()](https://leetcode-cn.com/problems/implement-strstr/)

实现 strStr() 函数。

给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

**示例 1:**

```
输入: haystack = "hello", needle = "ll"
输出: 2
```

**示例 2:**

```
输入: haystack = "aaaaa", needle = "bba"
输出: -1
```

说明:

当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。

对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。



## 我的第一解决方案，快！

```
class Solution {
    public int strStr(String haystack, String needle) {
        return haystack.indexOf(needle);
    }
}
```

很好奇`String.indexOf()`是怎么实现的，于是看`String.indexOf()`的源码，仿照实现:

以`String haystack = "hello";`和`String needle = “ll”`为例

```java
public int strStr(String haystack, String needle) {
        int sourceLength = haystack.length();
        int targetLength = needle.length();
        if(sourceLength == 0){
            return targetLength == 0? sourceLength:-1;
        }
        if(targetLength == 0){
            return 0;
        }

        char first = needle.charAt(0);
        int max = (sourceLength - targetLength);
        for(int i =0;i<=max; i++){
            if (haystack.charAt(i)!= first) {
                //寻找第一个字符
                while (++i <= max && haystack.charAt(i) != first);
            }
            if (i <= max) {
                int j = i + 1;
                int end = j + targetLength - 1;
                for (int k = 1; j < end && haystack.charAt(j)
                        == needle.charAt(k); j++, k++);

                if (j == end) {
                    /* Found whole string. */
                    return i;
                }
            }
        }
        return -1;
    }
```

刚开始一直对` while (++i <= max && haystack.charAt(i) != first);` 不理解,而且为啥`i=0`的时候经过while后为啥变成了`i=2`?

其实就是执行了两次while,第一次while里的条件都为true，然后需要在执行一次while循环，当第二次的时候先执行`++i <= max`为`true`但是`haystack.charAt(i) != first`为`flase`，所以while的整体条件为`false`跳出while循环，此时`i=2`了。



这个while循环就是在寻找字符串的第一个字符。

## 使用String.substring()方法

使用substring根据目标字符串截取出源字符串进行比对

```java
public int strStr(String haystack, String needle) {
        int sourceLength = haystack.length();
        int targetLength = needle.length();
        int max = sourceLength - targetLength;
        for(int i =0;i<=max;i++){
            String substring = haystack.substring(i,i+ targetLength);
            if(substring.equals(needle)){
                return i;
            }
        }
        return -1;
    }
```

