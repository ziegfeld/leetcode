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
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        return subsetsWithDup2(S);
    }

    vector<vector<int> > subsetsWithDup1(vector<int> &S) {
        sort(begin(S), end(S));
        vector<int> path;
        vector<vector<int> > res;
        subsetsWithDupHelper1(S, 0, path, res);
        return res;
    }

    void subsetsWithDupHelper1(vector<int> &S, int begin, vector<int> & path, vector<vector<int> > & res) {
        res.push_back(path);
        int end = S.size();
        for (int cur = begin; cur < end; cur++) {
            if (cur > begin && S[cur - 1] == S[cur]) continue;
            path.push_back(S[cur]);
            subsetsWithDupHelper1(S, cur + 1, path, res);
            path.pop_back();
        }
    }

    vector<vector<int> > subsetsWithDup2(vector<int> &S) {
        sort(begin(S), end(S));
        vector<vector<int> > res(1, vector<int>());
        int cnt = 0;
        for (int i = 0; i < S.size(); i++) {
            if (i > 0 && S[i - 1] == S[i]) cnt++;
            else cnt = 0;
            int M = res.size();
            for (int j = 0; j < M; j++) {
                int N = res[j].size();
                if (cnt == 0 || (N >= cnt && res[j][N - cnt] == S[i])) {
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