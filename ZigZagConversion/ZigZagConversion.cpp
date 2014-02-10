//============================================================================
// ZigZag Conversion
// The string "PAYPALISHIRING" is written in a zigzag pattern on a given
// number of rows like this: (you may want to display this pattern in a fixed
// font for better legibility)
//
// P   A   H   N
// A P L S I I G
// Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"
// Write the code that will take a string and make this conversion given a number of rows:
//
// string convert(string text, int nRows);
// convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
//
// Complexity
// O(n) time
//============================================================================

#include <iostream>

using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows < 2) return s;
        int N = s.size(), L = 2 * (nRows - 1);
        string res;
        for (int i = 0; i < nRows; i++) {
            for (int j = i; j < N; j += L) {
                res.push_back(s[j]);
                if (i > 0 && i < nRows - 1) {
                    int k = j + L - 2 * i;
                    if (k < N) res.push_back(s[k]);
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;

    {
        cout << sol.convert("PAYPALISHIRING", 3) << endl;
    }

    return 0;
}