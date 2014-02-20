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
        return searchInsert2(A, 0, n-1, target);
    }
    
    //recursive
    int searchInsert1(int A[], int left, int right, int target) {
        if (left > right) return left;
        int pivot = (right - left) / 2 + left;
        if (target == A[pivot]) return pivot;
        if (target < A[pivot]) return searchInsert1(A, left, pivot - 1, target);
        else return searchInsert1(A, pivot + 1, right, target);
    }
    
    //normal
    int searchInsert2(int A[], int left, int right, int target) {
        while (left<=right) {
            int p = (right - left) / 2 + left;
            if (target == A[p]) return p;
            if (target < A[p]) right = p - 1;
            else left = p + 1;
        }
        return left;
    }
};

int main() {
    return 0;
}
