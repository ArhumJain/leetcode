#include <stdlib.h>
#include <stdbool.h>

int leftChild(int i) { return (2 * i) + 1; }
int rightChild(int i) { return (2 * i) + 2; }
int parent(int i) { return (i - 1) / 2; }

void maxHeapify(int* heap, int heapSize, int node) { // node is sub tree to max heapify
    int parent = node;
    while (true) {
        int largest = parent;
        int leftIndex = leftChild(parent);
        int rightIndex = rightChild(parent);
        if (leftIndex < heapSize && heap[leftIndex] > heap[largest]) {
            largest = leftIndex;
        }
        if (rightIndex < heapSize && heap[rightIndex] > heap[largest]) {
            largest = rightIndex;
        }
        if (largest == parent) return;
        int swap = heap[parent];
        heap[parent] = heap[largest];
        heap[largest] = swap;
        parent = largest;
    }
}

void buildHeapify(int* heap, int heapSize) {
    int startNode = (heapSize/2)-1;
    for (int i = startNode; i >= 0; i--) {
        maxHeapify(heap, heapSize, i);
    }
}

int popHeap(int* heap, int heapSize) {
    if (heapSize <= 0) return -1;
    int pop = heap[0];
    heap[0] = heap[heapSize-1];
    maxHeapify(heap, heapSize-1, 0);
    return pop;
}

void maxHeapifyUp(int* heap, int heapSize, int node) {
    int curr = node;
    while (true) {
        if (curr == 0) return;
        int parent = (curr - 1)/2;
        if (heap[curr] > heap[parent]) {
            int swap = heap[parent];
            heap[parent] = heap[curr];
            heap[curr] = swap;
            curr = parent;
        } else return;
    }
}

void pushHeap(int* heap, int heapSize, int val) {
    heap[heapSize] = val;
    maxHeapifyUp(heap, heapSize+1, heapSize);
}

int findKthLargest(int* nums, int numsSize, int k) {
    buildHeapify(nums, numsSize);
    int heapSize = numsSize;
    int largest;
    for (int i = 0; i < k; i++) {
        largest = popHeap(nums, heapSize);
        heapSize--;
    }
    return largest;

}
