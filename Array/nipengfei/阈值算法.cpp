#include <iostream>
#include <vector>
using namespace std;

int numOfSubarrays(vector<int>& arr,int k,int threshold){
    int ans=0;//记录最终结果
    int sum=0;//记录每个子数组元素和

    for (int i = 0; i < k; ++i) {
        sum += arr[i];
    }
    if(sum >= threshold*k) ans++;

    int len = arr.size();

    for (int j = 0; j < len - k; ++j) {
        sum -= arr[j];
        sum += arr[k+j];
        if(sum >= threshold*k) ans++;
    }
    return ans;
}

void reverseLinkedList(Node* head){

}

int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<int> t;
    t.push_back(2);
    t.push_back(2);
    t.push_back(2);
    t.push_back(2);
    t.push_back(5);
    t.push_back(5);
    t.push_back(5);
    t.push_back(8);
    printf("%d", numOfSubarrays(t,3,4));
    return 0;
}
