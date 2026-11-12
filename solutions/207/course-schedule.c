void enqueue(int* queue, int* left, int* right, int val) {
    queue[*right] = val;
    *right = (*right + 1) % 20001;
}
bool dequeue(int* queue, int* left, int* right, int* val) {
    if (*left == *right) return false;
    *val = queue[*left];
    *left = (*left + 1) % 20001;
    return true;
}
bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    int** adjacencyList = malloc(sizeof(int*) * numCourses);
    bool* canTake = calloc(numCourses, sizeof(bool));
    int numCoursesLeft = numCourses;
    int queue[20001] = {0}; int left = 0; int right = 0;
    for (int i = 0; i < numCourses; i++) {
        adjacencyList[i] = calloc(prerequisitesSize + 2, sizeof(int));
        canTake[i] = true;
    }
    for (int i = 0; i < prerequisitesSize; i++) {
        int vertex = prerequisites[i][1]; int to = prerequisites[i][0];
        adjacencyList[vertex][adjacencyList[vertex][0]+2] = to;
        adjacencyList[vertex][0]++; // number of outgoing edges
        adjacencyList[to][1]++; // in-degree of vertex to
    }
    for (int i = 0; i < numCourses; i++) {
        if (adjacencyList[i][1] == 0) enqueue(queue, &left, &right, i);
    }
    while (left != right) {
        if (numCoursesLeft == 0) return true;
        int pop = 0;
        dequeue(queue, &left, &right, &pop);
        if (pop < numCourses) { // we have to take the popped course
            if (canTake[pop]) {
                numCoursesLeft--;
                canTake[pop] == false;
            }
            else return false;
        }
        for (int i = 2; i < 2+adjacencyList[pop][0]; i++) {
            int adjacent = adjacencyList[pop][i];
            adjacencyList[adjacent][1]--; // decrease in-degree of adjacent vertex
            if (adjacencyList[adjacent][1] == 0) enqueue(queue, &left, &right, adjacent);
            if (pop >= numCourses) canTake[adjacent] = false;
        }
    }
    return numCoursesLeft == 0;
}
