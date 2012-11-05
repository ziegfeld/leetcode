//============================================================================
// Pascal's Triangle II
// Given an index k, return the kth row of the Pascal's triangle.
//
// For example, given k = 3,
// Return [1,3,3,1].
//
// Note:
// Could you optimize your algorithm to use only O(k) extra space?
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> res;
        res.push_back(1);
        while (rowIndex > 0)
        {
            vector<int> row;
            row.push_back(1);
            for (size_t i = 0; i < res.size()-1; i++)
                row.push_back(res[i] + res[i+1]);
            row.push_back(1);
            res.clear();
            res.assign(row.begin(), row.end());
            rowIndex--;
        }
        return res;
    }
};

int main()
{
    return 0;
}
