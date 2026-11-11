/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize) {
    int* final = malloc(asteroidsSize * sizeof(int));
    *returnSize = 0;
    int top = 1;
    final[0] = asteroids[0];
    int i = 1;
    while (i < asteroidsSize) {
        bool exists = true;
        if (asteroids[i] < 0) {
            while (top > 0 && final[top-1] > 0) {
                if (abs(asteroids[i]) > abs(final[top-1])) {
                    top--;
                } else if (abs(asteroids[i]) < abs(final[top-1])) {
                    exists = false;
                    break;
                } else if (abs(asteroids[i]) == abs(final[top-1])) {
                    final[top-1] = 0;
                    top--;
                    exists = false;
                    break;
                }
            }
            
        } 
        if (exists) {
            final[top] = asteroids[i];
            top++;
        }
        i++;
    }
    *returnSize = top;
    return final;
    
}
