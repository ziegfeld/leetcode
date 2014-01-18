//============================================================================
// 4Sum
// Given an array S of n integers, are there elements a, b, c, and d in S such
// that a + b + c + d = target?
// Find all unique quadruplets in the array which gives the sum of target.
// Note:
// Elements in a quadruplet (a,b,c,d) must be in non-descending order.
// (ie, a ≤ b ≤ c ≤ d)
// The solution set must not contain duplicate quadruplets.
// For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
// A solution set is:
// (-1,  0, 0, 1)
// (-2, -1, 1, 2)
// (-2,  0, 0, 2)
//
// Complexity: O(n^3) time
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > res;
        int N = num.size();
        if (N < 4) return res;
        sort(begin(num), end(num));
        for (int i = 0; i < N-3; i++) {
            if (i > 0 && num[i-1] == num[i]) continue;
            for (int j = i+1; j < N-2; j++) {
                if (j > i+1 && num[j-1] == num[j]) continue;
                int l = j+1;
                int r = N-1;
                while (l < r) {
                    int sum = num[i]+num[j]+num[l]+num[r];
                    if (sum < target) l++;
                    else if (sum > target) r--;
                    else {
                        vector<int> sub;
                        sub.push_back(num[i]);
                        sub.push_back(num[j]);
                        sub.push_back(num[l]);
                        sub.push_back(num[r]);
                        res.push_back(sub);
                        do { l++; } while (l < r && num[l-1] == num[l]);
                        do { r--; } while (l < r && num[r] == num[r+1]);
                    }
                }
            }
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> p0;
    int p1;
    vector<vector<int> > p2;

    {
        int a[] = {1, 0, -1, 0, -2, 2};
        p0.assign(begin(a), end(a));
        p1 = 0;
        p2 = sol.fourSum(p0, p1);
        for (auto it1 : p2) {
            for (auto it2 : it1) cout << it2 << " ";
            cout << endl;
        }
    }

    return 0;
}
