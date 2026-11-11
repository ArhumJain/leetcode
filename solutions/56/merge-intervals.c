int compare(const void* A, const void* B) {
    const int** a = (const int**) A;
    const int** b = (const int**) B;
    if ((*a)[0] < (*b)[0]) return -1;
    if ((*a)[0] > (*b)[0]) return 1;
    return 0;
}
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    qsort(intervals, intervalsSize, sizeof(int**), compare);
    int curr = 0;
    int** merged = malloc(10000 * sizeof(int*));
    int mergedIndex = 0;
    for (int i = 0; i < intervalsSize; i++) {
        if (intervals[i][0] <= intervals[curr][1]) {
            intervals[curr][1] = fmax(intervals[curr][1], intervals[i][1]);
        } else {
            merged[mergedIndex] = malloc(2 * sizeof(int));
            merged[mergedIndex][0] = intervals[curr][0];
            merged[mergedIndex][1] = intervals[curr][1];
            curr = i;
            mergedIndex++;
        }
    }
    merged[mergedIndex] = malloc(2 * sizeof(int));
    merged[mergedIndex][0] = intervals[curr][0];
    merged[mergedIndex][1] = intervals[curr][1];
    mergedIndex++;
    *returnSize = mergedIndex;
    *returnColumnSizes = malloc((*returnSize) * sizeof(int));
    for (int i = 0; i < (*returnSize); i++) {
        (*returnColumnSizes)[i] = 2;
    }
    return merged;
}
