//============================================================================
// Given a string S, find the longest palindromic substring in S. You may
// assume that the maximum length of S is 1000, and there exists one unique
// longest palindromic substring.
// 
// Complexity:
// dp, take O(n^2) time, O(n^2) space
// greedy, take O(n^2) time, O(1) space
//============================================================================

#include <iostream>

using namespace std;

bool dp[1000][1000];

class Solution {
public:
    string longestPalindrome(string s) {
        return longestPalindrome1(s);
    }

    string longestPalindrome1(string s) {
        memset(dp, 0, sizeof(dp));
        int maxi = 0, maxl = 1, N = s.size();
        for (int j = 0; j < N; j++) {
            for (int i = j; i >= 0; i--) {
                int l = j - i + 1;
                if (s[i] == s[j] && (l <= 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                    if (l > maxl) maxl = l, maxi = i;
                }
            }
        }
        return s.substr(maxi, maxl);
    }

    string longestPalindrome2(string s) {
        int maxi = 0, maxl = 1, N = s.size();
        for (int k = 0; k < N; k++) {
            expand(s, k, k, maxi, maxl);
            expand(s, k, k + 1, maxi, maxl);
        }
        return s.substr(maxi, maxl);
    }

    void expand(string & s, int i, int j, int & maxi, int & maxl) {
        int N = s.size();
        while (i >= 0 && j <= N - 1 && s[i] == s[j]) i--, j++;
        i++, j--;
        int l = j - i + 1;
        if (l > maxl) maxl = l, maxi = i;
    }
};

int main() {
    Solution sol;

    {
        cout << sol.longestPalindrome("abccbd") << endl;
    }

    {
        cout << sol.longestPalindrome("bbbbb") << endl;
    }

    return 0;
}