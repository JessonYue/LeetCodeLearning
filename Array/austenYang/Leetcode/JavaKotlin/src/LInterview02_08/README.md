思路一：

![image-20200706224651830](https://note-austen-1256667106.cos.ap-beijing.myqcloud.com/2020-07-06-144653.png)

快指针 `fast` ，慢指针 `slow` ，都从 A 点出发。

快指针走两边，满指针走一步。

必定会在圈上相遇，假设在 C 点相遇。

当 slow 走到 B 点的时候，fast 肯定距离 B 点有 y，并且 fast 在圈上已经走了 x 步了。(这里的 x 可能在圈上余 x)。

那么  x + y = 圈长。

那么他们相遇后，让 fast 从 A 点开始 一步走，slow 不变。

fast 走 x，slow 从 c 点走 x 那么 必定在 B 点相遇。









