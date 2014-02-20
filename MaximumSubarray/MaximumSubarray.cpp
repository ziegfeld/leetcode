//============================================================================
// Find the contiguous subarray within an array (containing at least one
// number) which has the largest sum.
//
// For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
// the contiguous subarray [4,1,2,1] has the largest sum = 6.
//
// Complexity:
// Greedy O(n) time
// Divide and Conquer O(nlog(n)) time
//============================================================================

#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int maxSubArray(int A[], int n) {
        int res = A[0];
        int cur = 0;
        for (int i = 0; i < n ; i ++) {
            cur += A[i];
            res = (res > cur) ? res : cur;
            if (cur < 0) cur = 0;
        }
        return res;
        
    }
};

int main() {
    Solution sol;

    {
        int p0[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
        int p1 = sol.maxSubArray(p0, sizeof(p0) / sizeof(int));
        cout << p1 << endl;
    }

    {
        int p0[] = { -2, -1 };
        int p1 = sol.maxSubArray(p0, sizeof(p0) / sizeof(int));
        cout << p1 << endl;
    }

    return 0;
}
