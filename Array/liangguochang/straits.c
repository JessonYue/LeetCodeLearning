//
// Created by GuoChang Liang on 2020-06-02.
//

#include <stdio.h>

long stairs(int target) {

    if (target < 1) {

        return 0;

    }

    if (target == 1) {

        return 1;

    } else if (target == 2) {

        return stairs(1) + 1;

    } else {

        return stairs(target - 2) + stairs(target - 1);

    }

}


int main() {

    int target = 3;

    long count = stairs(target);

    printf("count %ld\n", count);

    return 0;
}