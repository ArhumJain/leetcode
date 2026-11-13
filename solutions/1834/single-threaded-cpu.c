#include <stdlib.h>
#include <stdbool.h>
typedef struct Task {
    int enqueueTime;
    int processingTime;
    int index;
} Task;

int compare(const void* A, const void* B) {
    const struct Task taskA = *(const struct Task*) A;
    const struct Task taskB = *(const struct Task*) B;
    if (taskA.enqueueTime < taskB.enqueueTime) return -1;
    else if (taskA.enqueueTime > taskB.enqueueTime) return 1;
    return 0;
}

int parent(int i) { return (i-1)/2; }
int leftChild(int i) { return 2 * i + 1; }
int rightChild(int i) { return 2 * i + 2; }

bool isLessProcessingTime(Task** heap, int heapSize, int A, int B) {
    if (A < heapSize && B < heapSize) {
        return (heap[A]->processingTime < heap[B]->processingTime || (heap[A]->processingTime == heap[B]->processingTime && heap[A]->index < heap[B]->index));
    }
    return false;
}

void minHeapifyDown(Task** heap, int heapSize, int node) {
    int parentIndex = node;
    while (true) {
        int minimum = parentIndex;
        int leftIndex = leftChild(minimum);
        int rightIndex = rightChild(minimum);
        if (isLessProcessingTime(heap, heapSize, leftIndex, minimum)) {
            minimum = leftIndex;
        }
        if (isLessProcessingTime(heap, heapSize, rightIndex, minimum)) {
            minimum = rightIndex;
        }
        if (parentIndex == minimum) break;
        Task* swap = heap[parentIndex];
        heap[parentIndex] = heap[minimum];
        heap[minimum] = swap;
        parentIndex = minimum;
    }
}

void minHeapifyUp(Task** heap, int heapSize, int node) {
    int curr = node;
    while (true) {
        if (curr == 0) return;
        int parentIndex = parent(curr);
        if (heap[curr]->processingTime < heap[parentIndex]->processingTime || (heap[curr]->processingTime == heap[parentIndex]->processingTime && heap[curr]->index < heap[parentIndex]->index)) {
            Task* swap = heap[parentIndex];
            heap[parentIndex] = heap[curr];
            heap[curr] = swap;
            curr = parentIndex;
        } else return;
    }
}

void pushMinHeap(Task** heap, int* heapSize, Task* task) {
    heap[(*heapSize)] = task;
    minHeapifyUp(heap, (*heapSize)+1, (*heapSize));
    (*heapSize)++;
}

bool popMinHeap(Task** heap, int* heapSize, Task** pop) {
    if ((*heapSize) <= 0) return false;
    *pop = heap[0];
    heap[0] = heap[(*heapSize)-1];
    minHeapifyDown(heap, (*heapSize)-1, 0);
    (*heapSize)--;
    return true;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getOrder(int** tasks, int tasksSize, int* tasksColSize, int* returnSize) {
    Task* taskList = calloc(tasksSize, sizeof(Task));
    int* order = calloc(tasksSize, sizeof(int));
    *returnSize = tasksSize;
    for (int i = 0; i < tasksSize; i++) {
        taskList[i].enqueueTime = tasks[i][0];
        taskList[i].processingTime = tasks[i][1];
        taskList[i].index = i;
    }
    qsort(taskList, tasksSize, sizeof(Task), compare);
    
    int heapSize = 0;
    Task** heap = calloc(tasksSize, sizeof(Task*));
    
    long long time = taskList[0].enqueueTime;
    Task* currTask;
    int tasksProcessed = 0;
    int availableIndex = 0;
    while (tasksProcessed < tasksSize) {
        for (int i = availableIndex; i < tasksSize; i++) {
            if (taskList[i].enqueueTime <= time) {
                pushMinHeap(heap, &heapSize, taskList+i);
                availableIndex++;
            } else break;
        }
        Task* processedTask = NULL;
        popMinHeap(heap, &heapSize, &processedTask);
        if (processedTask != NULL) {
            time += processedTask->processingTime;
            order[tasksProcessed] = processedTask->index;
            tasksProcessed++;
        } else {
            time = taskList[tasksProcessed].enqueueTime;
        }
    }
    return order;
}
