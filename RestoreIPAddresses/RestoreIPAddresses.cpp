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

    void restoreIpAddressesHelper(string & s, int begin, int step, string & path, vector<string> & res) {
        if (begin == s.size() || step == 4) {
            if (begin == s.size() && step == 4) res.push_back(path);
            return;
        }
        string copy = path;
        if (begin != 0) copy.push_back('.');
        int num = 0;
        for (; begin < s.size(); begin++) {
            num = num * 10 + s[begin] - '0';
            copy.push_back(s[begin]);
            if (num > 255) break;
            restoreIpAddressesHelper(s, begin + 1, step + 1, copy, res);
            if (num == 0) break;
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