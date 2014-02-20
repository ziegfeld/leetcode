//============================================================================
// N-Queens II
// Follow up for N-Queens problem.
//
// Now, instead outputting board configurations, return the total number of
// distinct solutions.
//
// Complexity:
// O(n^n)
//============================================================================

#include <iostream>

using namespace std;
class Solution {
public:
    int totalNQueens(int n) {
        int res = 0;
        helper2(n,0, 0,0,0,res);
        return res;
    }

    void helper2(int n, int row, int flagColomn, int zhuDuijiao, int fuDuijiao, int & res) {
        if (row == n) {
            res++;
            return;
        }
        //y is (1<<n - 1) wrong?  cuz n-1 is cal'ed first then 1<<!! should be (1<<n) - 1
        // int mask =  (1<<n) - 1;
        // zhuDuijiao &= mask;
        //actually these 2 lines are unneccessary.
        int curBit = 1, flag = flagColomn | fuDuijiao | zhuDuijiao;
        for (int j = 0; j < n; j++) {
            if ((flag & curBit) == 0) { 
                helper2(n,row+1, flagColomn|curBit, (zhuDuijiao|curBit)<<1, (fuDuijiao|curBit)>>1, res);
            }
            curBit <<= 1;
        }
    }
};

int main() {
    Solution sol;
    int p0;

    {
        p0 = 4;
        cout << sol.totalNQueens(p0) << endl;
    }

    return 0;
}
