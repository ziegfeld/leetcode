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
        return totalNQueens1(n);
    }

    int totalNQueens1(int n) {
        vector<int> board(n, -1);
        int res = 0;
        totalNQueensHelper1(board, 0, res);
        return res;
    }

    void totalNQueensHelper1(vector<int> & board, int row, int & res) {
        int N = board.size();
        if (row == N) {
            res++;
            return;
        }
        for (int col = 0; col < N; col++) {
            if (!isValid(board, row, col)) continue;
            board[row] = col;
            totalNQueensHelper1(board, row + 1, res);
        }
    }

    bool isValid(vector<int> & board, int row, int col) {
        for (int r = 0; r < row; r++) if (board[r] == col || abs(board[r] - col) == row - r) return false;
        return true;
    }

    int totalNQueens2(int n) {
        int res = 0;
        totalNQueensHelper2(n, 0, 0, 0, 0, res);
        return res;
    }

    void totalNQueensHelper2(int N, int row, int cur, int ld, int rd, int & res) {
        int mask = (1 << N) - 1;
        if (cur == mask) {
            res++;
            return;
        }

        int cs = ~(cur | ld | rd) & mask;
        while (cs > 0) {
            int p = cs & -cs;
            cs -= p;
            totalNQueensHelper2(N, row + 1, cur | p, (ld | p) << 1, (rd | p) >> 1, res);
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