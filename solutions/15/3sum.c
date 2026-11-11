#include <stdlib.h>

int compare(const void* a, const void* b) {
    const int* A = (const int*) a;
    const int* B = (const int*) b;
    if (*A < *B) return -1;
    if (*A > *B) return 1;
    return 0;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) { 
    qsort(nums, numsSize, sizeof(int), compare);
    int leftIndex = 0;
    int middleIndex = 1;
    int rightIndex = numsSize-1;
    int** output = malloc((size_t)numsSize*numsSize*sizeof(int *));
    int outputRows = 0;
    while (true) {
        if (middleIndex >= numsSize) {
            *returnSize = outputRows;
            *returnColumnSizes = malloc(outputRows * sizeof(int));
            for (int i=0; i<outputRows; i++) (*returnColumnSizes)[i] = 3;
            return output;
        }
        int sum = nums[leftIndex] + nums[middleIndex] + nums[rightIndex];
        if (middleIndex == rightIndex) {
            int currLeft = nums[leftIndex];
            while (leftIndex < numsSize && nums[leftIndex] == currLeft) {
                leftIndex++;
            }
            middleIndex = leftIndex + 1;
            rightIndex = numsSize-1;
        } else if (sum == 0) {
            outputRows++;
            output[outputRows-1] = calloc(3, sizeof(int));
            output[outputRows-1][0] = nums[leftIndex];
            output[outputRows-1][1] = nums[middleIndex];
            output[outputRows-1][2] = nums[rightIndex];
            int currMiddle = nums[middleIndex];
            while (middleIndex < rightIndex && nums[middleIndex] == currMiddle) {
                middleIndex++;
            }
        } else if (sum < 0) {
            int currMiddle = nums[middleIndex];
            while (middleIndex < rightIndex && nums[middleIndex] == currMiddle) {
                middleIndex++;
            }
        } else if (sum > 0) {
            int currRight = nums[rightIndex];
            while (rightIndex > middleIndex && nums[rightIndex] == currRight) {
                rightIndex--;
            }
        }
    }    
}
