//============================================================================
// Given an array of strings, return all groups of strings that are anagrams.
//
// Note: All inputs will be in lower-case.
//
// Complexity:
// O(k*n) time, O(k*n) space, k is the average length of string
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        unordered_map<string, vector<string> > table;
        for (string s : strs) table[hash(s)].push_back(s);
        vector<string> res;
        for (auto it : table) if (it.second.size() > 1) res.insert(end(res), begin(it.second), end(it.second));
        return res;
    }

    string hash(string & s) {
        vector<int> counts(26, 0);
        for (char c : s) counts[c - 'a']++;
        string res;
        for (int i = 0; i < 26; i++) res += string(counts[i], 'a' + i);
        return res;
    }
};

int main() {
    Solution sol;
    vector<string> p0;

    {
        p0 = { "tea", "and", "ace", "ad", "eat", "dan" };
        auto p1 = sol.anagrams(p0);
        for (auto it : p1) {
            cout << it << endl;
        }
    }

    return 0;
}