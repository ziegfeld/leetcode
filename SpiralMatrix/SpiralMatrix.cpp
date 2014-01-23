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
        if (matrix.empty()) return res;
        spiralOrderHelper(matrix, 0, matrix.size(), matrix[0].size(), res);
        return res;
    }

    void spiralOrderHelper(vector<vector<int> > &matrix, int k, int M, int N, vector<int> & res) {
        if (M <= 0 || N <= 0) return;
        if (M == 1) {
            for (int j = 0; j < N; j++) res.push_back(matrix[k][k+j]);
            return;
        }

        if (N == 1) {
            for (int i = 0; i < M; i++) res.push_back(matrix[k+i][k]);
            return;
        }

        int i = 0, j = 0;
        for (; j < N-1; j++) res.push_back(matrix[k+i][k+j]);
        for (; i < M-1; i++) res.push_back(matrix[k+i][k+j]);
        for (; j > 0; j--) res.push_back(matrix[k+i][k+j]);
        for (; i > 0; i--) res.push_back(matrix[k+i][k+j]);
        spiralOrderHelper(matrix, k+1, M-2, N-2, res);
    }
};

int main() {
    return 0;
}
