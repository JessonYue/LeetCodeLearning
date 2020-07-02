//
// Created by 张俊伟 on 2020/6/30.
//
#include <string>
#include <iostream>
#include <algorithm>
#include <stack>

/***
 * 最长公共子序列(Longest Common Subsequence,lcs)
 * 特点：分析是从大到小，写代码是从小到大
计算过程中会把结果都记录下，最终结果在记录中找到

 应用场景：   相似度的比较:计算生物学DNA对比(亲子验证),百度云盘找非法数据
            图形相似处理,媒体流的相似比较,百度知道,百度百科,WEB页面中找非法言论

            ababcabcbababcaba caba
                         abab caba
            ababcabcbababcaba
                          aba b
            ababcabcbababcab a
                        abab


*/
static int max(int i1, int i2) {
    return i1 > i2 ? i1 : i2;
}

char const *get_lcs(const char *str1, const char *str2) {
    int len1 = strlen(str1) + 1;
    int len2 = strlen(str2) + 1;
    //int arr[len2+1][len1+1]
    int **arr = static_cast<int **>(malloc(sizeof(int *) * len2));
    if (arr == nullptr) {
        std::cout << "arr memory alloc failed" << std::endl;
        return nullptr;
    }
    for (int i = 0; i < len2; ++i) {
        *(arr + i) = static_cast<int *>(malloc(sizeof(int) * len1));
        if (*arr != nullptr) {
            memset(*arr, 0, len1);
        }
    }

    for (int j = 1; j < len2; j++) {
        for (int i = 1; i < len1; i++) {
            //相同的取左上加1,不同取 上和左 中的最大值max(left,top)
            if (str1[i - 1] == str2[j - 1]) {
//                arr[i][j] = arr[i - 1][j - 1] + 1;
                *(*(arr + i) + j) = *(*(arr + i - 1) + j - 1) + 1;
            } else {
                *(*(arr + i) + j) = max(*(*(arr + i - 1) + j), *(*(arr + i) + j - 1));
//                arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
            }
        }
    }

    //打印
    for (int j = 0; j < len2; ++j) {
        for (int i = 0; i < len1; ++i) {

            std::cout << arr[i][j] << " ";
        }
        std::cout << "" << std::endl;
    }
    std::stack<char> st;
    int i = len1;
    int j = len2;
    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            st.push(str1[i - 1]);
            i--;
            j--;
        } else {//注意数组和String中的位置有一位差
            if (arr[i - 1][j] > arr[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }
    }
//    int i = len1 - 1;
//    int j = len2 - 1;
//    while (i >= 0 && j >= 0) {
//        if (str1[i] == str2[j]) {
//            st.push(str1[i]);
//            i--;
//            j--;
//        } else {//注意数组和String中的位置有一位差
//            if (arr[i + 1 - 1][j + 1] > arr[i + 1][j + 1 - 1]) {
//                i--;
//            } else {
//                j--;
//            }
//        }
//    }
    char *res = static_cast<char *>(malloc(sizeof(char) * st.size()));
    memset(res, 0, st.size());
    i = 0;
    while (!st.empty()) {
//        *(res+i) = st.top();
        res[i++] = st.top();
        st.pop();
    }

    for (int i = 0; i < len2; ++i) {
        free(*(arr + i));
    }
    free(arr);
    return res;
}