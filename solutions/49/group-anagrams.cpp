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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> groups;

        for (string str: strs) {
            string sorted_str = str;
            sort(sorted_str.begin(), sorted_str.end());
            groups[sorted_str].push_back(str);
        }

        vector<vector<string>> output;
        for (const auto& [key, value] : groups) {
            output.push_back(value);
        }

        return output;
    }
};
