//============================================================================
// Unique Paths II
// Follow up for "Unique Paths":
//
// Now consider if some obstacles are added to the grids. How many unique
// paths would there be?
//
// An obstacle and empty space is marked as 1 and 0 respectively in the grid.
//
// For example,
// There is one obstacle in the middle of a 3x3 grid as illustrated below.
//
// [
//  [0,0,0],
//  [0,1,0],
//  [0,0,0]
// ]
// The total number of unique paths is 2.
//
// Note: m and n will be at most 100.
//
// Complexity:
// DP, O(m*n) time, O(m*n) space
// DP, O(m*n) time, O(n) space
//============================================================================


#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        return uniquePathsWithObstacles1(obstacleGrid);
    }

    int uniquePathsWithObstacles1(vector<vector<int> > &obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty()) return 0;
        int M = obstacleGrid.size(), N = obstacleGrid[0].size();
        vector<vector<int> > dp(M, vector<int>(N, 0));
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (obstacleGrid[i][j]) continue;
                if (i == 0 && j == 0) dp[i][j] = 1;
                else dp[i][j] = ((i == 0) ? 0 : dp[i - 1][j]) + ((j == 0) ? 0 : dp[i][j - 1]);
            }
        }
        return dp[M - 1][N - 1];
    }

    int uniquePathsWithObstacles2(vector<vector<int> > &obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty()) return 0;
        int M = obstacleGrid.size(), N = obstacleGrid[0].size();
        vector<int> dp(N, 0);
        dp[0] = 1;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (obstacleGrid[i][j]) dp[j] = 0;
                else if (j > 0) dp[i] += dp[j - 1];
            }
        }
        return dp[N - 1];
    }
};

int main() {
    Solution sol;
    vector<vector<int> > p0;

    {
        p0 = {
            { 0, 0, 0 },
            { 0, 1, 0 },
            { 0, 0, 0 }
        };
        cout << sol.uniquePathsWithObstacles(p0) << endl;
    }

    return 0;
}