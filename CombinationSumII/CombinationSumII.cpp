//============================================================================
// Given a collection of candidate numbers (C) and a target number (T),
// find all unique combinations in C where the candidate numbers sums to T.
//
// Each number in C may only be used once in the combination.
//
// Note:
// All numbers (including target) will be positive integers.
// Elements in a combination (a1, a2, … ,ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
// The solution set must not contain duplicate combinations.
// For example, given candidate set 10,1,2,7,6,1,5 and target 8,
// A solution set is:
// [1, 7]
// [1, 2, 5]
// [2, 6]
// [1, 1, 6]
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        sort(begin(candidates), end(candidates));
        vector<vector<int> > res;
        vector<int> path;
        combinationSumHelper(candidates, target, 0, path, res);
        return res;
    }

    void combinationSumHelper(vector<int> &candidates, int target, int start, vector<int> & path, vector<vector<int> > & res) {
        if (target < 0) return;
        if (target == 0) {
            res.push_back(path);
            return;
        }

        for (int index = start; index < candidates.size(); index++) {
            if (index > start && candidates[index] == candidates[index - 1]) continue;
            path.push_back(candidates[index]);
            combinationSumHelper(candidates, target - candidates[index], index + 1, path, res);
            path.pop_back();
        }
    }
};

int main() {
    Solution sol;
    vector<int> p0;
    int p1;
    vector<vector<int> > p2;

    {
        p0 = { 10, 1, 2, 7, 6, 1, 5 };
        p1 = 8;
        p2 = sol.combinationSum2(p0, p1);
        for (auto it1 : p2) {
            for (auto it2 : it1) cout << it2 << " ";
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}