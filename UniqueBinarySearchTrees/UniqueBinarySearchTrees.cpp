//============================================================================
// Unique Binary Search Trees
// Given n, how many structurally unique BST's (binary search trees) that
// store values 1...n?
//
// For example,
// Given n = 3, there are a total of 5 unique BST's.
//
//   1         3     3      2      1
//    \       /     /      / \      \
//     3     2     1      1   3      2
//    /     /       \                 \
//   2     1         2                 3
//
// Complexity:
// Recursion, O(n^2) time, O(n) space
// DP, O(n^2) time, O(n) space
// Math, O(n) time, O(1) space
//============================================================================

#include <iostream>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        return numTree3(n);
    }

    int numTrees1(int n) {
        if (n <= 1) return 1;
        int res = 0;
        for (int i = 0; i < n; i++)
            res += numTrees(i)*numTrees(n - i - 1);
        return res;
    }

    int numTree2(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp[n];
    }

    int numTree3(int n) {
        int res = 1;
        for (int i = 1; i <= n; i++)
            res = res*(4 * i - 2) / (i + 1);
        return res;
    }
};

int main() {
    Solution sol;

    {
        cout << sol.numTrees(3) << endl;
    }

    return 0;
}