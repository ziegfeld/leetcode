//============================================================================
// Given an array of integers, every element appears three times except for 
// one. Find that single one.
//
// Note:
// Your algorithm should have a linear runtime complexity. Could you implement 
// it without using extra memory?
//============================================================================

#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        int res = 0;
        for (int i = 0; i < (int)sizeof(int)*CHAR_BIT; i++) {
            int sum = 0;
            int mask = (1 << i);
            for (int j = 0; j < n; j++) {
                if (A[j] & mask)
                    sum++;
            }
            if (sum % 3)
                res |= mask;
        }
        return res;
    }
};

int main() {
    return 0;
}
