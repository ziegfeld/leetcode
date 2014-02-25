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


string keypad[] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        return letterCombinations1(digits);
    }

    vector<string> letterCombinations1(string & digits) {
        string path;
        vector<string> res;
        letterCombinationsHelper1(digits, 0, path, res);
        return res;
    }

    void letterCombinationsHelper1(string & digits, int begin, string & path, vector<string> & res) {
        if (begin == digits.size()) {
            res.push_back(path);
            return;
        }
        for (char c : keypad[digits[begin] - '0']) {
            path.push_back(c);
            letterCombinationsHelper1(digits, begin + 1, path, res);
            path.pop_back();
        }
    }

    vector<string> letterCombinations2(string digits) {
        vector<string> res(1, "");
        int N = digits.size();
        for (int i = 0; i < N; i++) {
            string & key = keypad[digits[i] - '0'];
            int M = res.size();
            for (int j = 0; j < M; j++) {
                int K = key.size();
                for (int k = 0; k < K; k++) {
                    if (k == K - 1) res[j].push_back(key[k]);
                    else {
                        auto copy = res[j];
                        copy.push_back(key[k]);
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