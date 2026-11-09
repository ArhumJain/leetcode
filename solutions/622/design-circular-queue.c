#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int frontIndex;
    int rearIndex;
    int* queue;
    int size;
    int currentCount;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* queue = malloc(sizeof(MyCircularQueue));
    queue->queue = calloc(k, sizeof(int));
    queue->frontIndex = -1;
    queue->rearIndex = -1;
    queue->size = k;
    queue->currentCount = 0;
    return queue;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if ((obj->currentCount) == (obj->size)) return false;
    obj->queue[(obj->rearIndex+1) % (obj->size)] = value;
    obj->rearIndex = (obj->rearIndex+1) % obj->size;
    obj->currentCount++;
    if (obj->currentCount == 1) obj->frontIndex = obj->rearIndex;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (obj->currentCount == 0) return false;
    obj->frontIndex = (obj->frontIndex+1) % obj->size;
    obj->currentCount--;
    if (obj->currentCount == 0) obj->rearIndex = obj->frontIndex;
    return true;

}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (obj->currentCount == 0) return -1;
    return obj->queue[obj->frontIndex];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (obj->currentCount == 0) return -1;
    return obj->queue[(obj->rearIndex)];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->currentCount == 0;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->currentCount == obj->size;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->queue);
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/
