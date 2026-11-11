#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
int lengthOfLongestSubstring(char* s) {
    int* indices = calloc(256, sizeof(int));
    memset(indices, -1, 256 * sizeof(int));
    char *tip = s;
    char c = *tip;
    int maxLen = 0;
    int left = 0;
    int right = 0;
    while (c != '\0') {
        if (indices[c] >= left) {
            left = indices[c] + 1;
            indices[c] = right;
        } else {
            indices[c] = right;
        }
        right++;
        tip++;
        c = *tip;
        if ((right-left) > maxLen) {
            maxLen = (right-left);
        }
    }
    return maxLen;
}
