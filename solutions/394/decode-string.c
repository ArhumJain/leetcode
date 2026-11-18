#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* recurse(char** s, int* returnSize) {
    int count = 0;
    int size = 0;
    char* out = calloc(1, sizeof(char));
    int outTip = 0;
    while ((**s) != '\0' && (**s) != ']') {
        if ((**s) == '[') {
            (*s)++;
            int currSize;
            char* expand = recurse(s, &currSize);
            out = realloc(out, size + count*currSize + 1);
            for (int i = 0; i < count; i++) {
                memcpy(out + outTip + currSize*i, expand, currSize * sizeof(char));
            }
            free(expand);
            out[outTip + currSize*count] = '\0';
            outTip += currSize * count;
            size += count*currSize;
        }  
        else if ((**s) >= '0' && (**s) <= '9') {
            count = 0;
            while ((**s) >= '0' && (**s) <= '9') {
                count = 10 * count + ((**s) - '0');
                (*s)++;
            }
        }
        else {
            if ((**s) == '\0') break;
            out = realloc(out, size+2);
            out[outTip] = (**s);
            out[outTip+1] = '\0';
            outTip++;
            size++;
            (*s)++;
        }
    }
    if ((**s) == ']') (*s)++;
    *returnSize = size;
    return out;
}
char* decodeString(char* s) {
    int size = 0;
    return recurse(&s, &size);
}
