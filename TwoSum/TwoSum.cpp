//============================================================================
// Given an array of integers, find two numbers such that they add up to a
// specific target number.
//
// The function twoSum should return indices of the two numbers such that they
// add up to the target,
// where index1 must be less than index2.
// Please note that your returned answers (both index1 and index2) are not
// zero-based.
//
// You may assume that each input would have exactly one solution.
//
// Input: numbers={2, 7, 11, 15}, target=9
// Output: index1=1, index2=2
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // takes O(nlog(n)) time, O(n) space
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> res;
        int N = numbers.size();
        if (N < 2) return res;

        vector<int> indexs;
        for (int i = 0; i < N; i++) indexs.push_back(i);
        sort(begin(indexs), end(indexs), 
            [&numbers] (const int i, const int j) { return numbers[i] < numbers[j]; });

        int i = 0, j = N-1;
        while (i < j) {
            int sum = numbers[indexs[i]]+numbers[indexs[j]];
            if (sum < target) i++;
            else if (sum > target) j--;
            else break;
        }

        if (indexs[i] > indexs[j]) swap(indexs[i], indexs[j]);
        res.push_back(indexs[i]+1);
        res.push_back(indexs[j]+1);
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> p0;
    int p1;
    vector<int> p2;

    {
        int a[] = {2, 7, 11, 15};
        p0.assign(begin(a), end(a));
        p1 = 9;
        p2 = sol.twoSum(p0, p1);
        for (auto it : p2) cout << it << " ";
        cout << endl;
    }

    return 0;
}
