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
        int N = s.size();
        vector<vector<bool> > dp1(N, vector<bool>(N, false));
        vector<int> dp2(N, N);
        for (int j = 0; j < N; j++) {
            for (int i = j; i >= 0; i--) {
                if (s[i] == s[j] && (j - i < 2 || dp1[i + 1][j - 1])) {
                    dp1[i][j] = true;
                    if (i == 0) dp2[j] = 0;
                    else dp2[j] = min(dp2[j], dp2[i - 1] + 1);
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