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
        vector<int> res(rowIndex+1, 1);
        for (int r = 2; r <= rowIndex; r++)
            for (int c = r-1; c > 0; c--)
                res[c] += res[c-1];
        return res;
    }
};

int main() {
    return 0;
}
