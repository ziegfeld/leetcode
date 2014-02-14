//============================================================================
// Given two binary strings, return their sum (also a binary string).
//
// For example,
// a = "11"
// b = "1"
// Return "100".
//
// Complexity:
// O(n) time
//============================================================================

#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int i = a.size() - 1, j = b.size() - 1, sum = 0;
        while (i >= 0 || j >= 0) {
            sum += (i == -1 ? 0 : a[i--] - '0');
            sum += (j == -1 ? 0 : b[j--] - '0');
            res.insert(res.begin(), '0' + sum % 2);
            sum /= 2;
        }
        if (sum == 1) res.insert(res.begin(), '1');
        return res;
    }
};


int main() {
    Solution sol;
    string a, b;

    {
        a = "11";
        b = "1";
        cout << sol.addBinary(a, b) << endl;
    }
}
