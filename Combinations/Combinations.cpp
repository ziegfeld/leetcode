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
// Complexity: O(N!) time
// Sol 1: combine(n, k) = combine(n-1, k-1) + combine(n-1, k)
// Sol 2: combine(n, k) = join (1 ~ n-k+1) from k to 1
// Sol 3: combine(n, k) = combine(n-1, k-1) + (n ~ k)
//============================================================================

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        return combine2(n, k);
    }

    vector<vector<int> > combine1(int n, int k) {
        vector<int> sub;
        vector<vector<int> > res;
        combineHelper1(n, k, 1, sub, res);
        return res;
    }

    void combineHelper1(int n, int k, int s, vector<int> & sub, vector<vector<int> > & res) {
        if (k == 0) {
            res.push_back(sub);
            return;
        }
        for (int i = s; i <= n - k + 1; i++) {
            sub.push_back(i);
            combineHelper1(n, k - 1, i + 1, sub, res);
            sub.pop_back();
        }
    }

    vector<vector<int> > combine2(int n, int k) {
        vector<vector<int> > res(1, vector<int>());
        for (; k > 0; k--){
            if (res.empty()) {
                for (int i = 1; i <= n - k + 1; i++) res.push_back(vector<int>(1, i));
                continue;
            }

            int N = res.size();
            for (int i = 0; i < N; i++) {
                int j = res[i].back() + 1;
                for (; j < n - k + 1; j++) {
                    vector<int> copy = res[i];
                    copy.push_back(j);
                    res.push_back(copy);
                }
                res[i].push_back(j);
            }
        }
        return res;
    }

    vector<vector<int> > combine3(int n, int k) {
        vector<int> sub;
        vector<vector<int> > res;
        combineHelper3(n, k, 1, sub, res);
        return res;
    }

    void combineHelper3(int n, int k, int s, vector<int> & sub, vector<vector<int> > & res) {
        if (k == 0) {
            res.push_back(sub);
            return;
        }
        if (s > n) return;
        sub.push_back(s);
        combineHelper3(n, k - 1, s + 1, sub, res);
        sub.pop_back();
        combineHelper3(n, k, s + 1, sub, res);
    }

    vector<vector<int> > combine4(int n, int k) {
        vector<vector<int> > res;
        if (k == 1) {
            for (int i = 1; i <= n; i++) res.push_back(vector<int>(1, i));
            return res;
        }
        for (int i = n; i >= k; i--) {
            auto last = combine4(i - 1, k - 1);
            for (auto it : last) {
                it.push_back(i);
                res.push_back(it);
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