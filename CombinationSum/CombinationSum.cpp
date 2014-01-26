//============================================================================
// Given a set of candidate numbers (C) and a target number (T),
// find all unique combinations in C where the candidate numbers sums to T.
//
// The same repeated number may be chosen from C unlimited number of times.
//
// Note:
// All numbers (including target) will be positive integers.
// Elements in a combination (a1, a2, … ,ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
// The solution set must not contain duplicate combinations.
// For example, given candidate set 2,3,6,7 and target 7,
// A solution set is:
// [7]
// [2, 2, 3]
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(begin(candidates), end(candidates));
        vector<int> sub;
        vector<vector<int> > res;
        combinationSumHelper(candidates, target, 0, sub, res);
        return res;
    }

    void combinationSumHelper(vector<int> & candidates, int target, int start, vector<int> & sub, vector<vector<int> > & res) {
        if (target < 0) return;
        if (target == 0) {
            res.push_back(sub);
            return;
        }

        for (int i = start; i < (int)candidates.size(); i++) {
            sub.push_back(candidates[i]);
            combinationSumHelper(candidates, target - candidates[i], i, sub, res);
            sub.pop_back();
        }
    }
};


int main() {
    Solution sol;
    vector<int> p0 = { 2, 3, 6, 7 };
    int p1 = 7;
    auto p2 = sol.combinationSum(p0, p1);
    for (auto it1 : p2) {
        for (auto it2 : it1) cout << it2 << " ";
        cout << endl;
    }
    return 0;
}