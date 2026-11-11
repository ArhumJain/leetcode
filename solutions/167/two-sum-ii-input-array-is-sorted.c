/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int left = 0;
    int right = numbersSize-1;
    while (true) {
        int sum = numbers[left] + numbers[right];
        if (sum > target) {
            right--;
        } else if (sum < target) {
            left++;
        } else if (sum == target) {
            int* indices = malloc(2 * sizeof(int));
            *returnSize = 2;
            indices[0] = left+1;
            indices[1] = right+1;
            return indices;
        }
    }
}
