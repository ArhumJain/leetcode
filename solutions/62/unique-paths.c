#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
bool admissible(int row, int col, int m, int n) {
    return !(row < 0 || row >= m || col < 0 || col >= n);
}
int explore(int row, int col, int m, int n, int** memoize) {
    if (!admissible(row, col, m, n)) return 0;
    if (row == m-1 && col == n-1) return 1;
    if (memoize[row][col] != 0) return memoize[row][col];
    int pathCount = explore(row + 1, col, m, n, memoize) + explore(row, col+1, m, n, memoize);
    memoize[row][col] = pathCount;
    return pathCount;
}
int uniquePaths(int m, int n) {
    int** memoize = calloc(m, sizeof(int*));
    for (int i = 0; i < m; i++) memoize[i] = calloc(n, sizeof(int));
    int pathCount = explore(0, 0, m, n, memoize);
    for (int i = 0; i < m; i++) free(memoize[i]);
    free(memoize);
    return pathCount;
}
