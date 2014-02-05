//============================================================================
// Search Insert Position
//
// Given a sorted array and a target value, return the index if the target is
// found. If not, return the index where it would be if it were inserted in order.
//
// You may assume no duplicates in the array.
//
// Here are few examples.
// [1,3,5,6], 5 → 2
// [1,3,5,6], 2 → 1
// [1,3,5,6], 7 → 4
// [1,3,5,6], 0 → 0
// 
// Complexity
// log(n) time
//============================================================================

#include <iostream>
using namespace std;

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int l = 0, u = n-1;
        while (l < u) {
            int m = l+(u-l)/2;
            if (A[m] < target) l = m+1;
            else u = m;
        }
        if (A[u] < target) return n;
        return u;
    }
};

int main() {
    return 0;
}
