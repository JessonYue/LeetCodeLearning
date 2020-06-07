**最近一直在寻找面试机会 ，发现现在的面试太难了，都要考察算法，并且都挂在算法题上，并且自己的Android 知识也很薄弱不成体系。我在内心发出感慨太难了。现在太难了！！！**

**不知道现在说什么好，我只能硬着头皮往前冲！！！**



## 题目一：https://leetcode-cn.com/problems/sort-characters-by-frequency/

## 题目二. 字符串字符去重并不破坏原来的顺序

#### 思路1：

1. 将字符串变成 char Array；
2. 遍历 char Array，依次放入 ArrayList，在 add 的同时判断 当前已经方法 list 中是否包含 当前正要放入的 字符，不存在放入，存在不方入。
3. 遍历得到的 List 集合。StringBuffer append List 元素，最后 toString。

```java
public void deduplicate(String str){
	ArrayList<Character> temp = new ArrayList<>()
    char[] charArray = str.toCharArray();
    
    for(int i = 0;i < charArray.length; i++){
        char c = charArray[i];
        if(!temp.contains(c)){
            temp.add(c);
        }
    }
    StringBuffer sb = new StringBuffer();
    for(char c:temp){
        sb.append(c);
    }
    System.out.println(sb.toString());
}
```

#### 思路二：利用 Set 集合的去重性

##### TreeSet 会排序

##### HashSet 由于 散列函数的问题 会影响元素的顺序

##### LinkedHashSet

```java
public void deduplicate(String str){
	LinkedHashset<Character> set = new LinkedHashset<>();
    char[] charArray = str.toCharArray();
    for(char c:charArray){
        set.add(c);
    }
    
    StringBuffer sb = new StringBuffer();
    for(char c:set){
        sb.append(c);
    }
    System.out.println(sb.toString())
}
```



## 题目三：两个字符串进行求和

![image-20200607113114257](https://note-austen-1256667106.cos.ap-beijing.myqcloud.com/2020-06-07-033117.png)

```java
public String sumLargeInt(Stirng a,String b){
    char[] aCharArray = a.toCharArray();
    char[] bCharArray = a.toCharArray();
    int lengthA = a.length();
    int lengthB = b.lenghth();
    
    
   
}
```
