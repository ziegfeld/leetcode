//============================================================================
// Valid Sudoku
// Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
//
// The Sudoku board could be partially filled, where empty cells are filled
// with the character '.'.
//
// Complexity:
// O(N^2) time, N is the size of board
//============================================================================

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        if (board.size() != 9) return false;
        for (int r = 0; r < 9; r++) if (board[r].size() != 9) return false;
        for (int r = 0; r < 9; r++) {
            vector<bool> visit(9, false);
            for (int c = 0; c < 9; c++) if (!check(board, r, c, visit)) return false;
        }
        for (int c = 0; c < 9; c++) {
            vector<bool> visit(9, false);
            for (int r = 0; r < 9; r++) if (!check(board, r, c, visit)) return false;
        }
        for (int i = 0; i < 9; i++) {
            vector<bool> visit(9, false);
            for (int j = 0; j < 9; j++) if (!check(board, i / 3 * 3 + j / 3, i % 3 * 3 + j % 3, visit)) return false;
        }
        return true;
    }

    bool check(vector<vector<char> > &board, int r, int c, vector<bool> & visit) {
        if (board[r][c] == '.') return true;
        if (board[r][c] < '1' || board[r][c] > '9') return false;
        int n = board[r][c] - '1';
        if (visit[n]) return false;
        return visit[n] = true;
    }
};


int main() {
    Solution sol;
    vector<vector<char> > p0 = {
        { '5', '3', '.', '.', '7', '.', '.', '.', '.' },
        { '6', '.', '.', '1', '9', '5', '.', '.', '.' },
        { '.', '9', '8', '.', '.', '.', '.', '6', '.' },
        { '8', '.', '.', '.', '6', '.', '.', '.', '3' },
        { '4', '.', '.', '8', '.', '3', '.', '.', '1' },
        { '7', '.', '.', '.', '2', '.', '.', '.', '6' },
        { '.', '6', '.', '.', '.', '.', '2', '8', '.' },
        { '.', '.', '.', '4', '1', '9', '.', '.', '5' },
        { '.', '.', '.', '.', '8', '.', '.', '7', '9' },
    };
    cout << sol.isValidSudoku(p0) << endl;
    return 0;
}