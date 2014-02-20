//============================================================================
// Remove Duplicates from Sorted Array
// Given a sorted array, remove the duplicates in place such that each element
// appear only once and return the new length.
//
// Do not allocate extra space for another array, you must do this in place
// with constant memory.
//
// For example,
// Given input array A = [1,1,2],
//
// Your function should return length = 2, and A is now [1,2].
//
// Complexity
// O(n) time
//============================================================================

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n<2) return n;
        int i = 0, j = 1;
        do {
            if (A[j]!=A[i]) A[++i]=A[j];
        } while (++j<n);
        return i+1;
    }
};

int main() {
    return 0;
}
