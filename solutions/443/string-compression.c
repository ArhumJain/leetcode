#include <stdio.h>
int compress(char* chars, int charsSize) {
    char* currentChar = chars;
    char c = *chars; currentChar++;
    int count = 1;
    int compressedIndex = 0;
    char str[20];
    for (int i = 1; i <= charsSize; i++) {
        if (i != charsSize && c == (*currentChar)) {
            count++;
        } else if (count == 1) {
            chars[compressedIndex] = *(currentChar-1);
            if (i != charsSize) c = *currentChar;
            compressedIndex++;
        } else {
            chars[compressedIndex] = *(currentChar-1);
            sprintf(str, "%d", count);
            for (int i = 0; i < 5; i++) {
                compressedIndex++;
                if (str[i] == '\0') break;
                chars[compressedIndex] = str[i]; 
            }
            if (i != charsSize) c = *currentChar;
            count = 1;
        }
        currentChar++;
    }
    return compressedIndex;
}
