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
    int
            array[] = {2, 5, 7, 9, 11};

    int target = 14;

    int index1 = 0;
    int index2 = 0;
    int size = sizeof(array) / sizeof(array[0]);

    for (int i = 0; i < size - 1; i++) {
        for (int i1 = 0; i1 < size; i1++) {
            if (array[i] + array[i1] == target) {
                std::cout << "index1 = " << i << "    -----   index2 =" << i1 << "   " << endl;
                return 0;
            }
        }
    }

    return 0;
}

}