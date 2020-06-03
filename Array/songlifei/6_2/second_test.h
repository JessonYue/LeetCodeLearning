//
// Created by DF on 2020/6/2.
//

#ifndef LEETCODELEARNING_SECOND_TEST_H
#define LEETCODELEARNING_SECOND_TEST_H

using namespace std;

//解题过程越解越蒙后面参考大佬的思路是斐波那契
//感觉自己对算法还是懵逼没经验 希望汲取经验下次找到门道
int fbnq(int n){

    if(n<3){
        return n ;
    }

    return fbnq(n-1)+fbnq(n-2);

}


int main() {

    int step_size = 4 ;

    int method = fbnq(step_size);

    std::cout << method << endl ;
    return 0;
}
