//============================================================================
// Palindrome Partitioning II
// Given a string s, partition s such that every substring of the partition 
// is a palindrome.
//
// Return the minimum cuts needed for a palindrome partitioning of s.
//
// For example, given s = "aab",
// Return 1 since the palindrome partitioning ["aa","b"] could be produced 
// using 1 cut.
//
// Complexity:
// O(n^2) time, O(n^2) space
//============================================================================

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int minCut(string s) {
        return minCut2(s);
    }

    int minCut1(string & s) {
        int N = s.size();
        vector<vector<bool> > dp1(N, vector<bool>(N, false));
        for (int l = 1; l <= N; l++) {
            for (int i = 0; i < N - l + 1; i++) {
                int j = i + l - 1;
                if (s[i] == s[j] && (l <= 2 || dp1[i + 1][j - 1])) dp1[i][j] = true;
            }
        }

        vector<int> dp2(N, 0);
        for (int i = 1; i < N; i++) {
            dp2[i] = i;
            for (int j = 0; j <= i; j++) {
                if (dp1[j][i]) dp2[i] = min(dp2[i], (j == 0) ? 0 : dp2[j - 1] + 1);
            }
        }
        return dp2[N - 1];
    }

    int minCut2(string & s) {
        int N = s.size();
        vector<vector<bool> > dp1(N, vector<bool>(N, false));
        vector<int> dp2(N, 0);
        for (int i = 1; i < N; i++) {
            dp2[i] = i;
            for (int j = 0; j <= i; j++) {
                if (s[j] == s[i] && (i - j < 2 || dp1[j + 1][i - 1])) {
                    dp1[j][i] = true;
                    dp2[i] = min(dp2[i], (j == 0) ? 0 : dp2[j - 1] + 1);
                }
            }
        }
        return dp2[N - 1];
    }
};

int main() {
    Solution sol;
    string p0;

    {
        p0 = "aab";
        cout << sol.minCut(p0) << endl;
    }

    {
        p0 = "abbab";
        cout << sol.minCut(p0) << endl;
    }

    return 0;
}