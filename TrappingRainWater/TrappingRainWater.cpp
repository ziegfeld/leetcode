//============================================================================
// Trapping Rain Water
// Given n non-negative integers representing an elevation map where the width
// of each bar is 1, compute how much water it is able to trap after raining.
//
// For example,
// Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
//
// Complexity:
// O(n)
//============================================================================

#include <iostream>

using namespace std;

class Solution {
public:
    int trap(int A[], int n) {
        if (n < 3) return 0;

        vector<int> ls(n, 0);
        for (int i = 1; i <= n-1; i++)
            ls[i] = max(ls[i-1], A[i-1]);

        vector<int> rs(n, 0);
        for (int i = n-2; i >= 0; i--)
            rs[i] = max(rs[i+1], A[i+1]);
        
        int res = 0;
        for (int i = 1; i < n-1; i++) {
            int h = min(ls[i], rs[i]);
            if (h > A[i]) res += (h-A[i]);
        }

        return res;
    }
};

int main() {
    Solution sol;

    {
        int p0[] = {0,1,0,2,1,0,1,3,2,1,2,1};
        int p1 = sizeof(p0)/sizeof(p0[0]);
        cout << sol.trap(p0, p1) << endl;
    }
}