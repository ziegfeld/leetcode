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
        return addBinary1(a, b);
    }

    string addBinary1(string & a, string & b) {
        reverse(begin(a), end(a));
        reverse(begin(b), end(b));
        if (a.size() < b.size()) swap(a, b);
        int na = a.size(), nb = b.size();
        int c = 0;
        string res(na, '0');
        for (int i = 0; i < na; i++) {
            int s = a[i] - '0';
            s += (i < nb) ? b[i] - '0' : 0;
            s += c;
            res[i] = '0' + s % 2;
            c = s / 2;
        }
        if (c == 1) res.push_back('1');
        reverse(begin(res), end(res));
        return res;
    }

    string addBinary2(string & a, string & b) {
        if (a.size() < b.size()) swap(a, b);
        int na = a.size(), nb = b.size();
        int c = 0;
        string res(na, '0');
        for (int i = na - 1; i >= 0; i--) {
            int j = nb - na + i;
            int s = a[i] - '0';
            s += (j >= 0) ? b[j] - '0' : 0;
            s += c;
            res[i] = '0' + s % 2;
            c = s / 2;
        }
        if (c == 1) res.insert(res.begin(), '1');
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
