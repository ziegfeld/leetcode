//============================================================================
// Given a digit string, return all possible letter combinations that the
// number could represent.
//
// Input:Digit string "23"
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
// Note:
// Although the above answer is in lexicographical order, your answer could be
// in any order you want.
//============================================================================

#include <iostream>
#include <string>
#include <vector>

using namespace std;


string keypad[] = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        return letterCombinations1(digits);
    }

    vector<string> letterCombinations1(string digits) {
        string sub;
        vector<string> res;
        letterCombinationsHelper1(digits, 0, sub, res);
        return res;
    }

    void letterCombinationsHelper1(string & digits, int start, string & sub, vector<string> & res) {
        if (start == digits.size()) {
            res.push_back(sub);
            return;
        }

        int d = digits[start] - '2';
        for (char c : keypad[d]) {
            sub.push_back(c);
            letterCombinationsHelper1(digits, start + 1, sub, res);
            sub.pop_back();
        }
    }

    vector<string> letterCombinations2(string digits) {
        vector<string> res(1, "");
        for (char c : digits) {
            int d = c - '2';
            int M = res.size();
            for (int i = 0; i < M; i++) {
                int N = keypad[d].size();
                for (int j = 0; j < N; j++) {
                    if (j == N - 1) res[i].push_back(keypad[d][j]);
                    else {
                        string copy = res[i];
                        copy.push_back(keypad[d][j]);
                        res.push_back(copy);
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    string p0;

    {
        p0 = "23";
        auto p1 = sol.letterCombinations(p0);
        for (auto it : p1) {
            cout << it << endl;
        }
    }

    return 0;
}