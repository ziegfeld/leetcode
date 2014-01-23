//============================================================================
// Given n pairs of parentheses, write a function to generate all combinations
// of well-formed parentheses.
//
// For example, given n = 3, a solution set is:
//
// "((()))", "(()())", "(())()", "()(())", "()()()"
//
// Complexity:
// O(n!)
//============================================================================

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string sub;
        vector<string> res;
        generateParenthesis(n, n, sub, res);
        return res;
    }

    void generateParenthesis(int l, int r, string & sub, vector<string> & res) {
        if (l == 0 && r == 0) {
            res.push_back(sub);
            return;
        }
        if (l > 0) {
            sub.push_back('(');
            generateParenthesis(l-1, r, sub, res);
            sub.pop_back();
        }
        if (r > l) {
            sub.push_back(')');
            generateParenthesis(l, r-1, sub, res);
            sub.pop_back();
        }
    }
};

int main() {
    Solution sol;
    auto res = sol.generateParenthesis(3);
    for (auto it1 : res) {
        for (auto it2 : it1) cout << it2 << " ";
        cout << endl;
    }
    return 0;
}