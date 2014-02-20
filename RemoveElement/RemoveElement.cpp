//============================================================================
// Remove Element
// Given an array and a value, remove all instances of that value in place
// and return the new length.
//
// The order of elements can be changed. It doesn't matter what you leave
// beyond the new length.
//
// Complexity
// O(n) time
//============================================================================

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int newLength = n;
        int i = 0;
        while (i<newLength && newLength) {
            if (A[i]==elem)
                A[i]=A[--newLength];
            else
                i++;
        }
        return newLength;
    }
};

int main() {
    return 0;
}
