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
    bool isValidSudoku(vector<vector<char> > & board) {
        if (board.size() != 9 || board[0].size() != 9) return false;
        for (int i = 0; i < 9; i++) {
            memset(visit, 0, sizeof(visit));
            for (int j = 0; j < 9; j++) {
                if (!isValid(board[i][j])) return false;
            }
        }

        for (int i = 0; i < 9; i++) {
            memset(visit, 0, sizeof(visit));
            for (int j = 0; j < 9; j++) {
                if (!isValid(board[j][i])) return false;
            }
        }

        for (int i = 0; i < 9; i++) {
            memset(visit, 0, sizeof(visit));
            for (int j = 0; j < 9; j++) {
                int r = i / 3 * 3 + j / 3, c = i % 3 * 3 + j % 3;
                if (!isValid(board[r][c])) return false;
            }
        }

        return true;
    }

    bool isValid(char c) {
        if (c == '.') return true;
        if (c < '1' || c > '9' || visit[c - '1']) return false;
        return visit[c - '1'] = true;
    }

    bool visit[9];
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