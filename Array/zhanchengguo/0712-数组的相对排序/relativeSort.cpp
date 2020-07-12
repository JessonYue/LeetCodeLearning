#include <iostream>
#include <stack>
#include <list>
#include <vector>

using namespace std;

vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2);

int main() {
    int a[] = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19};
    int b[] = {2, 1, 4, 3, 9, 6};
    vector<int> aa(a, a + 11);
    vector<int> bb(b, b + 6);
    vector<int> c = relativeSortArray(aa, bb);
    for (int i = 0; i < c.size(); i++) {
        printf("value is %d\n", c[i]);
    }
    return 0;
}

/**
 * 思路：类似冒泡排序法的方法。把arr1中的arr2数按arr中的顺序往前冒，然后后面直接sort
 * @param arr1
 * @param arr2
 * @return
 */
vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2) {
    int num = 0;
    for (int i = 0; i < arr2.size(); ++i) {
        for (int j = 0; j < arr1.size(); ++j) {
            if (arr1[j] == arr2[i]) {
                swap(arr1[j], arr1[num]);
                num++;
            }
        }
    }
    sort(arr1.begin() + num, arr1.end());
    return arr1;
}
