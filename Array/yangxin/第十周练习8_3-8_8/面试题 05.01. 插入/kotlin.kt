 /**
     * 面试题 05.01. 插入
     * 插入。给定两个32位的整数N与M，以及表示比特位置的i与j。
     * 编写一种方法，将M插入N，使得M从N的第j位开始，到第i位结束。
     * 假定从j位到i位足以容纳M，也即若M = 10 011，那么j和i之间至少可容纳5个位。
     * 例如，不可能出现j = 3和i = 2的情况，因为第3位和第2位之间放不下M
     */
    fun insertBits(N: Int, M: Int, i: Int, j: Int): Int {
        var n = N
        var m = M
        for (k in i..j) {
            n = n.and((1 shl k).inv())
        }

        m = m.shl(i)
        return n or m
    }