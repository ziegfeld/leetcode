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


class Solution {
public:
    string longestPalindrome(string s) {
        return longestPalindrome1(s);
    }

    bool dp[1000][1000];

    string longestPalindrome1(string s) {
        memset(dp, 0, sizeof(dp[0][0])*1000*1000);
        int N = s.size(), maxi = 0, maxl = 1;
        for (int l = 1; l <= N; l++) {
            for (int i = 0; i < N-l+1; i++) {
                int j = i+l-1;
                if (l == 1) dp[i][j] = true;
                else if (l == 2 && s[i] == s[j]) dp[i][j] = true;
                else if (s[i] == s[j] && dp[i+1][j-1]) dp[i][j] = true;
                if (dp[i][j] && l > maxl) maxl = l, maxi = i;
            }
        }
        return s.substr(maxi, maxl);
    }

    string longestPalindrome2(string s) {
        int maxl = 0, N = s.size();
        string res;
        for (int k = 0; k < N; k++) {
            expand(s, k, k, maxl, res);
            expand(s, k, k+1, maxl, res);
        }
        return res;
    }

    void expand(string & s, int i, int j, int & maxl, string & res) {
        int N = s.size();
        while (i >= 0 && j <= N-1 && s[i] == s[j]) i--, j++;
        i++, j--;
        int l = j-i+1;
        if (l > maxl) maxl = l, res = s.substr(i, l);
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