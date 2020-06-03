// CMakeProject1.cpp: 定义应用程序的入口点。

#include "CMakeProject1.h";

using namespace std;

int strStr(string haystack, string needle) {
	if (needle.empty()) {
		return 0;
	}
	return haystack.find(needle);
}

int main()
{
	cout << "出现的位置：" << strStr("12345","") << endl;
	system("pause");
	return 0;
}