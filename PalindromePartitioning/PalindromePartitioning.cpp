//============================================================================
// Palindrome Partitioning
// Given a string s, partition s such that every substring of the partition 
// is a palindrome.
//
// Return all possible palindrome partitioning of s.
//
// For example, given s = "aab",
// Return
//
//   [
//       ["aa","b"],
//       ["a","a","b"]
//   ]
//
// Complexity:
// Recursion, O(2^n) time
// DP, O(n^2) time, O(n^3) space
//============================================================================

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<string> > partition(string s) {
        return partition2(s);
    }

    vector<vector<string> > partition1(string & s) {
        vector<vector<string> > res;
        vector<string> path;
        partitionHelper1(s, 0, path, res);
        return res;
    }

    void partitionHelper1(string & s, int i, vector<string> & path, vector<vector<string> > & res) {
        int N = s.size();
        if (i == N) {
            res.push_back(path);
            return;
        }

        for (int j = i; j < N; j++) {
            if (!check(s, i, j)) continue;
            path.push_back(s.substr(i, j - i + 1));
            partitionHelper1(s, j + 1, path, res);
            path.pop_back();
        }
    }

    bool check(string & s, int i, int j) {
        while (i < j && s[i] == s[j]) i++, j--;
        return (i >= j);
    }

    vector<vector<string> > partition2(string & s) {
        int N = s.size();
        vector<vector<bool> > dp1(N, vector<bool>(N, false));
        vector<vector<vector<string> > > dp2(N, vector<vector<string> >());
        for (int i = 0; i < N; i++) {
            for (int j = 0; j <= i; j++) {
                if (s[i] == s[j] && (i - j < 2 || dp1[j + 1][i - 1])) {
                    dp1[j][i] = true;
                    if (j == 0) {
                        dp2[i].push_back(vector<string>(1, s.substr(j, i - j + 1)));
                    }
                    else {
                        for (auto p : dp2[j - 1]) {
                            p.push_back(s.substr(j, i - j + 1));
                            dp2[i].push_back(p);
                        }
                    }
                }
            }
        }
        return dp2[N - 1];
    }
};

int main() {
    Solution sol;
    string p0;

    {
        p0 = "aab";
        auto p1 = sol.partition(p0);
        for (auto it1 : p1) {
            for (auto it2 : it1) {
                cout << it2 << " ";
            }
            cout << endl;
        }
    }

    return 0;
}