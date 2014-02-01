//============================================================================
// Restore IP Addresses
// Given a string containing only digits, restore it by returning all possible
// valid IP address combinations.
//
// For example:
// Given "25525511135",
//
// return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
//============================================================================

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string path;
        restoreIpAddressesHelper(s, 0, 0, path, res);
        return res;
    }

    void restoreIpAddressesHelper(string & s, int i, int k, string path, vector<string> & res) {
        if (i == s.size() || k == 4) {
            if (i == s.size() && k == 4) res.push_back(path);
            return;
        }
        if (k != 0) path.push_back('.');
        int x = 0;
        for (int j = i; j < s.size(); j++) {
            x = x * 10 + s[j] - '0';
            if (x > 255) break;
            path.push_back(s[j]);
            restoreIpAddressesHelper(s, j + 1, k + 1, path, res);
            if (x == 0) break;
        }
    }
};

int main() {
    Solution sol;
    string p0;
    vector<string> p1;

    {
        p0 = "25525511135";
        auto p1 = sol.restoreIpAddresses(p0);
        for (auto it : p1) cout << it << endl;
    }

    {
        p0 = "010010";
        auto p1 = sol.restoreIpAddresses(p0);
        for (auto it : p1) cout << it << endl;
    }

    return 0;
}