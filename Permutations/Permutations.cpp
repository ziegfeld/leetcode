//============================================================================
// Given a collection of numbers, return all possible permutations.
//
// For example,
// [1,2,3] have the following permutations:
// [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
//============================================================================

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        // int n = num.size();
        // if (n<=1) return 1
        // sort(num.begin(),num.end());
        // int repeat = 0;
        // for (int i = 0; i < num.size(); i++){
        vector<vector<int>> res;
        permuteHelper(num, 0, res);
        return res;
    }
    
    void permuteHelper(vector<int> & num, int begin, vector<vector<int>> & res;) {
        int end = num.size();
        if (begin == end) {
            res.push_back(num);
            return;
        }
        for (int cur = begin; cur < end; cur++) {
            swap(num[begin],num[cur]);
            permuteHelper(num, begin+1, res);
            swap(num[begin],num[cur]);
        }
        
    }
    
    //     vector<vector<int> > permute(vector<int> &num) {
    //     return permute2(num);
    // }

    // vector<vector<int> > permute1(vector<int> & num) {
    //     sort(begin(num), end(num));
    //     vector<vector<int> > res;
    //     do {
    //         res.push_back(num);
    //     } while (next_permutation(begin(num), end(num)));
    //     return res;

    // }

    // vector<vector<int> > permute2(vector<int> & num) {
    //     vector<vector<int> > res;
    //     permuteHelper2(num, 0, res);
    //     return res;
    // }

    // void permuteHelper2(vector<int> & num, int begin, vector<vector<int> > & res) {
    //     int end = num.size();
    //     if (begin == end) {
    //         res.push_back(num);
    //         return;
    //     }
    //     for (int cur = begin; cur < end; cur++) {
    //         swap(num[begin], num[cur]);
    //         permuteHelper2(num, begin + 1, res);
    //         swap(num[begin], num[cur]);
    //     }
    // }
};
int main() {
    Solution sol;
    vector<int> p0 = { 1, 2, 3 };
    auto p1 = sol.permute(p0);

    for (auto it1 : p1) {
        for (auto it2 : it1) cout << it2 << " ";
        cout << endl;
    }
    return 0;
}
