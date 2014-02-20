//============================================================================
// Pascal's Triangle II
// Given an index k, return the kth row of the Pascal's triangle.
//
// For example, given k = 3,
// Return [1,3,3,1].
//
// Note:
// Could you optimize your algorithm to use only O(k) extra space?
//
// Complexity:
// O(n^2) time, O(n) space
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        
        res.push_back(1);
        if (rowIndex==0) return res;
        int n = rowIndex + 1;
        
        for (int r = 1; r < n; r++)
            res.push_back(0);
        for (int r = 1; r < n; r++) {
            int curMinus1 = 1;
            for (int c = 1; c <= r; c++) {
                int cur = res[c];
                res[c] = curMinus1 + cur;
                curMinus1 = cur;
            }
        }
        
        return res;
    }
};


int main() {
    return 0;
}
