//============================================================================
// N-Queens
//
// The n-queens puzzle is the problem of placing n queens on an n×n chessboard
// such that no two queens attack each other.
//
// Complexity:
// O(n^(n+2)) time
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<int> pos(n,0);  // pos[i]= j means row i, col j has a queen.
        vector<vector<string> > res;
        
        //helper1(pos,n,0,res);
        helper2(pos,n,0, 0,0,0,res);
        return res;
    }
    
    void helper2(vector<int> & pos, int n, int row, int flagColomn, int zhuDuijiao, int fuDuijiao, vector<vector<string> > & res) {
        if (row == n) {
            res.push_back(board(pos, n));
            return;
        }
        //y is (1<<n - 1) wrong?  cuz n-1 is cal'ed first then 1<<!! should be (1<<n) - 1
        int mask =  (1<<n) - 1;
        zhuDuijiao &= mask;
        int curBit = 1, flag = flagColomn | fuDuijiao | zhuDuijiao;
        for (int j = 0; j < n; j++) {
            if ((flag & curBit) == 0) {
                pos[row] = j;     
                helper2(pos,n,row+1, flagColomn|curBit, (zhuDuijiao|curBit)<<1, (fuDuijiao|curBit)>>1, res);
            }
            curBit <<= 1;
        }
    }
    void helper1(vector<int> & pos, int n, int i, vector<vector<string> > & res) {
        if (i == n) {
            res.push_back(board(pos, n));
            return;
        }
        for (int j = 0; j < n; j++) {
            // check if (i,j) cell feasible
            bool legal = true;
            for (int k = 0; k < i; k++)
                if (pos[k] == j || oneLine(i,j,k,pos[k]) ) {
                    legal = false;
                    break;
                }
            if (legal) {
                pos[i] = j;
                helper1(pos,n,i+1,res);
            }
        }
        
    }
    
    vector<string> board(vector<int> pos, int n) {
        vector<string> res(n,string(n,'.'));
        for (int i = 0; i < n; i ++)
            res[i][pos[i]] = 'Q';
        return res;
    }
    
    inline bool oneLine(int x1, int y1, int x2, int y2) {
        return ((x1-x2 == y1-y2) || (x1 - x2 == y2 - y1));
    }
};

int main() {
    Solution sol;
    int p0;

    {
        p0 = 4;
        auto p1 = sol.solveNQueens(p0);
        for (auto it1 : p1) {
            for (auto it2 : it1) cout << it2 << endl;
            cout << endl;
        }
    }

    return 0;
}
