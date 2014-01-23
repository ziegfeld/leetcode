//============================================================================
// Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle
// containing all ones and return its area.
//
// Complexity:
// dp O(n^3) time
// largest rectangle in histogram O(n^2) time
//============================================================================

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        return maximalRectangle2(matrix);
    };

    int maximalRectangle1(vector<vector<char> > &matrix) {
        int M = matrix.size();
        int N = matrix[0].size();
        vector<vector<int> > dp(M, vector<int>(N, 0));
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = (i==0)?1:dp[i-1][j]+1;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                int minv = dp[i][j];
                for (int k = i; k >= 0; k--) {
                    minv = min(minv, dp[k][j]);
                    res = max(res, minv*(i-k+1));
                }
            }
        }

        return res;
    }

    int maximalRectangle2(vector<vector<char> > &matrix) {
        int M = matrix.size();
        int N = matrix[0].size();
        vector<vector<int> > dp(M, vector<int>(N+1, 0));
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = (i==0)?1:dp[i-1][j]+1;
                }
            }
        }

        int res = 0;
        for (int i = 0; i < M; i++) {
            stack<int> stk;
            int j = 0;
            while (j <= N) {
                if (stk.empty() || dp[i][stk.top()] <= dp[i][j]) {
                    stk.push(j++);
                    continue;
                }
                int k = stk.top();
                stk.pop();
                res = max(res, dp[i][k]*(stk.empty()?j:(j-stk.top()-1)));
            }
        }
        return res;
    }
};

int main() {
    return 0;
}
