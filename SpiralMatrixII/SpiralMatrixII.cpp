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
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > res(n, vector<int>(n, 0));
        spiralOrderHelper(res, 0, n, 0);
        return res;
    }

    void spiralOrderHelper(vector<vector<int> > &res, int k, int n, int v) {
        if (n <= 0) return;
        if (n == 1) {
            res[k][k] = ++v;
            return;
        }

        int i = 0, j = 0;
        for (; j < n-1; j++) res[k+i][k+j] = ++v;
        for (; i < n-1; i++) res[k+i][k+j] = ++v;
        for (; j > 0; j--) res[k+i][k+j] = ++v;
        for (; i > 0; i--) res[k+i][k+j] = ++v;
        spiralOrderHelper(res, k+1, n-2, v);
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
