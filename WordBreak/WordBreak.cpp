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
// Complexity:
// O(n^2) time, O(n) space
//============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int N = s.size();
        vector<bool> dp(N+1, false);
        dp[0] = true;
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && dict.count(s.substr(j, i-j))) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[N];
    }
};

int main() {
    Solution sol;
    string p0;
    unordered_set<string> p1;

    {
        p0 = "leetcode";
        p1.insert("leet");
        p1.insert("code");
        cout << sol.wordBreak(p0, p1) << "," << 1 << endl;
    }

    return 0;
}