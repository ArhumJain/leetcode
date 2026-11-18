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

bool insertQueue(int* queue, int *front, int *rear, int val) {
    queue[(*rear) % 2000] = val; // don't need to check capacity since we won't exceed it
    *rear = ((*rear) + 1) % 2000;
    return true;
}

int popQueue(int* queue, int* front, int* rear) {
    if (*rear == *front) return -1;
    int val = queue[(*front)];
    *front = ((*front) + 1) % 2000;
    return val;
}

void cleanUpAdjacencyList(int** adjacencyList, int numCourses) { 
    for (int i = 0; i < numCourses; i++) {
        free(adjacencyList[i]);
    }
    free(adjacencyList);
}

int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize) {
    int queue[2000];
    bool canTake[2000];
    for (int i = 0; i < 2000; i++) canTake[i] = true;
    int front = 0;
    int rear = 0;
    int inDegrees[2000] = {0};
    int edgeCounts[2000] = {0};
    for (int i = 0; i < prerequisitesSize; i++) {
        int prerequisite = prerequisites[i][1];
        edgeCounts[prerequisite]++;
    }
    int** adjacencyList = malloc(numCourses * sizeof(int*));
    for (int i = 0; i < numCourses; i++) {
        adjacencyList[i] = malloc(
            (edgeCounts[i] + 1) * sizeof(int)
        );
        adjacencyList[i][0] = 0;
    }
    for (int i = 0; i < prerequisitesSize; i++) {
        int prerequisite = prerequisites[i][1];
        int outgoing = prerequisites[i][0];
        int edgeCount = adjacencyList[prerequisite][0];
        adjacencyList[prerequisite][edgeCount + 1] = outgoing;
        adjacencyList[prerequisite][0]++;
        inDegrees[outgoing]++;
    }

    int currTopCount = 0;
    for (int i = 0; i < numCourses; i++) {
        if (inDegrees[i] == 0) {
            insertQueue(queue, &front, &rear, i);
            currTopCount++;
        }
    }

    int* courseOrder = calloc(numCourses, sizeof(int));
    int courseOrderIndex = 0;

    
    while (front != rear) { // while queue is not empty
        int nextTopCount = 0;
        for (int i = 0; i < currTopCount; i++) {
            int pop = popQueue(queue, &front, &rear);
            if (pop < numCourses && !canTake[pop]) {
                cleanUpAdjacencyList(adjacencyList, numCourses);
                free(courseOrder);
                *returnSize = 0;
                return NULL;
            }
            else {
                courseOrder[courseOrderIndex] = pop;
                courseOrderIndex++;
            }
            for (int j = 0; j < adjacencyList[pop][0]; j++) {
                int adjacentVertex = adjacencyList[pop][j+1];
                inDegrees[adjacentVertex]--;
                if (inDegrees[adjacentVertex] == 0) {
                    insertQueue(queue, &front, &rear, adjacentVertex);
                    nextTopCount++;
                }
                if (pop >= numCourses) canTake[adjacentVertex] = false;
            }
        }
        currTopCount = nextTopCount;
    }

    cleanUpAdjacencyList(adjacencyList, numCourses);
    if (courseOrderIndex == numCourses) {
        *returnSize = courseOrderIndex;
        return courseOrder;
    } else {
        free(courseOrder);
        *returnSize = 0;
        return NULL;
    }
}
