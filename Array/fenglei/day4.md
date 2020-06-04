```
2020.06.4
面试题 10.01. 合并排序的数组 //https://leetcode-cn.com/problems/sorted-merge-lcci/
给定两个排序后的数组 A 和 B，其中 A 的末端有足够的缓冲空间容纳 B。 编写一个方法，将 B 合并入 A 并排序。

初始化 A 和 B 的元素数量分别为 m 和 n。

示例:

输入:
A = [1,2,3,0,0,0], m = 3
B = [2,5,6],       n = 3

输出: [1,2,2,3,5,6]
说明:

A.length == n + m
```

##### JAVA

```java
// 一开始想到的暴力解法
  
	public void merge(int[] A, int[] B, int m, int n) {
		for (int i = n; i > 0; i--) {
			A[m + i - 1] = B[i - 1];
		}

		for (int i = 1; i < A.length; i++) {
			for (int j = i; j > 0; j--) {
				if (A[j] < A[j - 1]) {
					int temp = A[j - 1];
					A[j - 1] = A[j];
					A[j] = temp;
				}
			}
		}
	}

执行用时 内存消耗 
 3 ms		39.2 MB

  
// 通过 leetCode 借鉴的改进写法
// 双指针倒序插入
  public void merge(int[] A, int[] B, int m, int n) {
		while (m > 0 && n > 0) {
			int a = A[m - 1];
			int b = B[n - 1];
			if (a > b) {
				A[m + n - 1] = a;
				m--;
			} else {
				A[m + n - 1] = b;
				n--;
			}
		}
		for (int i = 0; i < n; i++) {
			A[i] = B[i];
		}
	}

执行用时 内存消耗 
 0 ms		39.8 MB



```



##### C

```c
void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    while (m > 0 && n > 0){
        if (A[m - 1] > B[n -1]){
            A[m + n - 1] = A[m - 1];
            m--;
        } else {
            A[m + n - 1] = B[n -1];
            n--;
        }
    }
    for (int i = 0; i < n; i++) {
        A[i] = B[i];
    }
}


执行用时 内存消耗 
 4 ms		5.6 MB
```

