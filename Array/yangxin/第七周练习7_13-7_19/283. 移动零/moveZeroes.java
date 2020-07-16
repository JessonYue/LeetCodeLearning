/**
     * 283. 移动零
     * 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
     */
public void moveZeroes(int[] nums) {
        if (nums == null) {
            return;
        }
        int tmp;
        for (int i = 0, tail = 0; i < nums.length; i++) {
            if (nums[i] != 0) {
                tmp = nums[i];
                nums[i] = nums[tail];
                nums[tail++] = tmp;
            }
        }
    }