//============================================================================
// Balanced Binary Tree
// Given a binary tree, determine if it is height-balanced.
//
// An example of a height-balanced tree. A height-balanced tree is a tree
// whose subtrees differ in height by no more than one and the subtrees are
// height-balanced, too.
//
// Top-Down, Pre-Order, O(n^2) time, O(h) space
// Bottom-Up, Post-Order, O(n) time, O(h) space
//============================================================================

#include <iostream>
#include <sstream>
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
    bool isBalanced(TreeNode *root) {
        return isBalanced2(root);
    }

    bool isBalanced1(TreeNode *cur) {
        if (cur == NULL) return true;
        return (abs(height(cur->left) - height(cur->right)) <= 1) && isBalanced(cur->left) && isBalanced1(cur->right);
    }

    int height(TreeNode * cur) {
        if (cur == NULL) return 0;
        return max(height(cur->left), height(cur->right)) + 1;
    }

    bool isBalanced2(TreeNode * root) {
        return (isBalancedHelper(root) >= 0);
    }

    int isBalancedHelper(TreeNode *cur) {
        if (cur == NULL) return 0;
        int lh = isBalancedHelper(cur->left), rh = isBalancedHelper(cur->right);
        if (lh == -1 || rh == -1 || abs(lh - rh) > 1) return -1;
        return max(lh, rh) + 1;
    }
};

int main() {
    Solution sol;
    TreeNode * p0;

    {
        p0 = new TreeNode(1);
        p0->left = new TreeNode(2);
        p0->right = new TreeNode(2);
        p0->left->left = new TreeNode(3);
        p0->left->right = new TreeNode(3);
        p0->right->left = new TreeNode(3);
        p0->right->right = new TreeNode(3);
        p0->left->left->left = new TreeNode(4);
        p0->left->left->right = new TreeNode(4);
        p0->left->right->left = new TreeNode(4);
        p0->left->right->right = new TreeNode(4);
        p0->right->left->left = new TreeNode(4);
        p0->right->left->right = new TreeNode(4);
        p0->left->left->left->left = new TreeNode(5);
        p0->left->left->left->right = new TreeNode(5);
        cout << sol.isBalanced(p0) << endl;
    }

    return 0;
}