//============================================================================
// There are two sorted arrays A and B of size m and n respectively. Find the
// median of the two sorted arrays. The overall run time complexity should be
// O(log (m+n)).
//============================================================================

#include <iostream>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if (m == 0 && n == 0) return 0.0;
        return findMedianSortedArrays2(A, m, B, n);
    }

    double findMedianSortedArrays1(int A[], int m, int B[], int n) {
        int i = 0, j = 0, m1 = -1, m2 = -1;
        for (int k = 0; k <= (m+n)/2; k++) {
            m1 = m2;
            if (j == n || (i < m && A[i] < B[j])) m2 = A[i++];
            else m2 = B[j++];
        }

        if ((m+n)%2) return (double)m2;
        return (m1+m2)/2.0;
    }

    double findMedianSortedArrays2(int A[], int m, int B[], int n) {
        if ((m+n)%2) return (double)findKth(A, m, B, n, (m+n)/2+1);
        return (findKth(A, m, B, n, (m+n)/2)+findKth(A, m, B, n, (m+n)/2+1))/2.0;
    }

    int findKth(int A[], int m, int B[], int n, int k) {
        if (m > n) return findKth(B, n, A, m, k);
        if (m == 0) return B[k-1];
        if (k == 1) return min(A[0], B[0]);

        int p1 = min(k/2, m), p2 = k-p1;
        if (A[p1-1] < B[p2-1]) return findKth(A+p1, m-p1, B, n, k-p1);
        if (A[p1-1] > B[p2-1]) return findKth(A, m, B+p2, n-p2, k-p2);
        return A[p1-1];
    }
};

int main() {
    Solution sol;

    {
        int p0[] = {1, 12, 15, 26, 38};
        int p1 = sizeof(p0)/sizeof(p0[0]);
        int p2[] = {2, 13, 17, 30, 45};
        int p3 = sizeof(p2)/sizeof(p2[0]);
        cout << sol.findMedianSortedArrays(p0, p1, p2, p3) << endl;
    }

    return 0;
}