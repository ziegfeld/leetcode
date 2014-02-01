//============================================================================
// Valid Number
// Validate if a given string is numeric.
//
// Some examples:
// "0" => true
// " 0.1 " => true
// "abc" => false
// "1 a" => false
// "2e10" => true
// Note: It is intended for the problem statement to be ambiguous. You should
// gather all requirements up front before implementing one.
//
// Complexity:
// Regular Expression: depending on language
// Finite State Machine: O(n) time, O(1) space
//============================================================================

#include <iostream>
#include <cstring>

using namespace std;

enum Type {
    Invalid,
    Space,
    Sign,
    Digit,
    Dot,
    Exp
};

// Invalid Space Sign Digit Dot Exp
int states[9][6] = {
    { -1, 0, 1, 2, 3, -1 },        // state 0: leading space
    { -1, -1, -1, 2, 3, -1 },      // state 1: first sign
    { -1, 8, -1, 2, 4, 5 },        // state 2: integer (123)
    { -1, -1, -1, 4, -1, -1 },     // state 3: first dot (.)
    { -1, 8, -1, 4, -1, 5 },       // state 4: decimal (123. or .123 or 123.123)
    { -1, -1, 6, 7, -1, -1 },      // state 5: e notation
    { -1, -1, -1, 7, -1, -1 },     // state 6: second sign
    { -1, 8, -1, 7, -1, -1 },      // state 7: exponent (123)
    { -1, 8, -1, -1, -1, -1 },     // state 8: trailing space
};

class Solution {
public:
    bool isNumber(const char *s) {
        return isNumber2(string(s));
    }

    bool isNumber1(string str) {
        return regex_match(begin(str), end(str), regex("^\\s*[+-]?(\\d+|\\d*\\.\\d+|\\d+\\.\\d*)([eE][+-]?\\d+)?\\s*$"));
    }

    bool isNumber2(string str) {
        int state = 0;
        for (char c : str) {
            auto type = Type::Invalid;
            if (c == ' ') type = Type::Space;
            else if (c >= '0' && c <= '9') type = Type::Digit;
            else if (c == '+' || c == '-') type = Type::Sign;
            else if (c == '.') type = Type::Dot;
            else if (c == 'e' || c == 'E') type = Type::Exp;
            else return false;
            state = states[state][type];
            if (state == -1) return false;
        }
        return (state == 2 || state == 4 || state == 7 || state == 8);
    }
};

int main() {
    Solution sol;
    cout << sol.isNumber("0") << "," << 1 << endl;
    cout << sol.isNumber(" 0.1 ") << "," << 1 << endl;
    cout << sol.isNumber("abc") << "," << 0 << endl;
    cout << sol.isNumber("1 a") << "," << 0 << endl;
    cout << sol.isNumber("2e10") << "," << 1 << endl;
    cout << sol.isNumber("6+1") << "," << 0 << endl;
    cout << sol.isNumber("3.") << "," << 1 << endl;
    cout << sol.isNumber(".3") << "," << 1 << endl;
    cout << sol.isNumber(".") << "," << 0 << endl;
    cout << sol.isNumber("..") << "," << 0 << endl;
    cout << sol.isNumber(". ") << "," << 0 << endl;
    cout << sol.isNumber("+.8") << "," << 1 << endl;
    return 0;
}