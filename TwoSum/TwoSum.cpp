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
// 
// Complexity:
// Sort and Scan, O(nlog(n)) time, O(n) space
// Hash table, O(n) time, O(n) space
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        return twoSum2(numbers, target);
    }

    vector<int> twoSum1(vector<int> &numbers, int target) {
        int N = numbers.size();
        vector<int> vs;
        for (int i = 0; i < N; i++) vs.push_back(i);
        sort(begin(vs), end(vs),
            [&numbers](const int i, const int j) { return numbers[i] < numbers[j]; });
        vector<int> res(2, -1);
        int i = 0, j = N - 1;
        while (i < j) {
            int sum = numbers[vs[i]] + numbers[vs[j]];
            if (sum < target) i++;
            else if (sum > target) j--;
            else {
                res[0] = vs[i] + 1;
                res[1] = vs[j] + 1;
                if (res[0] > res[1]) swap(res[0], res[1]);
                break;
            }

        }
        return res;
    }

    vector<int> twoSum2(vector<int> &numbers, int target) {
        int N = numbers.size();
        unordered_map<int, int> table;
        for (int i = 0; i < N; i++) table[numbers[i]] = i;
        vector<int> res(2, -1);
        for (int i = 0; i < N; i++) {
            int num = target - numbers[i];
            if (table.count(num) && i != table[num]) {
                res[0] = i + 1;
                res[1] = table[num] + 1;
                if (res[0] > res[1]) swap(res[0], res[1]);
                break;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> p0;
    int p1;
    vector<int> p2;

    {
        p0 = { 2, 7, 11, 15 };
        p1 = 9;
        p2 = sol.twoSum(p0, p1);
        cout << p2[0] << "," << p2[1] << endl;
    }

    {
        vector<int> p0 = { 3, 2, 4 };
        p1 = 6;
        p2 = sol.twoSum(p0, p1);
        cout << p2[0] << "," << p2[1] << endl;
    }

    return 0;
}
