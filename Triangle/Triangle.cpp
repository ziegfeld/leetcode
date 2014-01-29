//============================================================================
// Triangle
// Given a triangle, find the minimum path sum from top to bottom. Each step 
// you may move to adjacent numbers on the row below.
//
// For example, given the following triangle
// [
//     [2],
//    [3,4],
//   [6,5,7],
//  [4,1,8,3]
//             ]
// The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
//
// Note:
// Bonus point if you are able to do this using only O(n) extra space, where 
// n is the total number of rows in the triangle.
//
// Complexity:
// O(n^2) time, O(n^2) space
// O(n^2) time, O(n) space
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        return minimumTotal1(triangle);
    }

    int minimumTotal1(vector<vector<int> > &triangle) {
        int N = triangle.size();
        vector<vector<int> > dp;
        for (int i = 1; i <= N; i++) dp.push_back(vector<int>(i, 0));
        for (int i = N - 1; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                if (i == N - 1) dp[i][j] = triangle[i][j];
                else dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
            }
        }
        return dp[0][0];
    }

    int minimumTotal2(vector<vector<int> > &triangle) {
        if (triangle.empty()) return 0;
        int N = triangle.size();
        vector<int> dp(N, 0);
        for (int i = N - 1; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                if (i == N - 1) dp[j] = triangle[i][j];
                else dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
            }
        }
        return dp[0];
    }
};


int main() {
    Solution sol;
    vector<vector<int> > p0;

    {
        p0 = {
            { 2 },
            { 3, 4 },
            { 6, 5, 7 },
            { 4, 1, 8, 3 }
        };
        cout << sol.minimumTotal(p0) << endl;
    }
    return 0;
}
