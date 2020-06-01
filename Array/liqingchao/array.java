	/**
     * 2020.06.1
     * 167. 两数之和 II - 输入有序数组
     * 给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。
     * <p>
     * 函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。
     * <p>
     * 说明:
     * <p>
     * 返回的下标值（index1 和 index2）不是从零开始的。
     * 你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
     * 示例:
     * <p>
     * 输入: numbers = [2, 7, 11, 15], target = 9
     * 输出: [1,2]
     * 解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。
     */
    public void numCount(int[] num, int sum) {
        // 已知有序数组，且唯一答案，所以可以两个指针前后一起走，如果第一个加最后一个 和小于sum，则移动前面的指针，如果大于移动后面的指针，如果相等返回

        int left = 0;
        int right = num.length - 1;

        while (left < right) {
            if (num[left] + num[right] == sum) {
                System.out.println("[" + left + "," + right + "]");
                return;
            } else if (num[left] + num[right] < sum) {
                left++;
            } else if (num[left] + num[right] > sum) {
                right--;
            }
        }
        System.out.println("不存在两个数相加等于"+sum);
    }