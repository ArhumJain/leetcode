int reverseBits(int n) {
    unsigned int out = 0;
    for (unsigned int i = 0; i < 32; i++) {
        out |= (n & (1U << i)) >> i << (31U-i);
    }
    return out;
}
