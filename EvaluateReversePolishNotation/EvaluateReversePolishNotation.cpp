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
//============================================================================
using namespace std;


#include <iostream>
#include <stack>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> tokens) {
        stack<int> stk;
        for (size_t i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int op2 = stk.top();
                stk.pop();
                int op1 = stk.top();
                stk.pop();
                if (tokens[i] == "+") 
                    stk.push(op1 + op2); 
                else if (tokens[i] == "-")
                    stk.push(op1 - op2);
                else if (tokens[i] == "*")
                    stk.push(op1 * op2);
                else if (tokens[i] == "/")
                    stk.push(op1 / op2);
            }
            else {
                istringstream stream(tokens[i]);
                int num;
                stream >> num;
                stk.push(num);
            }
        }
        return stk.top();
    }
};

int main() {
    return 0;
}
