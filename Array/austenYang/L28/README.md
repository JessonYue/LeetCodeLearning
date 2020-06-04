### https://leetcode.com/problems/implement-strstr/

#### 思路一：

自己在没有看题解的情况下思考出来的思路

字符串逐一比较

在`haystack` 中匹配 `needle` 字符

1. 先找到 `haystack` 中第一与  `needle`  第一相等的字符，才有可能相等。

2. 找到后 `haystack` 从相等字符位置往后 length 长度，length 与 `needle` 相等。

3. 比较 截取到的字符串与 `needle` 是否相等 字符串 `equals` 。

```java
public static int strStr1(String haystack, String needle) {
        if ("".endsWith(needle)) {
            return 0;
        }
        char[] haystackCharArray = haystack.toCharArray();
        char[] needleCharArray = needle.toCharArray();
        int length = needleCharArray.length;
        char c = needleCharArray[0];
        for (int i = 0; i < haystackCharArray.length; i++) {
            char cc = haystackCharArray[i];
            if (c == cc && haystackCharArray.length - i >= length) {
                String substring = haystack.substring(i, i + length);
                if (substring.equals(needle)) {
                    return i;
                }
            }
        }
        return -1;
    }

```

#### 思路二：

#### 子串逐一比较 - 线性时间复杂度

<img src="https://note-austen-1256667106.cos.ap-beijing.myqcloud.com/2020-06-03-160817.png" alt="image-20200604000811739" style="zoom:50%;" />

最直接的方法 - 沿着字符换逐步移动滑动窗口，将窗口内的子串与 needle 字符串比较。

**PS:与自己实现的方式基本一致**

**这里有个很实用的思考就是，怎么减少了比较的次数**

`int L = haystack.length()`

`int n = neele.length()`

`L - n + 1` **对比次数和 n 的长度有关系** 这里的这个思路需要熟悉

```java
public static int strStr2(String haystack, String needle){
        int L = haystack.length(), n = needle.length();
        for (int i = 0; i < L - n + 1; i++) {
            if (haystack.substring(i,i + n).equals(needle)) {
                return i;
            }
        }
        return -1;
    }
```

