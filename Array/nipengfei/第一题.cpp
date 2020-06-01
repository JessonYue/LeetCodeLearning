// CMakeProject1.cpp: 定义应用程序的入口点。
//路哥，您好！C之前就会一点点，还都忘了，不过我会努力的。

#include "CMakeProject1.h"

using namespace std;

int main()
{
	int numbers[] = {2,7,11,15};
	int tartget = 9;
	int index1 = -1;
	int index2 = -1;
	int size = sizeof(numbers) / sizeof(numbers[0]);
	for (size_t i = 0; i < size; i++)
	{
		//数组递增，以9为例，大于4就没意义了
		if (numbers[i] > tartget / 2) {
			break;
		}
		for (size_t j = 1; j < size; j++)
		{
			if ((numbers[i] + numbers[j]) == tartget) {
				index1 = i + 1;
				index2 = j + 1;
				break;
			}
		}
	}

	cout << "index1:"<< index1<< ",index2:"<< index2 << endl;
	system("pause");
	return 0;
}
