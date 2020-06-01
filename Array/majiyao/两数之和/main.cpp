#include <iostream>
#include <set>

void sumArray(int *array, int target);

using namespace std;


int main() {
    std::cout << "Hello, World!" << std::endl;

    int array[] = {2, 7, 11, 15};
    int target = 9;
    sumArray(array, 9);
    return 0;
}

void sumArray(int *array, int target) {
    set<int> s;
    int size = sizeof(array) / sizeof(int);
    for (int i = 0; i < size; ++i) {
        s.insert(array[i]);
    }
    for (int j = 0; j < size; ++j) {
        int result[2];
        int a = target - array[j];
        const set<int>::iterator &iterator = s.find(a);
        if (iterator != s.end()){
            cout<< " index value is "<< j + 1 << endl;
        }
    }
}
