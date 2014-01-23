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
        if (*s == '\0' && *p == '\0') return true;
        if (*p == '\0') return false;
        if (*(p+1) == '*') {
            while (equals(*s, *p)) {
                if (isMatch(s, p+2)) return true;
                s++;
            }
            return isMatch(s, p+2);
        }
        return equals(*s, *p) && isMatch(s+1, p+1);
    }

    bool equals(char x, char y) {
        return ((x == y) || (y == '.' && x != '\0'));
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