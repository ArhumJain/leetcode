#include <limits.h>
int myAtoi(char* s) {
    char c = *s;
    while (c == ' ') {
        s++;
        c = *s;
    }
    int sign = 0;
    if (c == '-') {
        sign = -1;
        s++;
        c = *s;
    } else if (c == '+') {
        sign = 1;
        s++;
        c = *s;
    } else sign = 1;
    while (c == '0') {
        s++;
        c = *s;
    }
    
    long i = 0;
    while (c >= '0' && c <= '9') {
        i = 10 * i + (c - '0');
        if ((sign * i) >= INT_MAX) {
            return INT_MAX;
        } else if ((sign * i) <= INT_MIN) {
            return INT_MIN;
        }
        s++;
        c = *s;
    }
    return sign * i;
}
