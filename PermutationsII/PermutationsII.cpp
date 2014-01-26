//============================================================================
// Permutations II
// Given a collection of numbers that might contain duplicates, return all
// possible unique permutations.
//
// For example,
// [1,1,2] have the following unique permutations:
// [1,1,2], [1,2,1], and [2,1,1].
//============================================================================

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        return permuteUnique2(num);
    }

    vector<vector<int> > permuteUnique1(vector<int> & num) {
        sort(begin(num), end(num));
        vector<vector<int> > res;
        do {
            res.push_back(num);
        } while (next_permutation(begin(num), end(num)));
        return res;

    }

    vector<vector<int> > permuteUnique2(vector<int> & num) {
        vector<vector<int> > res;
        sort(begin(num), end(num));
        permuteUnique1Helper2(num, 0, res);
        return res;
    }

    void permuteUnique1Helper2(vector<int> & num, int i, vector<vector<int> > & res) {
        if (i == (int)num.size()) {
            res.push_back(num);
            return;
        }
        unordered_set<int> visit;
        for (int j = i; j < (int)num.size(); j++) {
            if (visit.count(num[j])) continue;
            visit.insert(num[j]);
            swap(num[i], num[j]);
            permuteUnique1Helper2(num, i + 1, res);
            swap(num[i], num[j]);
        }
    }
};

int main() {
    Solution sol;

    {
        vector<int> p0 = { 1, 1, 2 };
        auto p1 = sol.permuteUnique(p0);

        for (auto it1 : p1) {
            for (auto it2 : it1) cout << it2 << " ";
            cout << endl;
        }
        cout << p1.size() << endl;
    }

    return 0;
}