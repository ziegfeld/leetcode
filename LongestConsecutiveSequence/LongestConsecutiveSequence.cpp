//============================================================================
// Longest Consecutive Sequence
// Given an unsorted array of integers, find the length of the longest 
// consecutive elements sequence.
//
// For example,
// Given [100, 4, 200, 1, 3, 2],
// The longest consecutive elements sequence is [1, 2, 3, 4]. Return its 
// length: 4.
//
// Your algorithm should run in O(n) complexity.
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int N = numbers.size();
        if (N < 2) return vector<int>();
        vector<int> indexs;
        for (int i = 0; i < N; i++) indexs.push_back(i);
        sort(begin(indexs), end(indexs),
            [&numbers](const int x, const int y) { return numbers[i] < numbers[j]; });
        int i = 0, j = N - 1;
        while (i < j) {
            int sum = numbers[indexs[i]] + numbers[indexs[j]]
                if (sum == target) return vector<int>(min(indexs[i], indexs[j]), max(indexs[i], indexs[j]));
                if (sum < target) i++;
                else j--;
        }
        return vector<int>();
    }
};



int main() {
    vector<int> p0;

    Solution sol;
    {
        int a[] = { 100, 4, 200, 1, 3, 2 };
        p0.assign(begin(a), end(a));
        cout << sol.longestConsecutive(p0) << endl;
    }
    return 0;
}