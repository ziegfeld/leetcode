//============================================================================
// Write a function to find the longest common prefix string amongst an array
// of strings.
//
// Complexity:
// O(NL) time, N is the size of input, L is the length of result
//============================================================================

#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> & strs) {
        if (strs.empty() || strs[0].empty()) return "";
        int M = strs.size(), N = strs[0].size();
        for (int j = 0; j < N; j++) {
            for (int i = 1; i < M; i++)
                if (j == (int)strs[i].size() || strs[i][j] != strs[0][j])
                    return strs[0].substr(0, j);
        }
        return strs[0];
    }
};

int main() {
    return 0;
}
