//============================================================================
// Pascal's Triangle
// Given numRows, generate the first numRows of Pascal's triangle.
//
// For example, given numRows = 5,
// Return
//
// [
//      [1],
//     [1,1],
//    [1,2,1],
//   [1,3,3,1],
//  [1,4,6,4,1]
// ]
//
// Complexity:
// O(n^2)
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > res;
        for (int r = 0; r < numRows; r++) res.push_back(vector<int>(r+1, 1));
        for (int r = 2; r < numRows; r++)
            for (int c = 1; c < r; c++)
                res[r][c] = res[r-1][c-1]+res[r-1][c];

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> p0;
    vector<vector<int> > p1;

    {
        p1 = sol.generate(5);
        for (auto it1 : p1) {
            for (auto it2 : it1) cout << it2 << " ";
            cout << endl;
        }
    }

    return 0;
}