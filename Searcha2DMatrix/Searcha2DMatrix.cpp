//============================================================================
// Search a 2D Matrix
// Write an efficient algorithm that searches for a value in an m x n matrix.
// This matrix has the following properties:
//
// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.
// For example,
//
// Consider the following matrix:
//
// [
//  [1,   3,  5,  7],
//  [10, 11, 16, 20],
//  [23, 30, 34, 50]
// ]
// Given target = 3, return true.
// 
// Complexity:
// O(log(mn))
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> > & matrix, int target) {
        int M = matrix.size();
        int N = matrix[0].size();
        int l = 0, u = M*N-1;
        while (l <= u) {
            int m = l+(u-l)/2;
            if (matrix[m/N][m%N] == target) return true;
            if (matrix[m/N][m%N] < target) l = m+1;
            else u = m-1;
        }
        return false;
    }
};

int main() {
    Solution sol;

    {
        vector<vector<int> > p0 = {
            {1,   3,  5,  7},
            {10, 11, 16, 20},
            {23, 30, 34, 50}
        };
        cout << sol.searchMatrix(p0, 3) << endl;
    }

    return 0;
}
