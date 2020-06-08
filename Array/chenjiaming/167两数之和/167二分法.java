class Solution {
    public int[] twoSum(int[] numbers, int target) {
        if(numbers == null || numbers.length < 2 || target < numbers[0] + numbers[1] || target > numbers[numbers.length - 2] + numbers[numbers.length - 1]){
            return null;
        }
        /*缩小查找范围,找到缩小范围的结束边界*/
        int mid = 0;
        if(target - numbers[0] >= numbers[numbers.length - 1]){
            mid = numbers.length - 1;
        }else{
            int i = 0,j = numbers.length - 1,temp = target - numbers[0];
            while(i <= j){
                mid = (i + j) / 2;
                if(numbers[mid] > temp){
                    j = mid - 1;
                } else if(numbers[mid] < temp){
                    i = mid + 1;
                } else break;
            }
            /*二分结束时mid可能指向第一个大于temp的数,也可能指向第一个小于temp的数*/
            if(numbers[mid] > temp){
                mid -= 1;
            }
        }
        /*在缩小的范围内用双指针遍历一次数组获得结果*/
        for(int i = 0, j = mid; i < j;){
            if(numbers[i] + numbers[j] > target){
                --j;
            } else if(numbers[i] + numbers[j] < target){
                ++i;
            } else{
                return new int[]{i +  1, j + 1};
            }
        }
        return null;
    }
}

作者：xie-5t
链接：https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/solution/yi-ge-xin-de-zhi-xing-yong-shi-0msjavati-jiao-zhon/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。