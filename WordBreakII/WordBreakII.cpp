
//============================================================================
// Given a string s and a dictionary of words dict, add spaces in s to 
// construct a sentence where each word is a valid dictionary word.
//
// Return all such possible sentences.
//
// For example, given
// s = "catsanddog",
// dict = ["cat", "cats", "and", "sand", "dog"].
//
// A solution is ["cats and dog", "cat sand dog"].
//
// Complexity:
// O(n^2) time, O(n^2) space
//============================================================================

#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        return wordBreak1(s, dict);
    }

    vector<string> wordBreak1(string & s, unordered_set<string> &dict) {
        int N = s.size();
        vector<vector<int> > dp(N + 1, vector<int>());
        dp[0].push_back(0);
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < i; j++) {
                if (!dp[j].empty() && dict.count(s.substr(j, i - j))) {
                    dp[i].push_back(j);
                }
            }
        }

        vector<vector<string> > memo(N + 1, vector<string>());
        return wordBreakHelper1(s, dp, memo, N);
    }

    vector<string> wordBreakHelper1(string & s, vector<vector<int> > & dp, vector<vector<string> > & memo, int i) {
        if (!memo[i].empty()) return memo[i];
        for (int j : dp[i]) {
            if (j == 0) {
                memo[i].push_back(s.substr(0, i));
                continue;
            }
            auto res = wordBreakHelper1(s, dp, memo, j);
            for (auto & str : res) memo[i].push_back(str + " " + s.substr(j, i - j));
        }
        return memo[i];
    }

    vector<string> wordBreak2(string s, unordered_set<string> &dict) {
        vector<string> res;
        if (s.empty()) return res;
        int N = s.size();
        vector<vector<int> > dp1(N + 1, vector<int>());
        dp1[0].push_back(0);
        for (int j = 0; j <= N; j++) {
            for (int i = 0; i < j; i++) {
                if (!dp1[i].empty() && dict.count(s.substr(i, j - i))) dp1[j].push_back(i);
            }
        }
        if (dp1[N].empty()) return res;
        vector<vector<string> > dp2(N + 1, vector<string>());
        for (int j = 0; j <= N; j++) {
            for (int i : dp1[j]) {
                if (i == 0) dp2[j].push_back(s.substr(i, j - i));
                else for (auto & str : dp2[i]) dp2[j].push_back(str + " " + s.substr(i, j - i));
            }
        }
        return dp2[N];
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
        auto p2 = sol.wordBreak(p0, p1);
        for (auto it : p2) cout << it << endl;
    }

    {
        p0 = "catsanddog";
        p1.insert("cat");
        p1.insert("cats");
        p1.insert("and");
        p1.insert("sand");
        p1.insert("dog");
        auto p2 = sol.wordBreak(p0, p1);
        for (auto it : p2) cout << it << endl;
    }

    {
        p0 = "catsanddogcatsanddog";
        p1.insert("cat");
        p1.insert("cats");
        p1.insert("and");
        p1.insert("sand");
        p1.insert("dog");
        auto p2 = sol.wordBreak(p0, p1);
        for (auto it : p2) cout << it << endl;
    }

    return 0;
}