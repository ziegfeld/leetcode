//============================================================================
// Given two sorted integer arrays A and B, merge B into A as one sorted array.
//
// Note:
// You may assume that A has enough space to hold additional elements from B.
// The number of elements initialized in A and B are m and n respectively.
//
// Complexity:
// O(m+n) time
//============================================================================

#include <iostream>

using namespace std;

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int cur = (m--) + (n--) - 1;
        // start from the end point of new array (index = m+n-1) and go backward. stop when j=0; or i=0 and copy all B[0-j];
        while (n!=-1 && m!=-1) 
            if (A[m]>B[n]) A[cur--] = A[m--];
            else A[cur--] = B[n--];
            
        if (m == -1 && n != -1) 
            for (m=0; m<=n; m++) A[m]=B[m];

        return;
    }
};

int main() {
    return 0;
}
