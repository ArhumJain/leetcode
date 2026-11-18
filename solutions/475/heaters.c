#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int compare(const void* A, const void* B) {
    const int a = *((const int*) A);
    const int b = *((const int*) B);
    if (a < b) return -1;
    if (a > b) return 1;
    return 0;
}
bool allCovered(int* houses, int housesSize, int* heaters, int heatersSize, int standardRadius) {
    int leftHeater = -1;
    int rightHeater = 0;
    for (int i = 0; i < housesSize; i++) {
        if (rightHeater < heatersSize && houses[i] > heaters[rightHeater]) {
            leftHeater++;
            rightHeater++;
            i--;
            continue;
        } 
        if (leftHeater >= 0 && houses[i] >= heaters[leftHeater]) {
            if (houses[i] <= heaters[leftHeater] + standardRadius) continue;
        }
        if (rightHeater < heatersSize && houses[i] <= heaters[rightHeater]) {
            if (houses[i] >= heaters[rightHeater] - standardRadius) continue;
        }
        return false;
    }
    return true;
}
int findRadius(int* houses, int housesSize, int* heaters, int heatersSize) {
    qsort(houses, housesSize, sizeof(int), compare);
    qsort(heaters, heatersSize, sizeof(int), compare);
    int leftStandardRadius = 0;
    int rightStandardRadius = 1000000000;
    int currStandardRadius = (rightStandardRadius + leftStandardRadius) / 2;
    while (leftStandardRadius < rightStandardRadius) {
        if (allCovered(houses, housesSize, heaters, heatersSize, currStandardRadius)) {
            rightStandardRadius = currStandardRadius;
            currStandardRadius = (rightStandardRadius + leftStandardRadius) / 2;
        } else {
            leftStandardRadius = currStandardRadius + 1;
            currStandardRadius = (rightStandardRadius + leftStandardRadius) / 2;
        }
    }
    return currStandardRadius;
}
