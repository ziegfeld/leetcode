//============================================================================
// Subsets
// Given a set of distinct integers, S, return all possible subsets.
//
// Note:
// Elements in a subset must be in non-descending order.
// The solution set must not contain duplicate subsets.
// For example,
// If S = [1,2,3], a solution is:
//
// [
//  [3],
//  [1],
//  [2],
//  [1,2,3],
//  [1,3],
//  [2,3],
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
    vector<vector<int> > subsets(vector<int> & S) {
        return subsets1(S);
    }

    vector<vector<int> > subsets1(vector<int> & S) {
        sort(begin(S), end(S));
        vector<int> sub;
        vector<vector<int> > res;
        subsetsHelper1(S, 0, sub, res);
        return res;
    }

    void subsetsHelper1(vector<int> & S, int start, vector<int> & sub, vector<vector<int> > & res) {
        res.push_back(sub);
        for (int i = start; i < S.size(); i++) {
            auto copy = sub;
            copy.push_back(S[i]);
            subsetsHelper1(S, i + 1, copy, res);
        }
    }

    vector<vector<int> > subsets2(vector<int> & S) {
        sort(begin(S), end(S));
        vector<vector<int> > res(1, vector<int>());
        for (int i = 0; i < S.size(); i++) {
            int N = res.size();
            for (int j = 0; j < N; j++) {
                auto copy = res[j];
                copy.push_back(S[i]);
                res.push_back(copy);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> p0;

    {
        p0 = { 1, 2, 3 };
        auto p1 = sol.subsets(p0);
        for (auto it1 : p1) {
            for (auto it2 : it1) cout << it2 << " ";
            cout << endl;
        }
    }

    return 0;
}