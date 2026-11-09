#include <stdlib.h>
#include <stdio.h>

void rotate(int* nums, int numsSize, int k) {
    int num_rotated[100000] = {0};
    for (int i=0; i<numsSize; i++) {
        num_rotated[(i+k)%numsSize] = nums[i];
    }
    for (int i = 0; i<numsSize; i++) {
        nums[i] = num_rotated[i];
    }
}

