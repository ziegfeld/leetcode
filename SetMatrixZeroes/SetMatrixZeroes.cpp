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
        int m = matrix.size(), n = matrix[0].size();
        if (m == 0 || n == 0) return;
        
        bool is1stColomnZero = false, is1stRowZero = false;
        for (int i = 0; i < m; i++)
            if (matrix[i][0] == 0) {
                is1stColomnZero = true;
                break;
            }
        for (int j = 0; j < n; j++)
            if (matrix[0][j] == 0) {
                is1stRowZero = true;
                break;
        }
        
        for (int i = 0; i < m; i++ )
            for (int j = 0; j < n; j++)
                if (matrix[i][j] == 0) 
                    matrix[i][0] = 0, matrix[0][j] = 0;
                
        for (int i = 1; i < m; i++ )
            if (matrix[i][0] == 0) 
                for (int j = 1; j < n; j++)
                    matrix[i][j] = 0;

        for (int j = 1; j < n; j++)
            if (matrix[0][j] == 0) 
                for (int i = 1; i < m; i++ )
                    matrix[i][j] = 0;
            
        if (is1stColomnZero)
            for (int i = 0; i < m; i++)
                matrix[i][0] = 0;
        if (is1stRowZero)
            for (int j = 0; j < n; j++)
                matrix[0][j] = 0;
    }
};


int main() {
    return 0;
}
