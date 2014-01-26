//============================================================================
// Sudoku Solver
// Write a program to solve a Sudoku puzzle by filling the empty cells.
//
// Empty cells are indicated by the character '.'.
//
// You may assume that there will be only one unique solution.
//
// Complexity:
// O(M*N^2) time, M is # of empty cells, N is size of board
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        solveSudokuHelper(board, 0, 0);
    }

    bool solveSudokuHelper(vector<vector<char> > &board, int r, int c) {
        if (!getNext(board, r, c)) return true;
        auto ps = getPossible(board, r, c);
        for (auto p : ps) {
            board[r][c] = p;
            if (solveSudokuHelper(board, r, c)) return true;
            board[r][c] = '.';
        }
        return false;
    }

    bool getNext(vector<vector<char> > &board, int & r, int & c) {
        while (r < 9) {
            if (board[r][c] == '.') return true;
            if (c + 1 == 9) r = r + 1, c = 0;
            else c += 1;
        }
        return false;
    }

    vector<char> getPossible(vector<vector<char> > &board, int r, int c) {
        bool visit[9];
        memset(visit, 0, sizeof(visit));
        for (int i = 0; i < 9; i++) {
            if (board[r][i] != '.') visit[board[r][i] - '1'] = true;
            if (board[i][c] != '.') visit[board[i][c] - '1'] = true;
            int rr = r / 3 * 3 + i / 3, cc = c / 3 * 3 + i % 3;
            if (board[rr][cc] != '.') visit[board[rr][cc] - '1'] = true;
        }
        vector<char> res;
        for (int j = 0; j < 9; j++) if (!visit[j]) res.push_back('1' + j);
        return res;
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
    sol.solveSudoku(p0);
    for (auto it1 : p0) {
        for (auto it2 : it1) cout << it2 << " ";
        cout << endl;
    }
    return 0;
}