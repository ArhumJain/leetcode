#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int compare(const void* a, const void* b) {
    const int* intervalA = *((const int**) a);
    const int* intervalB = *((const int**) b);
    if (intervalA[1] < intervalB[1]) return -1;
    if (intervalA[1] > intervalB[1]) return 1;
    return 0;
}
int findMinArrowShots(int** points, int pointsSize, int* pointsColSize) {
    qsort(points, pointsSize, sizeof(int*), compare);
    bool* intervalPopped = calloc(pointsSize, sizeof(bool));

    int currEnd = points[0][1];

    int arrowCount = 1;
    for (int i = 0; i < pointsSize; i++) {
        if (points[i][0] > currEnd) {
            arrowCount++;
            currEnd = points[i][1];
        }
    }
    return arrowCount;


}
