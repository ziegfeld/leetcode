//============================================================================
// Given a string S and a string T, find the minimum window in S which will
// contain all the characters in T in complexity O(n).
//
// For example,
// S = "ADOBECODEBANC"
// T = "ABC"
// Minimum window is "BANC".
//
// Note:
// If there is no such window in S that covers all characters in T, return the
// empty string "".
//
// If there are multiple such windows, you are guaranteed that there will
// always be only one unique minimum window in S.
//
// Complexity:
// O(n)
//============================================================================

#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    string minWindow(string S, string T) {
        int toFind[256];
        int hasFound[256];
        memset(toFind, 0, sizeof(toFind));
        memset(hasFound, 0, sizeof(hasFound));
        for (char c : T) toFind[c]++;

        int M = S.size(), N = T.size(), count = 0, mini = -1, minl = INT_MAX;
        for (int start = 0, end = 0; end < M; end++) {
            if (toFind[S[end]] == 0) continue;
            hasFound[S[end]]++;
            if (hasFound[S[end]] <= toFind[S[end]]) count++;
            if (count == N) {
                while (toFind[S[start]] == 0 || hasFound[S[start]] > toFind[S[start]]) {
                    if (hasFound[S[start]] > toFind[S[start]]) hasFound[S[start]]--;
                    start++;
                }
                int len = end-start+1;
                if (len < minl) minl = len, mini = start;
            }
        }

        return (mini==-1)?"":S.substr(mini, minl);
    }
};

int main() {
   return 0;
}
