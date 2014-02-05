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
        return findMedianSortedArrays2(A, m, B, n);
    }

    double findMedianSortedArrays1(int A[], int m, int B[], int n) {
        int r1 = -1, r2 = -1, i = 0, j = 0;
        for (int k = (m + n) / 2; k >= 0; k--) {
            r1 = r2;
            if (j == n || (i < m && A[i] <= B[j])) r2 = A[i++];
            else r2 = B[j++];
        }
        if ((m + n) % 2) return (double)r2;
        return (r1 + r2) / 2.0;
    }

    double findMedianSortedArrays2(int A[], int m, int B[], int n) {
        int k = (m + n) / 2;
        if ((m + n) % 2) return findKth(A, m, B, n, k + 1);
        return (findKth(A, m, B, n, k) + findKth(A, m, B, n, k + 1)) / 2.0;
    }

    int findKth(int A[], int m, int B[], int n, int k) {
        if (n == 0) return A[k - 1];
        if (m == 0) return B[k - 1];
        if (k == 1) return min(A[0], B[0]);
        if (m / 2 + n / 2 + 1 >= k) {
            if (A[m / 2] <= B[n / 2]) return findKth(A, m, B, n / 2, k);
            else return findKth(A, m / 2, B, n, k);
        }
        else {
            if (A[m / 2] <= B[n / 2]) findKth(A + m / 2 + 1, m - (m / 2 + 1), B, n, k - (m / 2 + 1));
            else return findKth(A, m, B + n / 2 + 1, n - (n / 2 + 1), k - (n / 2 + 1));
        }
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