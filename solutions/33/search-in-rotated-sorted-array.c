int binarysearch(int left, int right, int target, int* nums) {
    if (nums[right] == target) return right;
    else if (nums[left] == target) return left;
    if ((right - left) <= 1) return -1;
    int index = left + (right - left) / 2;
    if (nums[index] == target) return index;
    else {
        if (nums[left] < nums[index])  {
            if (target >= nums[left] && target <= nums[index]) {
                return binarysearch(left, index, target, nums);
            } else {
                return binarysearch(index, right, target, nums);
            }
        } else {
            if (target >= nums[index] && target <= nums[right]) {
                return binarysearch(index, right, target, nums);
            } else {
                return binarysearch(left, index, target, nums);
            }
        }
    }
}
int search(int* nums, int numsSize, int target) {
    return binarysearch(0, numsSize-1, target, nums);
}
