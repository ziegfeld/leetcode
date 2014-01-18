//============================================================================
// Search in Rotated Sorted Array II
//
// Follow up for "Search in Rotated Sorted Array":
// What if duplicates are allowed?
//
// Would this affect the run-time complexity? How and why?
//
// Write a function to determine if a given target is in the array.
//
// Complexity:
// Worse case O(n) time
//============================================================================

#include <iostream>
using namespace std;

class Solution {
public:
    bool search(int A[], int n, int target) {
        int l = 0, u = n-1;
        while (l <= u) {
            int m = l+(u-l)/2;
            if (A[m] == target) return true;
            if (A[l] < A[m]) {
                if (A[l] <= target && target < A[m]) u = m-1;
                else l = m+1;
            }
            else if (A[l] > A[m]){
                if (A[m] < target && target <= A[u]) l = m+1;
                else u = m-1;
            }
            else l++;
        }
        return false;
    }
};

int main() {
    Solution sol;

    {
        int p0[] = {1, 1, 5, 1, 1, 1, 1};
        int p1 = sizeof(p0)/sizeof(p0[0]);
        int p2 = 5;
        cout << p2 << "," << sol.search(p0, p1, p2) << endl;
    }

    return 0;
}