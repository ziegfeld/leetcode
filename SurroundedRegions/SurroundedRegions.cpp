//============================================================================
// Given a 2D board containing 'X' and 'O', capture all regions surrounded 
// by 'X'.
//
// A region is captured by flipping all 'O's into 'X's in that surrounded 
// region.
//
// For example,
// X X X X
// X O O X
// X X O X
// X O X X
// After running your function, the board should be:
//
// X X X X
// X X X X
// X X X X
// X O X X
//
// Complexity:
// O(n^2) time, O(n) space
//============================================================================

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char> > &board) {
        if (board.empty() || board[0].empty()) return;
        int M = board.size(), N = board[0].size();
        for (int j = 0; j < N; j++) {
            if (board[0][j] == 'O') bfs(board, 0, j);
            if (board[M - 1][j] == 'O') bfs(board, M - 1, j);
        }
        for (int i = 0; i < M; i++) {
            if (board[i][0] == 'O') bfs(board, i, 0);
            if (board[i][N - 1] == 'O') bfs(board, i, N - 1);
        }
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'D') board[i][j] = 'O';
            }
        }
    }
    const int MAX = 10000;
    void bfs(vector<vector<char> > & board, int i, int j) {
        board[i][j] = 'D';
        int M = board.size(), N = board[0].size();
        queue<int> qs;
        qs.push(i * MAX + j);
        while (!qs.empty()) {
            int n = qs.front();
            qs.pop();
            i = n / MAX, j = n % MAX;
            if (i + 1 < M && board[i + 1][j] == 'O') board[i + 1][j] = 'D', qs.push((i + 1) * MAX + j);
            if (i - 1 >= 0 && board[i - 1][j] == 'O') board[i - 1][j] = 'D', qs.push((i - 1) * MAX + j);
            if (j + 1 < N && board[i][j + 1] == 'O') board[i][j + 1] = 'D', qs.push(i * MAX + j + 1);
            if (j - 1 >= 0 && board[i][j - 1] == 'O') board[i][j - 1] = 'D', qs.push(i * MAX + j - 1);
        }
    }
};

int main() {
    Solution sol;
    vector<vector<char> > p0;

    {
        p0 = {
            { 'O' },
        };
        sol.solve(p0);
        for (auto it1 : p0) {
            for (auto it2 : it1) cout << it2 << " ";
            cout << endl;
        }
    }

    {
        p0 = {
            { 'X', 'X', 'X', 'X' },
            { 'X', 'O', 'O', 'X' },
            { 'X', 'X', 'O', 'X' },
            { 'X', 'O', 'X', 'X' },
        };
        sol.solve(p0);
        for (auto it1 : p0) {
            for (auto it2 : it1) cout << it2 << " ";
            cout << endl;
        }
    }

    return 0;
}