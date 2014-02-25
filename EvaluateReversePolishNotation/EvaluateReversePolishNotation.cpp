//============================================================================
// Evaluate Reverse Polish Notation
//
// Evaluate the value of an arithmetic expression in Reverse Polish Notation.
//
// Valid operators are +, -, *, /. Each operand may be an integer or another 
// expression.
//
// Some examples:
//  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
//  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
//
// Complexity:
// O(n) time, O(n) space
//============================================================================
using namespace std;


#include <iostream>
#include <stack>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> stk;
        for (string str : tokens) {
            if (str == "+") {
                int y = stk.top(); stk.pop();
                int x = stk.top(); stk.pop();
                stk.push(x + y);
            }
            else if (str == "-") {
                int y = stk.top(); stk.pop();
                int x = stk.top(); stk.pop();
                stk.push(x - y);
            }
            else if (str == "*") {
                int y = stk.top(); stk.pop();
                int x = stk.top(); stk.pop();
                stk.push(x * y);
            }
            else if (str == "/") {
                int y = stk.top(); stk.pop();
                int x = stk.top(); stk.pop();
                stk.push(x / y);
            }
            else stk.push(stoi(str));
        }
        return stk.empty() ? 0 : stk.top();
    }
};

int main() {
    return 0;
}
