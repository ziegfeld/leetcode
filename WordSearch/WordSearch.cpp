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
        if (board.empty() || board[0].empty() || word.empty()) return false;
        return exist1(board, word);
    }

    bool exist1(vector<vector<char> > &board, string & word) {
        int M = board.size(), N = board[0].size();
        vector<vector<bool> > visited(M, vector<bool>(N, false));
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == word[0] && existHelper1(board, visited, i, j, word, 0)) return true;
            }
        }
        return false;
    }

    bool existHelper1(vector<vector<char> > & board, vector<vector<bool> > & visited, int i, int j, string &word, int k) {
        k++;
        if (k == word.size()) return true;
        int M = board.size(), N = board[0].size();
        visited[i][j] = true;
        if ((i > 0 && !visited[i - 1][j]) && board[i - 1][j] == word[k] && existHelper1(board, visited, i - 1, j, word, k)) return true;
        if ((i < M - 1 && !visited[i + 1][j]) && board[i + 1][j] == word[k] && existHelper1(board, visited, i + 1, j, word, k)) return true;
        if ((j > 0 && !visited[i][j - 1]) && board[i][j - 1] == word[k] && existHelper1(board, visited, i, j - 1, word, k)) return true;
        if ((j < N - 1 && !visited[i][j + 1]) && board[i][j + 1] == word[k] && existHelper1(board, visited, i, j + 1, word, k)) return true;
        visited[i][j] = false;
        return false;
    };
};

int main() {
    return 0;
}
