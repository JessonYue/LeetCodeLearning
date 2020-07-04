//
// Created by hasee on 2020/7/4.
//

#include "PageReplace.h"
#include<iostream>

using namespace std;

/**
 * 查找页面是否在物理块中，此处可以使用Set优化
 * @param physicalPage
 * @param physicalPageCount
 * @param address
 */
int find(const PhysicalPage *const physicalPage, int physicalPageCount, int address) {
    int i = 0;
    for (; i < physicalPageCount; ++i) {
        if (physicalPage[i].num == address) {
            return i;//找到了
        }
    }
    return -i;//没有找到页面
};

void fifo(const int physicalPageCount, const int *const addressSequence, int sequenceCount) {
    int error = 0;
    PhysicalPage physicalPage[physicalPageCount];
    for (int i = 0; i < sequenceCount; i++) {
        //查找是否已经缓存在物理页面中
        int ret = find(physicalPage, physicalPageCount, addressSequence[i]);
        if (ret < 0) {
            int replacePageIndex = (error) % physicalPageCount;
            physicalPage[replacePageIndex].num = addressSequence[i];
            cout << " error = " << ++error << ";replace index =  " << replacePageIndex << endl;
        }
    }
}


int main() {
    int addressSequence[20] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    fifo(4, addressSequence, 20);
}