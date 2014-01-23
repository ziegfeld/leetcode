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
        return maxSubArray2(A, 0, n-1);
    }

    int maxSubArray1(int A[], int n) {
        int sum = 0, res = INT_MIN;
        for (int i = 0; i < n; i++) {
            sum += A[i];
            res = max(res, sum);
            if (sum < 0) sum = 0;
        }

        return res;
    }

    int maxSubArray2(int A[], int l, int u) {
        if (l > u) return INT_MIN;
        int m = l+(u-l)/2;
        int res = 0, sum = 0, lmax = 0, rmax = 0;
        for (int i = m-1; i >= l; i--) sum += A[i], lmax = max(lmax, sum);
        sum = 0;
        for (int i = m+1; i <= u; i++) sum += A[i], rmax = max(rmax, sum);
        res = lmax+A[m]+rmax;
        res = max(res, maxSubArray2(A, l, m-1));
        res = max(res, maxSubArray2(A, m+1, u));
        return res;
    }
};

int main() {
    return 0;
}
