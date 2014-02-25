//============================================================================
// Permutation Sequence
// The set [1,2,3,…,n] contains a total of n! unique permutations.
//
// By listing and labeling all of the permutations in order,
// We get the following sequence (ie, for n = 3):
//
// "123"
// "132"
// "213"
// "231"
// "312"
// "321"
// Given n and k, return the kth permutation sequence.
//
// Note: Given n will be between 1 and 9 inclusive.
//
// Complexity:
// Next permutation based, O(k*n), k can be n!
// Math based, O(n^2)
//============================================================================

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        return getPermutation2(n, k);
    }

    string getPermutation1(int n, int k) {
        string res(n, '1');
        for (int i = 0; i < n; i++) res[i] += i;
        for (; k > 1; k--) next_permutation(begin(res), end(res));
        return res;
    }

    string getPermutation2(int n, int k) {
        vector<int> fs(n + 1, 1);
        for (int i = 2; i <= n; i++) fs[i] = fs[i - 1] * i;
        string res(n, '1');
        for (int i = 0; i < n; i++) res[i] += i;
        if (k > fs[n]) return res;
        k--;
        for (int i = 0; i < n - 1; i++) {
            int j = i + k / fs[n - 1 - i];
            k %= fs[n - 1 - i];
            char t = res[j];
            for (; j > i; j--) res[j] = res[j - 1];
            res[j] = t;
        }
        return res;
    }
};

int main() {
    Solution sol;
    for (int i = 1; i <= 6; i++)
        cout << sol.getPermutation(3, i) << endl;
    cout << sol.getPermutation(3, 6) << endl;
    return 0;
}