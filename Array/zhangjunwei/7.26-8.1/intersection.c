
#include <stdlib.h>

#define MAX_SIZE 1024

int *intersection(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize) {
    int *hash = (int *) calloc(MAX_SIZE, sizeof(int));
    int *result = (int *) calloc(MAX_SIZE, sizeof(int));

    for (int i = 0; i < nums1Size; ++i) {
        if (hash[nums1[i]] == 0)
            hash[nums1[i]]++;
    }
    *returnSize = 0;
    for (int j = 0; j < nums2Size; ++j) {
        if (hash[nums2[j]] > 0) {
            hash[nums2[j]]--;
            result[(*returnSize)++] = nums2[j];
        }
    }
    free(hash);
    return result;
}