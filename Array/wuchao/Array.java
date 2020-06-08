class Solution {
    //leetcode 167
    //在原有头尾指针的基础上，加入二分查找，缩小start和end的范围
    public int[] twoSum(int[] numbers, int target) {
        int start = 0;
        int end = numbers.length-1;
        while(start<end-1){
            int middle = start + ((end-start)>>1);
            if(numbers[middle]<target){
                start = middle;
            } else {
                end = middle;
            }
        }
        start = 0;
        while(start<numbers.length-1&&end>=0){
            if(numbers[start]+numbers[end] == target){
                return new int[]{start+1,end+1};
            }
            if(numbers[start]+numbers[end]>target){
                int max = 0;
                if(start>end){
                    start--;
                } else {
                    end--;
                }
            } else {
                if(end>start){
                    start++;
                } else {
                    end++;
                }
            }
        }
        return new int[]{-1,-1};
    }

    //leetcode 70
    public int climbStairs(int n) {
        //最后如果剩1步，1步走完
        if(n==1){
            return 1;
        }
        //最后如果剩2步，可以1步1步走完，也可以2步走完
        if(n==2){
            return 2;
        }
        //表示走1步之后，n-1个台阶的走法，加上，走2步之后，n-2个台阶的走法
        return climbStairs(n-1) + climbStairs(n-2);
    }

    //leetcode 27
    //思路：头尾指针，头指针在等于该值的元素停下，尾指针在不等于该值的元素停下，交换两个元素，头指针向后移动一步，尾指针向前移动一步，直到头指针等于尾指针
    public int removeElement(int[] nums, int val) {
        if(nums.length==0){
            return 0;
        }
        int start = 0;
        int end = nums.length -1;
        while(start<end){
            if(nums[start]==val){
                if(nums[end]!=val){
                    swap(nums,start,end);
                    start++;
                }
                end--;
            } else {
                start++;
            }
        }
        //返回的是数组的长度需要下标+1;
        if(nums[start]==val){
            //说明前一个元素是数组删除完之后的最后一个元素
            return start;
        } else {
            //说明当前元素是数组删除完之后的最后一个元素
            return start+1;
        }
    }

    public void swap(int[] nums,int a,int b){
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }

    //三步问题
    //这道题我先用递归法求解，但有两个弊端，1.执行时间超时2.容易栈溢出
    //所以得要转换成动态规划的方式，根据之前的状态（n-1...1阶台阶多少种上楼的方式），来推导出当前的状态（n阶台阶有多少种上楼方式）
    //f(n) = f(n-1) + f(n-2) + f(n-3)即动态规划状态转移方程
    //加法产生的值可能溢出，导致结果可能出现负数，所以需要在加法运算之后做取模操作
    public int waysToStep(int n) {
        if(n==1){
            return 1;
        }
        if(n==2){
            return 2;
        }
        if(n==3){
            return 4;
        }
        // return waysToStep(n-1)+waysToStep(n-2)+waysToStep(n-3);
        int status1 = 1;
        int status2 = 2;
        int status3 = 4;
        int status = 0;
        for(int i=4;i<n+1;i++){
            status = ((status3 + status2)%1000000007 + status1)%1000000007;
            status1 = status2;
            status2 = status3;
            status3 = status;
        }
        return status;
    }
}
