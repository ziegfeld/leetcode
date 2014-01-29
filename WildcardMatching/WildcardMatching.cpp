//============================================================================
// Wildcard Matching
// Implement wildcard pattern matching with support for '?' and '*'.
//
// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).
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
// isMatch("aa", "*") → true
// isMatch("aa", "a*") → true
// isMatch("ab", "?*") → true
// isMatch("aab", "c*a*b") → false
//============================================================================

#include <iostream>

using namespace std;

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        return isMatch1(s, p);
    }

    bool isMatch1(const char *s, const char *p) {
        if (*p == '\0') return (*s == '\0');
        if (*p == '*') {
            p++;
            while (*s != '\0') {
                if (isMatch(s, p)) return true;
                s++;
            }
            return isMatch(s, p);
        }
        return ((*p == '?' && *s != '\0') || (*p == *s)) && isMatch(s + 1, p + 1);
    }

    bool isMatch2(const char *s, const char *p) {
        const char * ss = s, *sp = NULL;
        while (*s != '\0') {
            if ((*p == '?') || (*p == *s)) s++, p++;
            else if (*p == '*') sp = p, ss = s, p++;
            else if (sp != NULL) p = sp + 1, s = ss + 1, ss++;
            else return false;
        }
        while (*p == '*') p++;
        return (*p == '\0');
    }
};

int main() {
    Solution sol;

    cout << sol.isMatch("aa", "a") << "," << 0 << endl;
    cout << sol.isMatch("aa", "aa") << "," << 1 << endl;
    cout << sol.isMatch("aaa", "aa") << "," << 0 << endl;;
    cout << sol.isMatch("aa", "*") << "," << 1 << endl;
    cout << sol.isMatch("aa", "a*") << "," << 1 << endl;
    cout << sol.isMatch("ab", "?*") << "," << 1 << endl;
    cout << sol.isMatch("aab", "c*a*b") << "," << 0 << endl;

    return 0;
}

