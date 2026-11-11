int dp(int* coins, int coinsSize, int amountRemaining, int memoize[10003]) {
    if (amountRemaining == 0) return 0;
    else if (amountRemaining < 0) return -1;
    else if (memoize[amountRemaining] != 0) return memoize[amountRemaining];
    int minCount = INT_MAX;
    for (int i = 0; i < coinsSize; i++) {
        int count = dp(coins, coinsSize, amountRemaining - coins[i], memoize);
        if (count != -1 && count < minCount) minCount = count;
    }
    if (minCount != INT_MAX) {
        memoize[amountRemaining] = 1 + minCount;
        return minCount + 1;
    } else {
        memoize[amountRemaining] = -1;
        return -1;
    }
}
int coinChange(int* coins, int coinsSize, int amount) {
    int memoize[10003] = {0};
    return dp(coins, coinsSize, amount, memoize);
}
