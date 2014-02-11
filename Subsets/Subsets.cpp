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
    vector<vector<int> > subsets(vector<int> &S) {
        return subsets2(S);
    }

    vector<vector<int> > subsets1(vector<int> &S) {
        sort(begin(S), end(S));
        vector<int> path;
        vector<vector<int> > res;
        subsetsHelper1(S, 0, path, res);
        return res;
    }

    void subsetsHelper1(vector<int> &S, int begin, vector<int> & path, vector<vector<int> > & res) {
        res.push_back(path);
        int end = S.size();
        for (int cur = begin; cur < end; cur++) {
            path.push_back(S[cur]);
            subsetsHelper1(S, cur + 1, path, res);
            path.pop_back();
        }
    }

    vector<vector<int> > subsets2(vector<int> &S) {
        sort(begin(S), end(S));
        vector<vector<int> > res(1, vector<int>());
        int N = S.size();
        for (int i = 0; i < N; i++) {
            int M = res.size();
            for (int j = 0; j < M; j++) {
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