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
        int res = 0, mask = 1;
        for (int i = 0; i < 32; i++) {
            int sum = 0;
            for (int j = 0; j < n; j ++)
                sum += (A[j] & mask) ? 1 : 0;
            if (sum%3) res |= mask;
            
            mask = mask << 1;
        }
        return res;
    }
};

int main() {
    return 0;
}
