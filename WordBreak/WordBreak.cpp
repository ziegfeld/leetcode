//============================================================================
// Given a string s and a dictionary of words dict, determine if s can be 
// segmented into a space-separated sequence of one or more dictionary words.
//
// For example, given
// s = "leetcode",
// dict = ["leet", "code"].
//
// Return true because "leetcode" can be segmented as "leet code".
//
//============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <tr1/unordered_set>

using namespace std;
using namespace std::tr1;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int N = s.size();
        vector<bool> dp(N+1, false);
        dp[0] = true;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= i; j++) {
                if (dp[i-j] && (dict.find(s.substr(i-j, j)) != dict.end())) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[N];
    }
};

int main() {
    return 0;
}
