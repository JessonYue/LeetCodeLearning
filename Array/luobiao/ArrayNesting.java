/**
索引从0开始长度为N的数组A，包含0到N - 1的所有整数。找到最大的集合S并返回其大小，其中 S[i] = {A[i], A[A[i]], A[A[A[i]]], ... }且遵守以下的规则。

假设选择索引为i的元素A[i]为S的第一个元素，S的下一个元素应该是A[A[i]]，之后是A[A[A[i]]]... 以此类推，不断添加直到S出现重复的元素。

 

示例 1:

输入: A = [5,4,0,3,1,6,2]
输出: 4
解释: 
A[0] = 5, A[1] = 4, A[2] = 0, A[3] = 3, A[4] = 1, A[5] = 6, A[6] = 2.

其中一种最长的 S[K]:
S[0] = {A[0], A[5], A[6], A[2]} = {5, 6, 2, 0}
 

提示：

N是[1, 20,000]之间的整数。
A中不含有重复的元素。
A中的元素大小在[0, N-1]之间。
通过次数6,286提交次数10,713

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/array-nesting
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

解题思路：遍历整个数组，从第一个开始查询，找到对应的环，如果发现该环的大小大于数组的一半长度，就直接返回，如果不是则count+1，再次循环，再次得到一个环形个数，与上次环个数比较，取最大的哪个值

**/

class Solution {
    public int arrayNesting(int[] nums) {
        int tempMax = 0;
        int max = 0;
        int length = nums.length;
        Queue<Integer> queue = new LinkedList<Integer>();
        int count = 0;
        int tempValue = 0;
        for (int i = count; i < length; i++) {
            if (!queue.isEmpty()) {
                if (queue.peek() == nums[tempValue]) {
                    if (tempMax > (length+1)/2) {
                        return tempMax;
                    } else {
                        count = count + 1;
                        i = count - 1;
                        max = tempMax > max ? tempMax : max;
                        queue.clear();
                        tempMax = 0;
                        tempValue = count;
                        continue;
                    }
                } else {
                    tempValue = nums[tempValue];
                    queue.add(tempValue);
                }
            } else {
                tempValue = nums[i];
                queue.add(tempValue);
            }
            tempMax++;

        }
        max = tempMax > max ? tempMax : max;
        return max;
    }
}