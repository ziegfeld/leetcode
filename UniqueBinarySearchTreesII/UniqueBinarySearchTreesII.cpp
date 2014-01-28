//============================================================================
// Unique Binary Search Trees II
// Given n, generate all structurally unique BST's (binary search trees) that
// store values 1...n.
//
// For example,
// Given n = 3, your program should return all 5 unique BST's shown below.
//
//   1         3     3      2      1
//    \       /     /      / \      \
//     3     2     1      1   3      2
//    /     /       \                 \
//   2     1         2                 3
//
// Complexity: (Cn*n) Cn is Catalan number
// DFS + Memoization
// DP
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for binary tree
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        return generateTrees2(n);
    }

    vector<TreeNode *> generateTrees1(int n) {
        vector<vector<vector<TreeNode *> > > memo(n + 1, vector<vector<TreeNode*> >(n + 1, vector<TreeNode *>()));
        return generateTreesHelper1(memo, 1, n);
    }

    vector<TreeNode*> generateTreesHelper1(vector<vector<vector<TreeNode *> > > & memo, int l, int r) {
        vector<TreeNode*> res;
        if (l > r) {
            res.push_back(NULL);
            return res;
        }
        if (!memo[l][r].empty()) return memo[l][r];
        for (int k = l; k <= r; k++) {
            auto lts = generateTreesHelper1(memo, l, k - 1);
            auto rts = generateTreesHelper1(memo, k + 1, r);
            for (TreeNode * lt : lts) {
                for (TreeNode * rt : rts) {
                    TreeNode* cur = new TreeNode(k);
                    cur->left = lt;
                    cur->right = rt;
                    res.push_back(cur);
                }
            }
        }
        return memo[l][r] = res;
    }

    vector<TreeNode *> generateTrees2(int n) {
        vector<vector<vector<TreeNode *> > > dp(n + 2, vector<vector<TreeNode*> >(n + 2, vector<TreeNode *>()));
        for (int i = 1; i <= n + 1; i++) dp[i][i - 1].push_back(NULL);
        for (int i = 1; i <= n; i++) {
            for (int l = 1; l <= n - i + 1; l++) {
                int r = l + i - 1;
                if (l == r) {
                    dp[l][r].push_back(new TreeNode(l));
                    continue;
                }

                for (int k = l; k <= r; k++) {
                    for (TreeNode * lt : dp[l][k - 1]) {
                        for (TreeNode * rt : dp[k + 1][r]) {
                            TreeNode* cur = new TreeNode(k);
                            cur->left = lt;
                            cur->right = rt;
                            dp[l][r].push_back(cur);
                        }
                    }
                }
            }
        }

        return dp[1][n];
    }
};

string toStringHelper(TreeNode * cur) {
    if (cur == NULL) return "#,";
    string res = to_string(cur->val) + ',';
    res += toStringHelper(cur->left);
    res += toStringHelper(cur->right);
    return res;
}

string toString(TreeNode * root) {
    string res = "{";
    res += toStringHelper(root);
    res.pop_back();
    res += "}";
    return res;
}

int main() {
    Solution sol;

    {
        auto p1 = sol.generateTrees(3);
        for (auto it : p1) cout << toString(it) << endl;
    }

    return 0;
}