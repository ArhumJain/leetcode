#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countPoints(int** points, int pointsSize, int* pointsColSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    int* answers = calloc(queriesSize, sizeof(int));
    for (int i = 0; i < queriesSize; i++) {
        int centerX = queries[i][0];
        int centerY = queries[i][1];
        int radius = queries[i][2];
        int count = 0;
        for (int i = 0; i < pointsSize; i++) {
            int x = points[i][0];
            int y = points[i][1];
            int x2 = abs(x - centerX) * abs(x - centerX);
            int y2 = abs(y - centerY) * abs(y - centerY); 
            if (x2 + y2 <= (radius * radius)) count++;
        }
        answers[i] = count;
    }
    *returnSize = queriesSize;
    return answers;
}
