// CMakeProject1.cpp: 定义应用程序的入口点。
//最近提测加搬家，耗了很大一部分精力，6月10号以后会再刷一遍，看答案，研究最优解

#include "CMakeProject1.h"

using namespace std;

int stairCount(int n) {
	if (n < 4) {
		return n;
	}
	return stairCount(n - 1) + stairCount(n - 2);
}

int main()
{
	cout << "爬到楼顶的方法数：" << stairCount(4) << endl;
	system("pause");
	return 0;
}