#include <stdbool.h>
#include <limits.h>
bool increasingTriplet(int* nums, int numsSize) {
    if (numsSize < 3) return false;
    int firstSmallest = INT_MAX;
    int secondSmallest = INT_MAX;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < secondSmallest && nums[i] < firstSmallest) firstSmallest = nums[i];
        else if (nums[i] > firstSmallest && nums[i] < secondSmallest) secondSmallest = nums[i];
        else if (nums[i] > firstSmallest && nums[i] > secondSmallest) return true;
        
    }
    return false;
}
