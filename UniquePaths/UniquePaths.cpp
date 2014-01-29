//============================================================================
// Unique Paths
// A robot is located at the top-left corner of a m x n grid (marked 'Start'
// in the diagram below).
//
// The robot can only move either down or right at any point in time. The robot
// is trying to reach the bottom-right corner of the grid (marked 'Finish' in
// the diagram below).
//
// How many possible unique paths are there?
//
// Complexity:
// DP, O(m*n) time, O(1) space
// DP, O(m*n) time, O(n) space
// Math, O(n) time, O(1) space
//============================================================================

#include <iostream>
#include <cstring>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        return uniquePaths1(m, n);
    }

    int uniquePaths1(int m, int n) {
        vector<vector<int> > dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0) dp[i][j] = 1;
                else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }

    int uniquePaths2(int m, int n) {
        vector<int> dp(n, 0);
        dp[0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[j] += dp[j - 1];
            }
        }
        return dp[N - 1];
    }

    int uniquePaths3(int m, int n) {
        long long res = 1;
        for (int i = 1; i < n; i++) {
            res = res * (i + m - 1) / i;
        }
        return (int)res;
    }
};

int main() {
    return 0;
}
