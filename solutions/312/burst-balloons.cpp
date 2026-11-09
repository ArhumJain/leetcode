#include <algorithm>
#include <array>
#include <charconv>
#include <deque>
#include <functional>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    map<string, int> memoize;
    int maxValue = -1;
    int findMaxCoins(string state, int value) {
        if (state.size() == 1) return state[0];
        if (memoize[state] != 0) return memoize[state];

        int currentMaxValue = -1;
        int stateSize = state.size();
        int nextPickValue = -1;

        for (int i = 0; i < stateSize; i++) {
            string nextState = state;
            int nextStateValue;
            int pickValue;
            nextState.erase(i,1);
            if (i == 0) {
                pickValue = (state[0]) * (stateSize > 1 ? (state[1]) : 1);
                nextStateValue = findMaxCoins(nextState, pickValue);
            } else if (i == stateSize - 1) {
                pickValue = (stateSize > 1 ? (state[stateSize-2]) : 1) * (state[stateSize-1]);
                nextStateValue = findMaxCoins(nextState, pickValue);
            } else {
                pickValue = (state[i-1]) * (state[i]) * (state[i+1]);
                nextStateValue = findMaxCoins(nextState, pickValue);
            }
            if ((nextStateValue + pickValue) > currentMaxValue) {
                currentMaxValue = nextStateValue + pickValue;
                nextPickValue = pickValue;
            }
        }

        memoize[state] = currentMaxValue;
        return currentMaxValue;
    }
    int maxCoins(vector<int>& nums) {
        string initialState;
        for (int num: nums) {
            initialState.push_back(static_cast<char>(num));
        }
        return findMaxCoins(initialState, 0);
    }
};
