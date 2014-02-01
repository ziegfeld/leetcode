//============================================================================
// Decode Ways
// A message containing letters from A-Z is being encoded to numbers using
// the following mapping:
//
// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
// Given an encoded message containing digits, determine the total number of
// ways to decode it.
//
// For example,
// Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
//
// The number of ways decoding "12" is 2.
//
// Complexity:
// Recursion + Memoization, O(2^n) time, O(n) space
// DP, O(n) time, O(n) space
// Squeeze memory, O(n) time, O(1) space
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        return numDecodings1(s);
    }

    int memo[4098];

    int numDecodings1(string & s) {
        if (s.empty()) return 0;
        memset(memo, -1, sizeof(memo));
        return numDecodingsHelper1(s, s.size(), 0);
    }

    int numDecodingsHelper1(string & s, int N, int i) {
        if (memo[i] != -1) return memo[i];
        if (i == N) return memo[i] = 1;
        if (s[i] < '0' || s[i] > '9') return memo[i] = 0;
        int res = 0;
        if (s[i] != '0') res += numDecodingsHelper1(s, N, i + 1);
        if (i < N - 1 && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))) {
            res += numDecodingsHelper1(s, N, i + 2);
        }
        return memo[i] = res;
    }

    int numDecodings2(string & s) {
        if (s.empty()) return 0;
        int N = s.size();
        vector<int> dp(N + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= N; i++) {
            if (s[i - 1] < '0' || s[i - 1] > '9') return 0;
            if (s[i - 1] != '0') dp[i] = dp[i - 1];
            if (i > 1 && (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6'))) dp[i] += dp[i - 2];
            if (dp[i] == 0) return 0;
        }
        return dp[N];
    }

    int numDecodings3(string & s) {
        if (s.empty()) return 0;
        int N = s.size();
        int dp2 = 0, dp1 = 1, res = 0;
        for (int i = 1; i <= N; i++) {
            res = 0;
            if (s[i - 1] < '0' || s[i - 1] > '9') return 0;
            if (s[i - 1] != '0') res = dp1;
            if (i > 1 && (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6'))) res += dp2;
            if (res == 0) return 0;
            dp2 = dp1;
            dp1 = res;
        }

        return res;
    }
};

int main() {
    Solution sol;
    string p0;
    {
        p0 = "12";
        cout << sol.numDecodings(p0) << "," << 2 << endl;
    }

    {
        p0 = "27";
        cout << sol.numDecodings(p0) << "," << 1 << endl;
    }

    {
        p0 = "17";
        cout << sol.numDecodings(p0) << "," << 2 << endl;
    }

    {
        p0 = "10";
        cout << sol.numDecodings(p0) << "," << 1 << endl;
    }

    return 0;
}