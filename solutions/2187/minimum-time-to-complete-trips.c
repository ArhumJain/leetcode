#include <stdlib.h>
#include <limits.h>
long long minimumTime(int* time, int timeSize, int totalTrips) {
    long long minTime = LONG_MAX;
    for (int i = 0; i < timeSize; i++) {
        if (time[i] < minTime) minTime = time[i];
    }
    long long maxTime = totalTrips * minTime;
    long long leftTime = minTime;
    while (leftTime < maxTime) {
        long long midTime = (maxTime + leftTime)/2;
        long long tripCount = 0;
        for (int i = 0; i < timeSize; i++) tripCount += midTime/time[i];
        if (tripCount >= totalTrips) maxTime = midTime;
        else if (tripCount < totalTrips) leftTime = midTime+1;
    }
    return leftTime;
}
