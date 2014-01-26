//============================================================================
// Subsets II
// Given a collection of integers that might contain duplicates, S, return all
// possible subsets.
//
// Note:
// Elements in a subset must be in non-descending order.
// The solution set must not contain duplicate subsets.
// For example,
// If S = [1,2,2], a solution is:
//
// [
//  [2],
//  [1],
//  [1,2,2],
//  [2,2],
//  [1,2],
//  []
// ]
//
// Complexity:
// O(2^n)
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> & S) {
        return subsetsWithDup2(S);
    }

    vector<vector<int> > subsetsWithDup1(vector<int> & S) {
        sort(begin(S), end(S));
        vector<int> sub;
        vector<vector<int> > res;
        subsetsWithDupHelper1(S, 0, sub, res);
        return res;
    }

    void subsetsWithDupHelper1(vector<int> & S, int start, vector<int> & sub, vector<vector<int> > & res) {
        res.push_back(sub);
        for (int i = start; i < S.size(); i++) {
            if (i > start && S[i] == S[i - 1]) continue;
            auto copy = sub;
            copy.push_back(S[i]);
            subsetsWithDupHelper1(S, i + 1, copy, res);
        }
    }

    vector<vector<int> > subsetsWithDup2(vector<int> & S) {
        sort(begin(S), end(S));
        int count = 0;
        vector<vector<int> > res(1, vector<int>());
        for (int i = 0; i < S.size(); i++) {
            if (i > 0 && S[i] == S[i - 1]) count++;
            else count = 0;
            int N = res.size();
            for (int j = 0; j < N; j++) {
                int K = res[j].size();
                if (count == 0 || (K >= count && res[j][K - count] == S[i])) {
                    auto copy = res[j];
                    copy.push_back(S[i]);
                    res.push_back(copy);
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> p0;

    {
        p0 = { 1, 2, 2 };
        auto p1 = sol.subsetsWithDup(p0);
        for (auto it1 : p1) {
            for (auto it2 : it1) cout << it2 << " ";
            cout << endl;
        }
    }

    return 0;
}