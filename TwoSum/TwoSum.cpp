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
    // mine : Time Limit Exceeded
    vector<int> twoSum1(vector<int> &numbers, int target) {
        vector<int> res(2,0);
        int i,j,k, N = numbers.size();
        vector<int> ind;
        for (i = 1; i <= N ; i++){
            ind.push_back(i);
        }
        for (i = 0; i < N - 1; i++){
            k = i;
            for (j = i + 1; j < N; j++)
                if (numbers[j]<numbers[k])
                    k = j;
            if (k != i) {
                swap(numbers[k],numbers[j]);
                swap(ind[k],ind[j]);
            }
        }
        i = 0, j = N -1;
        while (i<j){
            if (numbers[i]+numbers[j] == target) {
                if (ind[i]<ind[j])
                    res[0] = ind[i], res[1] = ind[j];
                else
                    res[0] = ind[j], res[1] = ind[i];
                return res;
            }
            if (numbers[i]+numbers[j]<target)
                i++;
            else
                j--;
        }
        return res;
    }
    
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int, int> tb;
        vector<int> res(2,0);
        int N = numbers.size();
        vector<int> ind;
        for (int i = 0; i < N; i++)
            tb[numbers[i]] = i + 1;
        for (int i = 0; i < N; i++)
            if (tb[target - numbers[i]]) {
                res[0] = i + 1;
                res[1] = tb[ target - numbers[i]];
                
                if (res[0]>res[1])
                    swap(res[0],res[1]);
                if (res[0]!=res[1]) return res;
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
