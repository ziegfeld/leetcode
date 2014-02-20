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
        return search1(A,n,target);
    }
    
    int search1(int A[], int n, int target) {
        if (n==0) return -1;
        int p = 0;
        // find pivot
        if (A[0]<A[n-1]) {
            // its just simple sorted array!
            return binSearch(A,0,n-1,target);
        }
        int i = 0, j = n - 1;
        while (i<j) {
            p = (i + j) / 2;
            if (A[i]<A[p])
                i = p;
            else
                j = p;
        }
        //++ p;
        //p must be less than n, p=n means A[0]<A[n-1], which is dealt with alrdy.
        if (A[0]<=target && (p==0 || A[p]>=target)) {
            return binSearch(A,0,p,target);
        } else if (target<=A[n-1] && (p == n-1 || A[p+1]<=target )) {
            return binSearch(A,p+1,n-1,target);
        }
        return -1;
    }
    
    int binSearch(int A[], int l, int u, int target) {
        if (l>u) return -1;
        int res = -1;
        while (l<=u) {
            int m = (l + u) / 2;
            if (A[m] == target) 
                return m;
            if (A[m]>target)
                u = m - 1;
            else
                l = m + 1;
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
