//============================================================================
// Set Matrix Zeroes
// Given a m x n matrix, if an element is 0, set its entire row and column to
// 0. Do it in place.
//
// Follow up:
// Did you use extra space?
// A straight forward solution using O(mn) space is probably a bad idea.
// A simple improvement uses O(m + n) space, but still not the best solution.
// Could you devise a constant space solution?
//
// Complexity:
// O(m*n) time
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        setZeroes2(matrix);
    }

    void setZeroes1(vector<vector<int> > &matrix) {
        int M = matrix.size(), N = matrix[0].size();
        vector<int> rows(M, 1);
        vector<int> cols(N, 1);
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (matrix[i][j] == 0) rows[i] = cols[j] = 0;
            }
        }
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (rows[i] == 0 || cols[j] == 0) matrix[i][j] = 0;
            }
        }
    }

    void setZeroes2(vector<vector<int> > &matrix) {
        int M = matrix.size(), N = matrix[0].size();
        int fr = 1;
        for (int j = 0; j < N; j++) {
            if (matrix[0][j] == 0) {
                fr = 0;
                break;
            }
        }
        int fc = 1;
        for (int i = 0; i < M; i++) {
            if (matrix[i][0] == 0) {
                fc = 0;
                break;
            }
        }
        for (int i = 1; i < M; i++) {
            for (int j = 1; j < N; j++) {
                if (matrix[i][j] == 0) matrix[i][0] = matrix[0][j] = 0;
            }
        }
        for (int i = 1; i < M; i++) {
            for (int j = 1; j < N; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
            }
        }
        if (fr == 0) {
            for (int j = 0; j < N; j++) matrix[0][j] = 0;
        }

        if (fc == 0) {
            for (int i = 0; i < M; i++) matrix[i][0] = 0;
        }
    }
};


int main() {
    return 0;
}
