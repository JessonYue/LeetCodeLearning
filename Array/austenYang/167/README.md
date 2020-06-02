<img src="https://note-austen-1256667106.cos.ap-beijing.myqcloud.com/2020-06-02-165602.png" alt="image-20200603005558608" style="zoom:40%;" align="left" />

思路一：递归

爬楼梯一次只能迈一节或二节台阶. 假设一共N节台阶. 那么一共有多少种方法呢? 分析问题的关键: 最后一步迈了几个格子? 如果最后一步迈了一个格子: 前面所有步法的数量为f(N-1) 如果最后一步迈了两个格子: 前面所有步法的数量为f(N-2)

```java
一个人一次可以迈过一节楼梯, 或者两节楼梯
问 N节楼梯有多少种走法?
分析: 
1节楼梯有1种走法
2节楼梯有2种走法

3节楼梯的走法数量 = 2节楼梯的走法数量(最后一次走一步的数量) + 1节楼梯的走法数量(最后一次走两步的数量)
N节楼梯的走法数量 = N-1 节楼梯的走法数量 + N-2节楼梯的走法数量

f(N) = f(N-1) + f(N-2)
  
  
  // 递归实现
   public static int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
```

**但问题是 这个算法在 leetcode 提交没通过，消耗时间太多。**

思路二：

`f(N) = f(N-1) + f(N-2)`

为 n 个台阶的走发，`f(1) = 1` 、`f(2) = 2` 那么 就有

`f(3) = f(1) + f(2)`

`f(4)= f(3) + f(2)`

`f(5)= f(4) + f(3)`

这个代码思路好像更简单，前提是 得到公式 `f(n) = f(n -1)+ f(n -2)`

```java
    public int climbStairs(int n) {
         if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        int first = 1;
        int second = 2;
        int result = 0;
        for (int i = 3; i <= n; i++) {
            // f(n) = f(n-1) + f(n-2)
            // f(3) = f(2) + f(1)
            // f(4) = f(3) + f(2)
            // f(5) = f(4) + f(3)
            result = second + first;
            first = second;
            second = result;
        }

        return result;
    }
```

