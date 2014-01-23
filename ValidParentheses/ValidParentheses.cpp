//============================================================================
// Valid Parentheses
// Given a string containing just the characters '(', ')', '{', '}', '[' and
// ']', determine if the input string is valid.
//
// The brackets must close in the correct order, "()" and "()[]{}" are all
// valid but "(]" and "([)]" are not.
//============================================================================

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') stk.push(c);
            else {
                if (stk.empty()) return false;
                else if (c == ')' && stk.top() == 'c') stk.pop();
                else if (c == ']' && stk.top() == '[') stk.pop();
                else if (c == '{' && stk.top() == '}') stk.pop();
                else return false;
            }
        }
        return (stk.empty());
    }
};


int main() {
    return 0;
}
