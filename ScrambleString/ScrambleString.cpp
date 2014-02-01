//============================================================================
// Scramble String
// Given a string s1, we may represent it as a binary tree by partitioning it
// to two non-empty substrings recursively.
//
// Below is one possible representation of s1 = "great":
//
//    great
//   /    \
//  gr    eat
// / \    /  \
//g   r  e   at
//           / \
//          a   t
//To scramble the string, we may choose any non-leaf node and swap its two
// children.
//
//For example, if we choose the node "gr" and swap its two children, it
// produces a scrambled string "rgeat".
//
//    rgeat
//   /    \
//  rg    eat
// / \    /  \
//r   g  e   at
//           / \
//          a   t
//We say that "rgeat" is a scrambled string of "great".
//
//Similarly, if we continue to swap the children of nodes "eat" and "at", it
// produces a scrambled string "rgtae".
//
//    rgtae
//   /    \
//  rg    tae
// / \    /  \
//r   g  ta  e
//       / \
//      t   a
//We say that "rgtae" is a scrambled string of "great".
//
//Given two strings s1 and s2 of the same length, determine if s2 is a
// scrambled string of s1.
//
// Complexity:
//
// Recursion: O(2^n) time
// DP: O(n^4) time, O(n^4) space
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        return isScramble2(s1, s2);
    }

    bool isScramble1(string & s1, string & s2) {
        return isScramble1Helper1(s1, 0, s1.size(), s2, 0, s2.size());
    }

    bool isScramble1Helper1(string & s1, int l1, int u1, string & s2, int l2, int u2) {
        if (!hasSameChars(s1, l1, u1, s2, l2, u2)) return false;
        if (u1 - l1 == 1) return true;
        for (int i = 1; i < u1 - l1; i++) {
            if ((isScramble1Helper1(s1, l1, l1 + i, s2, l2, l2 + i) && isScramble1Helper1(s1, l1 + i, u1, s2, l2 + i, u2)) ||
                (isScramble1Helper1(s1, l1, l1 + i, s2, u2 - i, u2) && isScramble1Helper1(s1, l1 + i, u1, s2, l2, u2 - i))) return true;
        }
        return false;
    }

    bool hasSameChars(string & s1, int l1, int u1, string & s2, int l2, int u2) {
        if (u1 - l1 != u2 - l2) return false;
        int c[256] = { 0 };
        for (int i = l1; i < u1; i++) c[s1[i]]++;
        for (int i = l2; i < u2; i++) c[s2[i]]--;
        for (int i = 0; i < 256; i++) if (c[i]) return false;
        return true;
    }

    bool isScramble2(string & s1, string & s2) {
        if (s1.size() != s2.size()) return false;
        if (s1 == s2) return true;
        int N = s1.size();
        vector<vector<vector<bool> > > dp(N, vector<vector<bool> >(N, vector<bool>(N, false)));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (s1[i] == s2[j]) dp[i][j][0] = true;
            }
        }

        for (int l = 1; l < N; l++) {
            for (int i = 0; i < N - l; i++) {
                for (int j = 0; j < N - l; j++) {
                    dp[i][j][l] = false;
                    for (int k = 0; k < l; k++) {
                        if ((dp[i][j][k] && dp[i + k + 1][j + k + 1][l - k - 1]) ||
                            (dp[i][j + l - k][k] && dp[i + k + 1][j][l - k - 1])) {
                            dp[i][j][l] = true;
                            break;
                        }
                    }
                }
            }
        }
        return dp[0][0][N - 1];
    }
};

int main() {

    Solution sol;
    cout << sol.isScramble("rgtae", "great") << endl;

    return 0;
}