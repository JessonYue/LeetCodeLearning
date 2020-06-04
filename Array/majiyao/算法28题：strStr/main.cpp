#include <iostream>
#include <string>

using namespace std;

int strStr(string haystack, string needle);

int main() {
    cout << "Hello, World!" << endl;
    string strOne = "hellomajiyaoworld";
    string strTwo = "majiyao";
    int value = strStr(strOne, strTwo);
    cout << "value is " << value << endl;
    return 0;
}

int strStr(string haystack, string needle) {
    if (needle == "") {
        return 0;
    }
    if (haystack == "") {
        return -1;
    }
    int lengthH = haystack.size();
    int lengthN = needle.size();
    for (int i = 0; i < lengthH - lengthN + 1; ++i) {
        //c++中的substr字符串截取函数，第一个参数表示从哪个位置开始截取，第二个参数表示截取的长度
        string strValue = haystack.substr(i, lengthN);
        cout << "strValue is " << strValue << endl;
        if (strValue == needle) {
            return i;
        }
    }
    return -1;
}

