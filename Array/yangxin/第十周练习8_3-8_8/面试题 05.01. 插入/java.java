/**
     * 面试题 05.01. 插入
     * 插入。给定两个32位的整数N与M，以及表示比特位置的i与j。
     * 编写一种方法，将M插入N，使得M从N的第j位开始，到第i位结束。
     * 假定从j位到i位足以容纳M，也即若M = 10 011，那么j和i之间至少可容纳5个位。
     * 例如，不可能出现j = 3和i = 2的情况，因为第3位和第2位之间放不下M
     */
    public int insertBits(int N, int M, int i, int j) {
        int tmp;
        for (int k = i; k <= j; k++) {
            tmp = 1 << k;
            if ((N & tmp) > 0) {
                N -= tmp;
            }
        }
        M = M << i;
        return N | M;
    }