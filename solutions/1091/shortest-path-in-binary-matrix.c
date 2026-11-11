int directions[8][2] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

bool admissible(int row, int col, int**grid, int gridSize, int* gridColSize) {
    return !(row >= gridSize || row < 0 || col >= (*gridColSize) || col < 0 || grid[row][col] == 1);
}

typedef struct Queue {
    int row;
    int col;
    struct Queue* next;
} Queue;

void enqueue(int row, int col, Queue** front, Queue** back) {
    if ((*back) == NULL) {
        (*back) = malloc(sizeof(Queue));
        (*back)->next = NULL;
        (*back)->row = row;
        (*back)->col = col;
        (*front) = (*back);
    } else {
        (*back)->next = malloc(sizeof(Queue));
        (*back)->next->row = row;
        (*back)->next->col = col;
        (*back) = (*back)->next;
        (*back)->next = NULL;
    }
}

Queue* dequeue(Queue** front, Queue** back) {
    if ((*front) == NULL) return NULL;
    Queue* pop = *front;
    (*front) = (*front)->next;
    if (*front == NULL) {
        (*back) = NULL;
    }
    pop->next = NULL;
    return pop;
}


int shortestPathBinaryMatrix(int** grid, int gridSize, int* gridColSize) {
    Queue* front = NULL;
    Queue* back = NULL;
    if (grid[0][0] == 1) return -1;
    enqueue(0, 0, &front, &back);
    int path = 1;
    int frontierCount = 1;
    while (front != NULL) {
        int newFrontierCount = 0;
        for (int i=0; i<frontierCount; i++) {
            Queue* curr = dequeue(&front, &back);
            if (curr->row == gridSize-1 && curr->col == (*gridColSize)-1) {
                return path;
            }
            for (int dir=0; dir < 8; dir++) {
                int nextRow = curr->row + directions[dir][0];
                int nextCol = curr->col + directions[dir][1];
                if (admissible(nextRow, nextCol, grid, gridSize, gridColSize)) {
                    grid[nextRow][nextCol] = 1;
                    enqueue(nextRow, nextCol, &front, &back);
                    newFrontierCount++;
                }
            }
            free(curr);
        }
        frontierCount = newFrontierCount;
        path += 1;
        
    }
    return -1;
}
