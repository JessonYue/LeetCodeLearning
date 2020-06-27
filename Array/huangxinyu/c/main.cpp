#include <iostream>
#include "alo.h"
#include "StackByQueue.h"
#include <vector>
int main() {
    const char *s = "{[]}";
    printf("s size = %d", isValidBrackets(s));
    return 0;
}
