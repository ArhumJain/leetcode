#include <stdio.h>
int minSubArrayLen(int target, int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    int runningSum = 0;
    int minLen = -1;
    int left = 0;
    int right = 0;
    for (int i=0; i<numsSize; i++) {
        runningSum += nums[i];
        if (runningSum >= target) {
            right = i;
            minLen = i + 1;
            break;
        }
    }
    if (minLen == -1) return 0;
    while (left <= right) {
        if (runningSum >= target) {
            if (left == right) return 1;
            if (((right - left) + 1) < minLen) minLen = (right-left) + 1;
            runningSum -= nums[left];
            left++;
        } 
        else if (runningSum < target) {
            if (right != numsSize-1) {
                runningSum += nums[right+1];
                right++;
            }
            runningSum -= nums[left];
            left++;
        }
    }
    return minLen;
}

int main() {
    int nums[10] = {5,1,3,5,10,7,4,9,2,8};
    printf("%i\n", minSubArrayLen(15, nums, 10));
}
