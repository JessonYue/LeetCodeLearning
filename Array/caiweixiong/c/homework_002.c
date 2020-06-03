//
//  homework_002.c
//  BaseBuild
//
//  Created by mac on 2020/6/2.
//  Copyright © 2020 mingxi. All rights reserved.
//

#include <stdio.h>

// 爬楼梯，LeetCode第70题
void homework_002_070(void)
{
    int i;
    printf("输入目标阶梯数字：");
    scanf("%d", &i);
    int climbStairs_1(int target);
    printf("共有 %d 种爬楼梯方法\n" , climbStairs_1(i));
}

int climbStairs_1(int target)
{
    int climbStairs_2(int, int);
    return climbStairs_2(0, target);
}

int climbStairs_2(int current, int target)
{
    if(current > target)
        return 0;
    if(current == target)
        return 1;
    return climbStairs_2(current + 1, target) + climbStairs_2(current + 2, target);
}
