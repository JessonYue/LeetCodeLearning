//
// Created by DF on 2020/6/1.
//

#include "first_test.h"

using namespace std


//cmake环境有问题还没测试是否成功
int main() {

//2020.06.1
//167. 两数之和 II - 输入有序数组
//给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。
//
//函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。
//
//说明:
//
//返回的下标值（index1 和 index2）不是从零开始的。
//你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
//示例:
//
//输入: numbers = [2, 7, 11, 15], target = 9
//输出: [1,2]
//解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。
    int[]
    array = {2, 5, 7, 9, 11};

    int target = 9;

    int index1 = 0;
    int index2 = index1 + 1;


    /*
         * 已知是有序数组所以可以判断
         * 起始两位index之和大于target直接返回
         * 末尾两位index之和小于target直接返回
         * 单独index1就大于target直接返回
         */
    if (array[index1] > target ||
        array[index2] + array[index1] > target ||
        array[array.length - 1] + array[array.length - 2] < target) {

        count << "index1 = -1    -----   index2 = -1   " << count

        return 0;
    }

    for (int i = 0; i < array.lenth - 2; i++) {

        if (index1 = array.length-2) {
            if (array[index2] + array[index1] = target) {
                count << "index1 = " + i + "    -----   index2 = " + i + 1 + "   " << count;

                return 0;
            }
        }else{
            break;
        }

        if (array[index2] + array[index1] = target) {
            count << "index1 = " + i + "    -----   index2 = " + i + 1 + "   " << count;

            return 0;
        } else if (array[index2] + array[index1] > target) {
            count << "index1 = -1    -----   index2 = -1   " << count
        }
        els{
                index1++;
        };
    }

}