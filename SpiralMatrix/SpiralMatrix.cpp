//============================================================================
// Spiral Matrix
// Given a matrix of m x n elements (m rows, n columns), return all elements
// of the matrix in spiral order.
//
// For example,
// Given the following matrix:
//
// [
// [ 1, 2, 3 ],
// [ 4, 5, 6 ],
// [ 7, 8, 9 ]
// ]
// You should return [1,2,3,6,9,8,7,4,5].
//
// Complexity:
// O(mn)
//============================================================================

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res;
        if (matrix.empty() || matrix[0].empty()) return res;
        for (int k = 0, m = matrix.size(), n = matrix[0].size(); m > 0 && n > 0; k++, m -= 2, n -= 2) {
            int i = 0, j = 0;
            if (m == 1) {
                for (; j < n; j++) res.push_back(matrix[k + i][k + j]);
                return res;
            }

            if (n == 1) {
                for (; i < m; i++) res.push_back(matrix[k + i][k + j]);
                return res;
            }

            for (; j < n - 1; j++) res.push_back(matrix[k + i][k + j]);
            for (; i < m - 1; i++) res.push_back(matrix[k + i][k + j]);
            for (; j > 0; j--) res.push_back(matrix[k + i][k + j]);
            for (; i > 0; i--) res.push_back(matrix[k + i][k + j]);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int> >  p0;

    {
        p0 = {
            { 1, 2, 3 },
            { 4, 5, 6 },
            { 7, 8, 9 },
        };
        auto p1 = sol.spiralOrder(p0);
        for (auto it : p1) cout << it << " ";
        cout << endl;
    }

    return 0;
}