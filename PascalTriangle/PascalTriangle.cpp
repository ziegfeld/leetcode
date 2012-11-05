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
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int> > generate(int numRows)
    {
        vector<vector<int> > res;
        if (numRows < 1) return res;
        res.push_back(vector<int>(1, 1));
        while (numRows > 1)
        {
            size_t m = res.size();
            size_t n = res[m-1].size();
            vector<int> row;
            row.push_back(1);
            for (size_t i = 0; i < n-1; i++)
                row.push_back(res[m-1][i] + res[m-1][i+1]);
            row.push_back(1);
            res.push_back(row);
            numRows--;
        }
        return res;
    }
};

int main()
{
    return 0;
}
