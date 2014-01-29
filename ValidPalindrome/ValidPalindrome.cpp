//============================================================================
// Given a string, determine if it is a palindrome, considering only 
// alphanumeric characters and ignoring cases.
//
// For example,
//
// "A man, a plan, a canal: Panama" is a palindrome.
// "race a car" is not a palindrome.
//
// Complexity:
// O(n) time, O(1) space
//============================================================================

#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        return isPalindrome2(s);
    }

    bool isPalindrome1(string & s) {
        string str;
        for (char c : s) {
            if (isalnum(c)) {
                if (isupper(c)) str.push_back(tolower(c));
                else str.push_back(c);
            }
        }
        int start = 0, end = str.size() - 1;
        while (start < end) {
            if (str[start] != str[end]) return false;
            start++, end--;
        }
        return true;
    }

    bool isPalindrome2(string & s) {
        int start = 0, end = s.size() - 1;
        while (start < end) {
            while (start < end && !isalnum(s[start])) start++;
            while (start < end && !isalnum(s[end])) end--;
            if (tolower(s[start]) != tolower(s[end])) return false;
            start++, end--;
        }
        return true;
    }
};

int main() {

    Solution sol;

    {
        cout << sol.isPalindrome("A man, a plan, a canal: Panama") << endl;
        cout << sol.isPalindrome("race a car") << endl;
    }

    return 0;
}
