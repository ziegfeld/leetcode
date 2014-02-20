//============================================================================
// Sort Colors
// Given an array with n objects colored red, white or blue, sort them so that
// objects of the same color are adjacent, with the colors in the order red,
// white and blue.
//
// Here, we will use the integers 0, 1, and 2 to represent the color red,
// white, and blue respectively.
//
// Note:
// You are not suppose to use the library's sort function for this problem.
//
// Follow up:
// A rather straight forward solution is a two-pass algorithm using counting
// sort.
// First, iterate the array counting number of 0's, 1's, and 2's, then
// overwrite array with total number of 0's, then 1's and followed by 2's.
//
// Could you come up with an one-pass algorithm using only constant space?
//============================================================================

class Solution {
public:
    // void  sortColors(int A[], int n){
    
    
    // this is sortColors_2 (got rid of (i1!=-1) if statement inside while loop)
    void sortColors(int A[], int n) {
        int i = 0, i1 = -1;
        // i1 is the beginning of a continuous series of 1's
        if (n == 0) return;
        n --;
        while (n != -1 && A[n] == 2) --n;
        // n is the beginning of not 2 counting backward from the very end of A.
        
        while (i < n && i1 == -1) {
            switch(A[i]) {
                case 0:  
                    ++i;
                    break;
                
                case 1: 
                    i1 = i;
                    ++i;
                    break;
                
                default: // A[i] == 2
                    swap(A[i],A[n]);
                    --n; // NO i++ !!!
                
            }
        }
        
        // no 1's found, sorting between 0 & 2 is complete in the while above.
        if (i1 == -1) return;
        
        
        while (i!=n) {  //!= is better than < in speed
            switch(A[i]) {
                case 0:  
                    swap(A[i1++],A[i++]);
                    break;
                
                case 1: 
                    ++i;
                    break;
                
                default: // A[i] == 2
                    swap(A[i],A[n]);
                    --n; // NO i++ !!!
            }
        }
        
        if (A[i] == 0 && i1 != -1)
            swap(A[i],A[i1]);
        
    }
    
    //earlier version where (i1!=-1 is inside while loop which can be avoided, as in sortColors_2

    void sortColors_1(int A[], int n) {
        int i = 0, i1 = -1;
        // i1 is the beginning of a continuous series of 1's
        if (n == 0) return;
        n --;
        while (n != -1 && A[n] == 2) --n;
        // n is the beginning of not 2 counting backward from the very end of A.
        
        // while (i1 <= n && A[i1] == 0) ++i1;
        // if (i1 > n) return;
        while (i<n) {
            switch(A[i]) {
                case 0:  
                    if (i1 != -1) {
                        swap(A[i1],A[i]);
                        ++i1;
                    }
                    ++i;
                    break;
                
                case 1: 
                    i1 = (i1 == -1)? i : i1;
                    ++i;
                    break;
                
                default: // A[i] == 2
                    swap(A[i],A[n]);
                    --n; // NO i++ !!!
                
            }
        }
        
        if (A[i] == 0 && i1 != -1)
            swap(A[i],A[i1]);
        
    }
    void sortColors_Anson(int A[], int n) {
        int zero = -1, one = -1, two = -1;
        for (int i = 0; i < n; i++) {
            if (A[i] == 0) {
                A[++two] = 2;
                A[++one] = 1;
                A[++zero] = 0;
            }
            else if (A[i] == 1) {
                A[++two] = 2;
                A[++one] = 1;
            }
            else {
                A[++two] = 2;
            }
        }
    }
};

int main() {
    return 0;
}
