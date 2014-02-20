//============================================================================
// Given a m x n grid filled with non-negative numbers, find a path from top
// left to bottom right which minimizes the sum of all numbers along its path.
//
// Note: You can only move either down or right at any point in time.
//
// Complexity:
// DP, O(m*n) time, O(m*n) space
// DP, O(m*n) time, O(n) space
//============================================================================

#include <vector>
#include <queue>
#include <climits>
#include <iostream>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n,0);
        dp[0] = grid[0][0];
        for (int i = 1; i < n; i++)
            dp[i] = grid[0][i] + dp[i-1];
        
        for (int k = 1; k <m; k++) {
            dp[0] = dp[0] + grid[k][0];
            for (int i = 1; i != n; i++)
                dp[i] = grid[k][i] + min(dp[i], dp[i-1]);
        }
        return dp[n-1];
    }
};

int main() {
    return 0;
}
