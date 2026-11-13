// inefficient solution not actually in-place can't just make a copy originalZeros
#include <stdlib.h>
#include <stdbool.h>
int directions[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool admissible(int** matrix, int matrixSize, int* matrixColSize, int row, int col) {
    return !(row < 0 || row >= matrixSize || col < 0 || col >= *matrixColSize);
}
void explore(int** matrix, int matrixSize, int* matrixColSize, int row, int col, int rowDir, int colDir) {
    if (admissible(matrix, matrixSize, matrixColSize, row, col)) {
        matrix[row][col] = 0;
        explore(matrix, matrixSize, matrixColSize, row + rowDir, col + colDir, rowDir, colDir);
    } else return;
}
void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int** originalZeros = calloc(matrixSize, sizeof(int*));
    for (int i = 0; i < matrixSize; i++) {
        originalZeros[i] = calloc(*matrixColSize, sizeof(int));
        for (int j = 0; j < *matrixColSize; j++) {
            if (matrix[i][j] == 0) originalZeros[i][j] = 1;
        }
    }

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < *matrixColSize; j++) {
            if (originalZeros[i][j] == 1) {
                for (int dir = 0; dir < 4; dir++) {
                    explore(matrix, matrixSize, matrixColSize, i + directions[dir][0], j + directions[dir][1], directions[dir][0], directions[dir][1]);
                }
            }
        }
    }
    
    
}
