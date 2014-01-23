//============================================================================
// Given a string, find the length of the longest substring without repeating
// characters. For example,
//
// the longest substring without repeating letters for "abcabcbb" is "abc",
// which the length is 3. For "bbbbb" the longest substring is "b", with the
// length of 1.
//
// Complexity:
// Sliding Window, O(n) time
//============================================================================

#include <iostream>
#include <cstring>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool visit[256];
        memset(visit, 0, sizeof(visit));
        int N = s.size(), res = 0;
        for (int start = 0, end = 0; end < N; end++) {
            if (visit[s[end]]) {
                while (s[start] != s[end]) visit[s[start++]] = false;
                visit[s[start++]] = false;
            }
            visit[s[end]] = true;
            int sub = end-start+1;
            res = max(res, sub);
        }
        return res;
    }
};

int main() {
    Solution sol;

    {
        cout << sol.lengthOfLongestSubstring("abcabcbb") << endl;
    }

    {
        cout << sol.lengthOfLongestSubstring("bbbbb") << endl;
    }

    return 0;
}