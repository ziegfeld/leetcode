//============================================================================
// Binary Tree Maximum Path Sum
// Given a binary tree, find the maximum path sum.
//
// The path may start and end at any node in the tree.
//
// For example:
// Given the below binary tree,
//
//  "     1     "
//  "    / \    "
//  "   2   3   " 
//  
//  Return 6.
//
// Complexity:
// O(n) time, O(h) space
//============================================================================

#include <iostream>
#include <queue>

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
    int maxPathSum(TreeNode *root) {
        if (root == NULL) return 0;
        int res = INT_MIN;
        maxPathHelper(root, res);
        return res;
    }

    int maxPathHelper(TreeNode *cur, int & path, int & sum) {
        if (cur == NULL) return 0;
        int lsub = maxPathHelper(cur->left, res);
        int rsub = maxPathHelper(cur->right, res);
        int sub = max(cur->val, cur->val + max(lsub, rsub));
        res = max(res, max(sub, cur->val + lsub + rsub));
        return sub;
    }
};

int main() {
    Solution sol;
    TreeNode *p0;
    int p1;

    {
        p0 = new TreeNode(1);
        p0->left = new TreeNode(2);
        p0->right = new TreeNode(3);
        cout << p1 << endl;
    }

    {
        p0 = new TreeNode(-3);
        p1 = sol.maxPathSum(p0);
        cout << p1 << endl;
    }

    {
        p0 = NULL;
        p1 = sol.maxPathSum(p0);
        cout << p1 << endl;
    }

    {
        p0 = new TreeNode(9);
        p0->left = new TreeNode(6);
        p0->right = new TreeNode(-3);
        p0->right->left = new TreeNode(-6);
        p0->right->right = new TreeNode(2);
        p0->right->right->left = new TreeNode(2);
        p0->right->right->left->left = new TreeNode(-6);
        p0->right->right->left->right = new TreeNode(-6);
        p0->right->right->left->left->left = new TreeNode(-6);
        p1 = sol.maxPathSum(p0);
        cout << p1 << endl;
    }

    return 0;
}