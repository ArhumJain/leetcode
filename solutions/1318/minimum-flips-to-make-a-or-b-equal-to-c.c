int minFlips(int a, int b, int c){
    unsigned int A = a;
    unsigned int B = b;
    unsigned int C = c;
    int count = 0;
    for (int i = 0; i < 32; i++) {
        if ((A & 1u) && (B & 1u)) {
            if (!(C & 1u)) count += 2;
        } else if (!(A & 1u) && !(B & 1u)) {
            if (C & 1u) count++;
        } else {
            if (!(C & 1u)) count++;
        }
        A >>= 1;
        B >>= 1;
        C >>= 1;
    }
    return count;
}
