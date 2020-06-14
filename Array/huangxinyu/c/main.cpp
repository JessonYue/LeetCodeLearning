#include <iostream>
#include "alo.h"
#include "StackByQueue.h"
int main() {
    StackByQueue stackByQueue ;
    stackByQueue.push(1);
    stackByQueue.push(2);
    stackByQueue.push(3);
    stackByQueue.pop();
    printf("top = %d", stackByQueue.top());
    return 0;
}
