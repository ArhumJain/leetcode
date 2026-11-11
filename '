int singleNumber(int* nums, int numsSize) {
    unsigned int number = 0;
    for (int i=0; i<32; i++) {
        int count = 0;
        for (int j=0; j<numsSize; j++) {
            if ((1U << i) & nums[j]) {
                count++;
            }
        }
        if (count % 3 == 1) {
            number = number | (1U << i);
        }
    }
    return (int) number;
}
