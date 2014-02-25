//============================================================================
// Remove Duplicates from Sorted Array II
// Follow up for "Remove Duplicates":
// What if duplicates are allowed at most twice?
//
// For example,
// Given sorted array A = [1,1,1,2,2,3],
//
// Your function should return length = 5, and A is now [1,1,2,2,3].
//
// Complexity
// O(n) time
//============================================================================

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n<3) return n;
        int i = 0, j = 1;
        bool dupli = false; // A[i] appeared twice
        do {
            if (A[j]!=A[i]) {
                A[++i]=A[j++];
                dupli = false;
            }
            else if (! dupli) {
                A[++i]=A[j++];
                dupli = true;
            } else {
                ++j;
                //dupli = false;  // duplicates might still goes on!
            }
        } while (j<n);
        return i+1;
//        for (int i = 2; i < n; i++) if (A[j - 2] != A[i]) A[j++] = A[i];
    }
};

int main() {
    return 0;
}
