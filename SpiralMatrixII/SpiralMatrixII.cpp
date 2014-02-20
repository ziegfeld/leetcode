//============================================================================
// Spiral Matrix II
// Given an integer n, generate a square matrix filled with elements from 1 to
// n2 in spiral order.
//
// For example,
// Given n = 3,
//
// You should return the following matrix:
// [
// [ 1, 2, 3 ],
// [ 8, 9, 4 ],
// [ 7, 6, 5 ]
// ]
//
// Complexity:
// O(n^2)
//============================================================================


#include <iostream>
#include <vector>

using namespace std;

class Solution {

    vector<vector<int>> inc = { 
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0}
    };

public:
    
    vector<vector<int> > generateMatrix(int n) {
        if (n == 0) {
            vector<vector<int>> res;
            return res;
        }
        
        vector<vector<int>> res(n, vector<int>(n, 0));
        //first row is special.
        for (int i = 0; i < n; ++i)
            res[0][i] = i + 1;
        
        int i = 0, j = n - 1;
        int i_inc = 1, value = n;
        int length = n - 1;
        for (; length != 0; length --) {
            for (int k = 0; k < length; k++) {
                i += inc[i_inc][0];
                j += inc[i_inc][1];
                res[i][j] = ++ value;
            }
            i_inc = (++i_inc) % 4;
            for (int k = 0; k < length; k++) {
                i += inc[i_inc][0];
                j += inc[i_inc][1];
                res[i][j] = ++ value;
            }
            i_inc = (++i_inc) % 4;
        }
        return res;
    }
    
    // this version does four lines (i_inc from 0 to 3) for a round intead of my way - 2 lines a round.
    //https://github.com/anson627/leetcode/blob/master/SpiralMatrixII/SpiralMatrixII.cpp
    vector<vector<int> > generateMatrix1(int n) {
        vector<vector<int> > res;
        if (n <= 0) return res;
        for (int i = 0; i < n; i++) res.push_back(vector<int>(n, 0));
        for (int k = 0, v = 1; n > 0; k++, n -= 2) {
            int i = 0, j = 0;
            if (n == 1) {
                res[k + i][k + j] = v++;
                return res;
            }

            for (; j < n - 1; j++) res[k + i][k + j] = v++;
            for (; i < n - 1; i++) res[k + i][k + j] = v++;
            for (; j > 0; j--) res[k + i][k + j] = v++;
            for (; i > 0; i--) res[k + i][k + j] = v++;
        }
        return res;
    }
};

int main() {
    Solution sol;

    {
        auto res = sol.generateMatrix(3);
        for (auto it1 : res) {
            for (auto it2 : it1) cout << it2 << " ";
            cout << endl;
        }
    }
    
    return 0;
}
