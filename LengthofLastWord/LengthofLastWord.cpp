//============================================================================
// Given a string s consists of upper/lower-case alphabets and empty space
// characters ' ', return the length of last word in the string.
//
// If the last word does not exist, return 0.
//
// Note: A word is defined as a character sequence consists of non-space
// characters only.
//
// For example,
// Given s = "Hello World",
// return 5.
//
// Complexity:
// O(n)
//============================================================================

#include <cstring>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        if (s == NULL || *s == '\0') return 0;
        int N = strlen(s), i = N - 1;
        while (i >= 0 && isspace(s[i])) i--;
        int res = 0;
        while (i >= 0 && !isspace(s[i])) i--, res++;
        return res;
    }
};

int main() {
    Solution sol;
    const char *s;

    {
        s = "hello world";
        cout << sol.lengthOfLastWord(s) << endl;
    }
}
