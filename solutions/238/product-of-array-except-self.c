#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int* product = calloc(numsSize, sizeof(int));
    *returnSize = numsSize;

    int leftAccumulte = nums[0];
    int rightAccumulate = nums[numsSize-1];
    product[0] = 1;

    for (int l = 1; l < numsSize; l++) {
        product[l] = leftAccumulte;
        leftAccumulte *= nums[l];
    }
    for (int r = numsSize - 2; r >= 0; r--) {
        product[r] *= rightAccumulate;
        rightAccumulate *= nums[r];
    }
    
    return product;
}
