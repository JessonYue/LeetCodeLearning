#include <stdio.h>

//思路同 java
int main() {
    int a[] = {1,2,3,0,0,0};
    int b[] = {2,5,6};
    int n = sizeof(a)/sizeof(a[0])+sizeof(b)/sizeof(b[0]);
    int c[n];
    for (int j = 0; j < sizeof(a)/sizeof(a[0]) ; ++j) {
        c[j] = a[j];
    }
    for (int k = 0; k < sizeof(b)/sizeof(b[0]) ; ++k) {
        c[sizeof(a)/sizeof(a[0])+k]= b[k];
    }
    for (int l = 0; l < sizeof(c)/sizeof(c[0]) ; ++l) {
        for (int m = l + 1; m < sizeof(c)/sizeof(c[0]); m++) {
            if (c[l] > c[m]) {
                int temp = c[l];
                c[l] = c[m];
                c[m] = temp;
            }
        }
    }
    for (int i = 0; i <sizeof(c)/sizeof(c[0]); ++i) {
        if (c[i]!=0){
            printf("%i\n",c[i]);
        }
    }
    return sizeof(c);

}

