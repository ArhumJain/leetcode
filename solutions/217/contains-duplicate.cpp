#include <algorithm>
#include <array>
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
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> numCounts;
        for (int num: nums) {
            if (numCounts[num] > 0) {
                return true;
            } else {
                numCounts[num] = 1;
            }
        }
        return false;
    }
};
