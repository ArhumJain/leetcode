int directions[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool admissible(int row, int col, char** grid, int gridSize, int* gridColSize, bool explored[300][300]) {
    return !(row < 0 || row >= gridSize || col < 0 || col >= (*gridColSize) || grid[row][col] == '0' || explored[row][col]);
}
void explore(int row, int col, char** grid, int gridSize, int* gridColSize, bool explored[300][300]) {
    explored[row][col] = true;
    for (int dir=0; dir < 4; dir++) {
        int nextRow = row + directions[dir][0];
        int nextCol = col + directions[dir][1];
        if (admissible(nextRow, nextCol, grid, gridSize, gridColSize, explored)) {
            explore(nextRow, nextCol, grid, gridSize, gridColSize, explored);
        }
    }
    return;
}
int numIslands(char** grid, int gridSize, int* gridColSize) {
    bool explored[300][300] = {0};
    int count = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < (*gridColSize); j++) {
            if (grid[i][j] == '1' && !explored[i][j]) {
                count++;
                explore(i, j, grid, gridSize, gridColSize, explored);
            }
        }
    }
    return count;
}
