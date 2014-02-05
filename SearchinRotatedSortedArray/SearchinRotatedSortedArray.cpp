//============================================================================
// Search in Rotated Sorted Array
// Suppose a sorted array is rotated at some pivot unknown to you beforehand.
//
// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
//
// You are given a target value to search. If found in the array return its
// index, otherwise return -1.
//
// You may assume no duplicate exists in the array.
//
// Complexity
// O(log(n)) time
//============================================================================

#include <iostream>

using namespace std;

class Solution {
public:
    int search(int A[], int n, int target) {
        int l = 0, u = n - 1;
        while (l <= u) {
            int m = l + (u - l) / 2;
            if (A[m] == target) return m;
            if (A[l] <= A[m]) {
                if (A[l] <= target && target < A[m]) u = m - 1;
                else l = m + 1;
            }
            else {
                if (A[m] < target && target <= A[u]) l = m + 1;
                else u = m - 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;

    {
        int p0[] = {4, 5, 6, 7, 0, 1, 2};
        int p1 = sizeof(p0)/sizeof(p0[0]);
        for (int p2 = -1; p2 < 9; p2++)
            cout << p2 << "," << sol.search(p0, p1, p2) << endl;
    }

    return 0;
}