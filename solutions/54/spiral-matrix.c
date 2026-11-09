#include <stdlib.h>
#include <stdio.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int visitedCount = 0;    
    int* spiral = calloc(matrixSize * (*matrixColSize), sizeof(int));
    int row = 0;
    int col = 0;
    char direction = 'r';
    while (visitedCount != (matrixSize * (*matrixColSize))) {
        spiral[visitedCount] = matrix[row][col];
        matrix[row][col] = -101;
        visitedCount++;
        switch (direction) {
            case 'r':
                if (col == (*matrixColSize)-1 || matrix[row][col+1] == -101)  {
                    row++;
                    direction = 'd';
                } else col++;
                break;
            case 'd':
                if (row == matrixSize-1 || matrix[row+1][col] == -101) {
                    col--;
                    direction = 'l';
                } else row++;
                break;
            case 'l':
                if (col == 0 || matrix[row][col-1] == -101) {
                    row--;
                    direction = 'u';
                } else col--;
                break;
            case 'u':
                if (row == 0 || matrix[row-1][col] == -101) {
                    col++;
                    direction = 'r';
                } else row--;
                break;
            default:
                break;
        }
    }
    *returnSize = (matrixSize * (*matrixColSize));
    return spiral;
}
