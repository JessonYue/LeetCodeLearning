//
// Created by DF on 2020/6/2.
//

#ifndef LEETCODELEARNING_SECOND_TEST_H
#define LEETCODELEARNING_SECOND_TEST_H

using namespace std;

class second_test {


    int step1 = 1;
    int step2 = 2;

    int step_size = 5;

    int method_count = 1;

    if(step_size<1){
        return 0;
    }

    /**
     * 我的想法是先区分step_size 的奇数偶数
     *
     */
    //如果是奇数那么的话 从只有一个step1 到有 （step_size-1）/2个  step1   1+（ step_size-1）/2种方法
    //i = step1
    for (
    int i = 1, i
    <=
    step_size;
    i += 2){
        count << method_count << count;
        for (i1 = 0; i1 < i; i++) {
            count << ". +1阶" << count;
            for (j = 0; j < step_size - i / 2; j++) {
                count << "+ 2 阶 " << count;
            }
        }
        method_count++;
    }

    //如果是偶数那么的话 从有step_size/2 个 step2 到没有  step2 就是 有  step_size/2种方法
    //i = step2
    for (
    int i = 2, i
    <=
    step_size;
    i += 2){
        count << method_count << count;
        for (i1 = 0; i1 < i; i += 2) {
            count << ". +2阶" << count;
            for (j = 0; j < step_size - i / 2; j++) {
                count << "+ 1 阶 " << count;
            }
        }
        method_count++;
    }

    /**
     * 整合将奇偶数放在一起循环 最外层step最大数  第二层
     */
    for(
    int step = 1;
    i <=
    step2;
    i ++){
        for (int i = step, i <= step_size;
        i += 2){
            count << method_count << count;
            for (i1 = 0; i1 < i; i += 2) {
                count << ". +2阶" << count;
                for (j = 0; j < step_size - i / 2; j++) {
                    count << "+ 1 阶 " << count;
                }
            }
            method_count++;
        }
    }

};


#endif //LEETCODELEARNING_SECOND_TEST_H
