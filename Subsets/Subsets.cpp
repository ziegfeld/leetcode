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
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        return subsets1(S);
        //return subsets2(S);
    }

    vector<vector<int> > subsets1(vector<int> &S) {
        sort(begin(S), end(S));
        int N = S.size();
        int max = 1 << N;
        vector<vector<int> > res;
        for (int i = 0; i < max; i++) {
            vector<int> sub;
            int k = i;
            int j = 0;
            while (k > 0) {
                if (k & 0x01) sub.push_back(S[j]);
                k >>= 1;
                j++;
            }
            res.push_back(sub);
        }
        sort(begin(res), end(res));
        return res;
    }

    vector<vector<int> > subsets2(vector<int> &S) {
        sort(begin(S), end(S));
        vector<vector<int> > res;
        subsetsHelper(S, 0, vector<int>(), res);
        sort(begin(res), end(res));
        return res;
    }

    void subsetsHelper(vector<int> &S, int i, vector<int> sol, vector<vector<int> > & res) {
        res.push_back(sol);
        while (i < (int)S.size()) {
            vector<int> next(sol);
            next.push_back(S[i]);
            ++i;
            subsetsHelper(S, i, next, res);
        }
    }
};

int main() {
    return 0;
}