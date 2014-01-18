//============================================================================
// Given an unsorted integer array, find the first missing positive integer.
//
// For example,
// Given [1,2,0] return 3,
// and [3,4,-1,1] return 2.
//
// Your algorithm should run in O(n) time and uses constant space.
//============================================================================

#include <iostream>

using namespace std;

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        int i = 0;
        while (i < n) {
            if (0 < A[i] && A[i] <= n && i != A[i]-1 && A[i] != A[A[i]-1]) swap(A[i], A[A[i]-1]);
            else i++;
        }
        i = 0;
        while (i < n && i == A[i]-1) i++;
        return i+1;
    }
};

int main() {
    Solution sol;

    {
        int p0[] = {1, 2, 0};
        int p1 = sizeof(p0)/sizeof(p0[0]);
        cout << sol.firstMissingPositive(p0, p1) << endl;
    }
}