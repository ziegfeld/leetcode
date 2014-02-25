//============================================================================
// Given two integers n and k, return all possible combinations of k numbers
// out of 1 ... n.
//
// For example,
// If n = 4 and k = 2, a solution is:
//
//[
// [2,4],
// [3,4],
// [2,3],
// [1,2],
// [1,3],
// [1,4],
//]
//
// Complexity:
// O(N!) time
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        return combine2(n, k);
    }

    vector<vector<int> > combine1(int n, int k) {
        vector<int> path;
        vector<vector<int> > res;
        combineHelper(n, k, 1, path, res);
        return res;
    }

    void combineHelper(int n, int k, int begin, vector<int> & path, vector<vector<int> > & res) {
        if (k == 0) {
            res.push_back(path);
            return;
        }
        int end = n - k + 1;
        for (int cur = begin; cur <= end; cur++) {
            path.push_back(cur);
            combineHelper(n, k - 1, cur + 1, path, res);
            path.pop_back();
        }
    }

    vector<vector<int> > combine2(int n, int k) {
        vector<vector<int> > res(1, vector<int>());
        for (; k > 0; k--) {
            int M = res.size();
            for (int i = 0; i < M; i++) {
                int begin = (res[i].empty() ? 0 : res[i].back()) + 1, end = n - k + 1;
                for (int cur = begin; cur <= end; cur++) {
                    if (cur == end) res[i].push_back(end);
                    else {
                        auto copy = res[i];
                        copy.push_back(cur);
                        res.push_back(copy);
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    int p0 = 4;
    int p1 = 2;
    auto p2 = sol.combine(p0, p1);

    for (auto it1 : p2) {
        for (auto it2 : it1) cout << it2 << " ";
        cout << endl;
    }
    return 0;
}