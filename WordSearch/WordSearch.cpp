//============================================================================
// Word Search
// Given a 2D board and a word, find if the word exists in the grid.
//
// The word can be constructed from letters of sequentially adjacent cell,
// where "adjacent" cells are those horizontally or vertically neighboring.
// The same letter cell may not be used more than once.
//
// For example,
// Given board =
//
// [
//   ["ABCE"],
//   ["SFCS"],
//   ["ADEE"]
// ]
// word = "ABCCED", -> returns true,
// word = "SEE", -> returns true,
// word = "ABCB", -> returns false.
//============================================================================

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if (board.empty() || board[0].empty()) return false;
        int M = board.size(), N = board[0].size();
        vector<vector<bool> > visit(M, vector<bool>(N, false));
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (dfs(board, visit, word, 0, i, j)) return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<char> > &board, vector<vector<bool> > & visit, string & word, int k, int i, int j) {
        if (k == word.size()) return true;
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return false;
        if (visit[i][j] || board[i][j] != word[k]) return false;
        visit[i][j] = true;
        bool res = dfs(board, visit, word, k + 1, i + 1, j) ||
            dfs(board, visit, word, k + 1, i - 1, j) ||
            dfs(board, visit, word, k + 1, i, j + 1) ||
            dfs(board, visit, word, k + 1, i, j - 1);
        visit[i][j] = false;
        return res;
    }
};

int main() {
    return 0;
}
