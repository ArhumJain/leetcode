#include <stdlib.h>
#include <stdbool.h>
char* convert(char* s, int numRows) {
    char* c = s;
    int size = 0;
    while ((*c) != '\0') {
        size++;
        c++;
    }
    if (size <= numRows || numRows == 1) return s;
    int cycle = 2 * numRows - 2;
    int numCols = ((size + cycle - 1) / cycle) * (numRows - 1);
    char** grid = calloc(numRows, sizeof(char*));
    for (int i = 0; i < numRows; i++) grid[i] = calloc(numCols, sizeof(char));
    int row = 0;
    int col = 0;
    bool zigzag = false;
    while ((*s) != '\0') {
        grid[row][col] = *s;
        s++;
        if (!zigzag && row == numRows-1) zigzag = true;
        if (zigzag && row == 0) zigzag = false;
        if (zigzag) {
            row--; col++;
        }
        else row++;
    }   
    char* out = calloc(size+1, sizeof(char)); 
    int outIndex = 0;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if (grid[i][j] != '\0') {
                out[outIndex] = grid[i][j];
                outIndex++;
            }
        }
    }
    for (int i = 0; i < numRows; i++) free(grid[i]);
    free(grid);
    return out;
}
