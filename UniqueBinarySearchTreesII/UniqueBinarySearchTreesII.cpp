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
        vector<vector<vector<TreeNode *> > > memo(n + 1, vector<vector<TreeNode *> >(n + 1, vector<TreeNode *>()));
        return generateTreesHelper1(1, n, memo);
    }

    vector<TreeNode *> generateTreesHelper1(int l, int u, vector<vector<vector<TreeNode *> > > & memo) {
        if (l > u) {
            vector<TreeNode *> res;
            res.push_back(NULL);
            return res;
        }
        if (!memo[l][u].empty()) return memo[l][u];
        vector<TreeNode *> res;
        for (int m = l; m <= u; m++) {
            auto ls = generateTreesHelper1(l, m - 1, memo);
            auto rs = generateTreesHelper1(m + 1, u, memo);
            for (auto it1 : ls) {
                for (auto it2 : rs) {
                    TreeNode * root = new TreeNode(m);
                    root->left = it1;
                    root->right = it2;
                    res.push_back(root);
                }
            }
        }
        return memo[l][u] = res;
    }

    vector<TreeNode *> generateTrees2(int n) {
        vector<vector<vector<TreeNode *> > > dp(n + 2, vector<vector<TreeNode *> >(n + 2, vector<TreeNode *>()));
        for (int i = 1; i <= n + 1; i++) dp[i][i - 1].push_back(NULL);
        for (int l = 1; l <= n; l++) {
            for (int i = 1; i <= n - l + 1; i++) {
                int j = i + l - 1;
                vector<TreeNode *> res;
                for (int k = i; k <= j; k++) {
                    for (auto it1 : dp[i][k - 1]) {
                        for (auto it2 : dp[k + 1][j]) {
                            TreeNode * root = new TreeNode(k);
                            root->left = it1;
                            root->right = it2;
                            res.push_back(root);
                        }
                    }
                }
                dp[i][j] = res;
            }
        }

        return dp[1][n];
    }
};

string toString(TreeNode * root) {
    ostringstream os;
    queue<TreeNode *> cq, nq;
    cq.push(root);
    while (!cq.empty()) {
        vector<int> path;
        while (!cq.empty()) {
            TreeNode * cur = cq.front();
            cq.pop();
            if (cur == NULL) {
                os << "# ";
            }
            else {
                os << cur->val << " ";
                nq.push(cur->left);
                nq.push(cur->right);
            }
        }
        swap(cq, nq);
    }
    string res = os.str();
    res.pop_back();
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