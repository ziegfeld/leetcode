//============================================================================
// Regular Expression Matching
// Implement regular expression matching with support for '.' and '*'.
//
// '.' Matches any single character.
// '*' Matches zero or more of the preceding element.
//
// The matching should cover the entire input string (not partial).
//
// The function prototype should be:
// bool isMatch(const char *s, const char *p)
//
// Some examples:
// isMatch("aa","a") → false
// isMatch("aa","aa") → true
// isMatch("aaa","aa") → false
// isMatch("aa", "a*") → true
// isMatch("aa", ".*") → true
// isMatch("ab", ".*") → true
// isMatch("aab", "c*a*b") → true
//============================================================================

#include <iostream>

using namespace std;

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if (*p == '\0') return (*s == '\0');
        if (*(p + 1) == '*') {
            while ((*p == *s) || (*p == '.' && *s != '\0')) {
                if (isMatch(s, p + 2)) return true;
                s++;
            }
            return isMatch(s, p + 2);
        }
        return ((*p == *s) || (*p == '.' && *s != '\0')) && isMatch(s + 1, p + 1);
    }
};

int main() {
    Solution sol;
    cout << sol.isMatch("aa","a") << endl;
    cout << sol.isMatch("aa","aa") << endl;
    cout << sol.isMatch("aaa","aa") << endl;
    cout << sol.isMatch("aa", "a*") << endl;
    cout << sol.isMatch("aa", ".*") << endl;
    cout << sol.isMatch("ab", ".*") << endl;
    cout << sol.isMatch("aab", "c*a*b")  << endl;
    return 0;
}