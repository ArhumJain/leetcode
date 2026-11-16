// WRONG AND INCOMPLETE SOLUTION
// studied manacher's algorithm but was too lazy to actually implement it after writing this failed solution :)
char* longestPalindrome(char* s) {
    int size = 0;
    char* c = s;
    while ((*c) != '\0') {
        size++;
        c++;
    }
    int left = 0;
    int right = size-1;
    int leftPalindrome = 0;
    int rightPalindrome = size-1;
    while (left < right) {
        if (s[left] != s[right]) {
            if (s[left+1] == s[right]) {
                leftPalindrome = left+1;
                left++;
                continue;
            }
            if (s[right-1] = s[left]) {
                rightPalindrome = right-1;
                right--;
                continue;
            }
            leftPalindrome = left+1;
            rightPalindrome = right-1;
            left++;
            right--;
        } else {
            left++;
            right--;
        }
    }
    char* palindrome = calloc((rightPalindrome-leftPalindrome)+2, sizeof(char));
    for (int i = leftPalindrome; i <= rightPalindrome; i++) {
        palindrome[i-leftPalindrome] = s[i];
    }
    palindrome[(rightPalindrome-leftPalindrome)+1] = '\0';
    return palindrome;
}
