//============================================================================
// Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle
// containing all ones and return its area.
//
// Complexity:
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
        int M = matrix.size(), N = matrix[0].size();
        int res = 0;
        vector<int> hs(N + 1, 0);
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (matrix[i][j] == '0') hs[j] = 0;
                else hs[j] = hs[j] + 1;
            }
            stack<int> stk;
            for (int j = 0; j <= N; j++) {
                while (!stk.empty() && hs[stk.top()] >= hs[j]) {
                    int h = hs[stk.top()];
                    stk.pop();
                    res = max(res, (stk.empty() ? j : j - stk.top() - 1)*h);
                }
                stk.push(j);
            }
        }
        return res;
    };
};

int main() {
    return 0;
}
