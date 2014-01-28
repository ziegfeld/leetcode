//============================================================================
// Validate Binary Search Tree
// Given a binary tree, determine if it is a valid binary search tree (BST).
//
// Assume a BST is defined as follows:
//
// The left subtree of a node contains only nodes with keys less than the
// node's key. The right subtree of a node contains only nodes with keys
// greater than the node's key. Both the left and right subtrees must also be
// binary search trees.
//
// Complexity:
// O(n) time
//============================================================================

#include <iostream>
#include <climits>
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
    bool isValidBST(TreeNode *root) {
        return isValidBST1(root, INT_MIN, INT_MAX);
    }

    bool isValidBST1(TreeNode * cur, int lo, int hi) {
        if (cur == NULL) return true;
        return (lo < cur->val && cur->val < hi) && isValidBST1(cur->left, lo, cur->val) && isValidBST1(cur->right, cur->val, hi);
    }

    bool isValidBST2(TreeNode * cur, int & preVal) {
        if (cur == NULL) return true;
        if (isValidBST2(cur->left, preVal) && preVal < cur->val) {
            preVal = cur->val;
            return isValidBST2(cur->right, preVal);
        }
        return false;
    }
};

int main() {
    return 0;
}
