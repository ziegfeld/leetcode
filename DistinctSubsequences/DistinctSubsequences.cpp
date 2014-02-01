//============================================================================
// Distinct Subsequences
// Given a string S and a string T, count the number of distinct subsequences
// of T in S.
//
// A subsequence of a string is a new string which is formed from the original
// string by deleting some (can be none) of the characters without disturbing
// the relative positions of the remaining characters. (ie, "ACE" is a
// subsequence of "ABCDE" while "AEC" is not).
//
// Here is an example:
// S = "rabbbit", T = "rabbit"
//
// Return 3.
//
// Complexity:
// Recurision + Memoization O(2^n) time
// DP O(n^2) time O(n^2) space
// Squeeze Memory O(n^2) time, O(n) space
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numDistinct(string S, string T) {
        return numDistinct3(S, T);
    }

    int numDistinct1(string & S, string & T) {
        int M = S.size(), N = T.size();
        vector<vector<int> > memo(M + 1, vector<int>(N + 1, -1));
        return numDistinctHelper1(S, T, 0, 0, memo);
    }

    int numDistinctHelper1(string & S, string & T, int i, int j, vector<vector<int> > & memo) {
        if (memo[i][j] != -1) return memo[i][j];
        if (j == T.size()) return memo[i][j] = 1;
        if (i == S.size()) return memo[i][j] = 0;
        int res = numDistinctHelper1(S, T, i + 1, j, memo);
        if (S[i] == T[j]) return res += numDistinctHelper1(S, T, i + 1, j + 1, memo);
        return memo[i][j] = res;
    }

    int numDistinct2(string & S, string & T) {
        int M = S.size(), N = T.size();
        vector<vector<int> > dp(M + 1, vector<int>(N + 1, 0));
        for (int i = 0; i <= M; i++) {
            for (int j = 0; j <= N; j++) {
                if (j == 0) dp[i][j] = 1;
                else if (i == 0) dp[i][j] = 0;
                else dp[i][j] = dp[i - 1][j] + ((S[i - 1] == T[j - 1]) ? dp[i - 1][j - 1] : 0);
            }
        }
        return dp[M][N];
    }

    int numDistinct3(string & S, string & T) {
        int M = S.size(), N = T.size();
        vector<int> dp(N + 1, 0);
        for (int i = 1; i <= M; i++) {
            dp[0] = 1;
            for (int j = N; j > 0; j--) dp[j] += ((S[i - 1] == T[j - 1]) ? dp[j - 1] : 0);
        }
        return dp[N];
    }
};

int main() {
    Solution sol;
    string p0, p1;
    {
        p0 = "rabbbit";
        p1 = "rabbit";
        cout << sol.numDistinct(p0, p1) << "," << 3 << endl;
    }

    {
        p0 = "";
        p1 = "a";
        cout << sol.numDistinct(p0, p1) << "," << 0 << endl;
    }

    return 0;
}