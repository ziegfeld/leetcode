//============================================================================
// Given an array S of n integers, find three integers in S such that the sum
// is closest to a given number, target. Return the sum of the three integers.
// You may assume that each input would have exactly one solution.
//
// For example, given array S = {-1 2 1 -4}, and target = 1.
//
// The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
//
// Complexity: O(n^2) time, O(1) space
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int N = num.size();
        sort(begin(num), end(num));
        int res = num[0] + num[1] + num[2];
        for (int k = 0; k < N - 2; k++) {
            int i = k + 1, j = N - 1;
            while (i < j) {
                int sum = num[k] + num[i] + num[j];
                if (abs(sum - target) < abs(res - target)) res = sum;
                if (sum < target) i++;
                else if (sum > target) j--;
                else return sum;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> p0;
    int p1, p2;

    {
        p0 = { -1, 2, 1, -4 };
        p1 = 1;
        p2 = sol.threeSumClosest(p0, p1);
        cout << p2 << endl;
    }

    {
        p0 = { -3, -2, -5, 3, -4 };
        p1 = -1;
        p2 = sol.threeSumClosest(p0, p1);
        cout << p2 << endl;
    }

    return 0;
}