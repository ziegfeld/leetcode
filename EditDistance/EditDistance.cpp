//============================================================================
// Given two words word1 and word2, find the minimum number of steps required
// to convert word1 to word2. (each operation is counted as 1 step.)
//
// You have the following 3 operations permitted on a word:
//
// a) Insert a character
// b) Delete a character
// c) Replace a character
//
// Complexity:
// DP, O(m*n) time, O(m*n) space
// Squeeze memory, O(m*n) time, O(n) space
//============================================================================

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        return minDistance2(word1, word2);
    }

    int minDistance1(string & word1, string & word2) {
        int M = word1.size(), N = word2.size();
        vector<vector<int> > dp(M + 1, vector<int>(N + 1, 0));
        for (int i = 0; i <= M; i++) {
            for (int j = 0; j <= N; j++) {
                if (i == 0) dp[i][j] = j;
                else if (j == 0) dp[i][j] = i;
                else dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]) + 1, dp[i - 1][j - 1] + (word1[i - 1] != word2[j - 1]));
            }
        }

        return dp[M][N];
    }

    int minDistance2(string & word1, string & word2) {
        int M = word1.size(), N = word2.size();
        vector<vector<int> > dp(2, vector<int>(N + 1, 0));
        int pre = -1, cur = 0;
        for (int j = 0; j <= N; j++) dp[cur][j] = j;
        for (int i = 1; i <= M; i++) {
            pre = cur;
            cur = !cur;
            for (int j = 0; j <= N; j++) {
                if (j == 0) dp[cur][j] = i;
                else dp[cur][j] = min(min(dp[cur][j - 1], dp[pre][j]) + 1, dp[pre][j - 1] + (word1[i - 1] != word2[j - 1]));
            }
        }

        return dp[cur][N];
    }
};

int main() {
    return 0;
}
