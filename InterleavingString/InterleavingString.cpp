//============================================================================
// Interleaving String
// Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
//
// For example,
// Given:
// s1 = "aabcc",
// s2 = "dbbca",
//
// When s3 = "aadbbcbcac", return true.
// When s3 = "aadbbbaccc", return false.
//
// Complexity:
// Recursion + Memoization O(2^n) time
// DP O(n^2) time, O(n^2) space
//============================================================================

#include <iostream>
using namespace std;

int memo[1024][1024];

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        return isInterleave2(s1, s2, s3);
    }

    bool isInterleave1(string & s1, string & s2, string & s3) {
        memset(memo, -1, sizeof(int)* 1024 * 1024);
        return isInterleaveHelper1(s1, s2, s3, 0, 0);
    }

    bool isInterleaveHelper1(string & s1, string & s2, string & s3, int i, int j) {
        if (memo[i][j] != -1) return memo[i][j];
        if (i == s1.size() && j == s2.size() && i + j == s3.size()) return memo[i][j] = true;
        if (i == s1.size()) return memo[i][j] = (s2[j] == s3[i + j] && isInterleaveHelper1(s1, s2, s3, i, j + 1));
        if (j == s2.size()) return memo[i][j] = (s1[i] == s3[i + j] && isInterleaveHelper1(s1, s2, s3, i + 1, j));
        return memo[i][j] = (s1[i] == s3[i + j] && isInterleaveHelper1(s1, s2, s3, i + 1, j)) ||
            (s2[j] == s3[i + j] && isInterleaveHelper1(s1, s2, s3, i, j + 1));
    }

    bool isInterleave2(string & s1, string & s2, string & s3) {
        int M = s1.size(), N = s2.size();
        if (M + N != s3.size()) return false;
        vector<vector<bool> > dp(M + 1, vector<bool>(N + 1, 0));
        for (int i = 0; i <= M; i++) {
            for (int j = 0; j <= N; j++) {
                if (i == 0 && j == 0) dp[i][j] = true;
                else if (i == 0) dp[i][j] = (s2[j - 1] == s3[j - 1]) && dp[i][j - 1];
                else if (j == 0) dp[i][j] = (s1[i - 1] == s3[i - 1]) && dp[i - 1][j];
                else dp[i][j] = ((s2[j - 1] == s3[i + j - 1]) && dp[i][j - 1]) || ((s1[i - 1] == s3[i + j - 1]) && dp[i - 1][j]);
            }
        }
        return dp[M][N];
    }
};

int main() {
    Solution sol;
    string p0, p1, p2;

    {
        p0 = "aabcc";
        p1 = "dbbca";
        p2 = "aadbbcbcac";
        cout << sol.isInterleave(p0, p1, p2) << "," << 1 << endl;
    }

    {
        p0 = "aabcc";
        p1 = "dbbca";
        p2 = "aadbbbaccc";
        cout << sol.isInterleave(p0, p1, p2) << "," << 0 << endl;
    }

    {
        p0 = "";
        p1 = "b";
        p2 = "b";
        cout << sol.isInterleave(p0, p1, p2) << "," << 1 << endl;
    }

    {
        p0 = "a";
        p1 = "";
        p2 = "a";
        cout << sol.isInterleave(p0, p1, p2) << "," << 1 << endl;
    }

    {
        p0 = "aa";
        p1 = "ab";
        p2 = "aaba";
        cout << sol.isInterleave(p0, p1, p2) << "," << 1 << endl;
    }

    {
        p0 = "aabc";
        p1 = "abad";
        p2 = "aabacbad";
        cout << sol.isInterleave(p0, p1, p2) << "," << 1 << endl;
    }

    return 0;
}