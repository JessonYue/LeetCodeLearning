#include <iostream>

using namespace std;

int indexOf(string source, string target) {
    if (target.length() == 0 && source.length() == 0) {
        return 0;
    } else if (target.length() == 0 && source.length() != 0) {
        return 0;
    } else if (target.length() != 0 && source.length() == 0) {
        return -1;
    }

    int sourceLength = source.length();
    int targetLength = target.length();

    //确定第一个元素的位置 然后循环对比
    //如果循环对比失败 则继续确定第一个元素的位置
    char first = target[0];
    int maxCycleNumber = sourceLength - targetLength;
    for (int i = 0; i <= maxCycleNumber; ++i) {
        if (source[i] != first) {
            while (++i <= maxCycleNumber && source[i] != first) {}
        }

        if (i <= maxCycleNumber) {
            //j为下一个要对比的字符
            //为什么从1开始？因为上面找first的时候已经对比过第0位了
            //走到这里的时候，第0位肯定是相等的，所以直接对比下一位
            int j = i + 1;
            //end为最小需要循环的次数
            int end = j + targetLength - 1;
            //为什么从1开始？道理跟上面的j一样
            for (int k = 1; j < end && source[j] == target[k]; j++, k++) {}

            //j==end说明循环正常结束，如果source[j]跟target[k]有不等的地方，那不可能j==end
            //故而如果相等，说明找到了那个相等的字符串
            if (j == end) {
                return i;
            }
        }
    }
    return -1;
}

int main() {
    string haystack = "hello";
    string needle = "llo";
    cout << indexOf(haystack, needle) << endl;
    return 0;
}




