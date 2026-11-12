typedef struct Node {
    int* frequencies;
    int val;
} Node;
int compare(const void* A, const void* B) {
    Node a = *((Node*) A);
    Node b = *((Node*) B);
    if (a.frequencies[a.val+10000] > b.frequencies[b.val+10000]) return -1;
    if (a.frequencies[a.val+10000] < b.frequencies[b.val+10000]) return 1;
    return 0;   
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    int frequencies[10000 + 10000 + 1] = {0};
    Node* uniqueInts = malloc(100000 * sizeof(Node));
    int uniqueIntCount = 0;
    for (int i = 0; i < numsSize; i++) {
        if (frequencies[nums[i] + 10000] == 0) {
            uniqueInts[uniqueIntCount].frequencies = frequencies;
            uniqueInts[uniqueIntCount].val = nums[i];
            uniqueIntCount++;
        }
        frequencies[nums[i] + 10000]++;
    }
    qsort(uniqueInts, uniqueIntCount, sizeof(Node), compare);
    int* out = malloc(sizeof(int) * k);
    for (int i = 0; i < k; i++) {
        out[i] = uniqueInts[i].val;
    }
    *returnSize = k;
    return out;
}
