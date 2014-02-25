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
// 2D Binary Search O(m*nlog(m*n)) time
// Upper Right Linear Search O(m*n) time
// 1D Binary Search O(log(m*n)) time
//============================================================================

#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // int m = matrix.size() - 1, n = matrix[0].size() - 1;
        // if (target > matrix[m][n]) return false;
        // int m1 = 0, n1 = 0;
        return searchMatrix2(matrix,target);
        //return searchBlock(matrix, target, m1, n1, m, n);
    }
    
    //textbook solution
    //http://leetcode.com/2010/10/searching-2d-sorted-matrix-part-ii.html
    //"step-wise Linear Search" (starting with the upper right corner and traverse only either to the left or the bottom.)
    bool searchMatrix2(vector<vector<int> > & matrix, int target) {
        int M = matrix.size(), N = matrix[0].size();
        int i = 0, j = N - 1;
        while (i < M && j >= 0) {
            if (matrix[i][j] == target) return true;
            if (matrix[i][j] < target) i++;
            else j--;
        }
        return false;
    }

bool binPart(int mat[][N_MAX], int M, int N, int target, int l, int u, int r, int d, int &targetRow, int &targetCol) {
  if (l > r || u > d) return false;
  if (target < mat[u][l] || target > mat[d][r]) return false;
  int mid = l + (r-l)/2;
  int row = u;
  while (row <= d && mat[row][mid] <= target) {
    if (mat[row][mid] == target) {
      targetRow = row;
      targetCol = mid;
      return true;
    }
    row++;
  }
  return binPart(mat, M, N, target, mid+1, u, r, row-1, targetRow, targetCol) ||
         binPart(mat, M, N, target, l, row, mid-1, d, targetRow, targetCol);
}
 
bool binPart(int mat[][N_MAX], int N, int target, int &row, int &col) {
  return binPart(mat, N, N, target, 0, 0, N-1, N-1, row, col);
}
    //https://github.com/anson627/leetcode/blob/master/Searcha2DMatrix/Searcha2DMatrix.cpp
    bool searchMatrix3(vector<vector<int> > & matrix, int target) {
        searchMatrix3(matrix, target);
    }

    bool searchMatrix(vector<vector<int> > & matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        return searchMatrix1(matrix, target);
    }

    bool searchMatrix1(vector<vector<int> > &matrix, int target) {
        int M = matrix.size(), N = matrix[0].size();
        return searchMatrixHelper1(matrix, target, 0, M - 1, 0, N - 1);
    }

    bool searchMatrixHelper1(vector<vector<int> > &matrix, int target, int upper, int bottom, int left, int right) {
        if (upper > bottom || left > right) return false;
        int mid = left + (right - left) / 2;
        int row = upper;
        for (; row <= bottom && matrix[row][mid] <= target; row++) if (matrix[row][mid] == target) return true;
        return searchMatrixHelper1(matrix, target, row, bottom, left, mid - 1) || searchMatrixHelper1(matrix, target, upper, row - 1, mid + 1, right);
    }

    bool searchMatrix2(vector<vector<int> > & matrix, int target) {
        int M = matrix.size(), N = matrix[0].size();
        int i = 0, j = N - 1;
        while (i < M && j >= 0) {
            if (matrix[i][j] == target) return true;
            if (matrix[i][j] < target) i++;
            else j--;
        }
        return false;
    }

    bool searchMatrix3(vector<vector<int> > & matrix, int target) {
        int M = matrix.size();
        int N = matrix[0].size();
        int l = 0, u = M*N - 1;
        while (l <= u) {
            int m = l + (u - l) / 2;
            if (matrix[m / N][m%N] == target) return true;
            if (matrix[m / N][m%N] < target) l = m + 1;
            else u = m - 1;
        }
        return false;
    }
    

    
    
    // my wrong answer!!
    bool searchBlock(vector<vector<int>> matrix, int target, int m1, int n1, int m, int n) {
        // do as few recursions as possible.
        
        //  /-------\
        //  | A | B |
        //  |-------|
        //  | C | D |
        //  \-------/
        
        while (m1 <= m && n1 <= n) {
            if (m1 == m && n1 == n) return (target == matrix[m][n]);
            
            int m2 = m1 + (m - m1) / 2;
            int n2 = n1 + (n - n1) / 2;

            // if (target < matrix[m2][n2]) { // could be A
            //     //   m = m2; n = n2;

            
            if (target == matrix[m2][n]) return true;
            if (target < matrix[m2][n]) { // A B not D. BUT C unknown
                if (n!=n2 && target < matrix[m][n2]) { // get C done
                    if (searchBlock(matrix, target, m2, n2, m, n2))
                        return true;
                }
                m = m2;  // A and B
                if (target == matrix[m2][n2])
                    return true;
                if (target < matrix[m2][n2]) //go A
                    n = n2;
                else // go B
                    n1 = n2 + 1; 
            } else { // not A B. either C or D
                m1 = m2 + 1;
                if (target == matrix[m][n2]) return true;
                if (target < matrix[m][n2]) // go C
                    n = n2; 
                else n1 = n2 + 1; // go D
            }
        
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
