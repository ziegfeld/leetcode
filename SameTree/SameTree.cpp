//============================================================================
// Same Tree
// Given two binary trees, write a function to check if they are equal or not.
//
// Two binary trees are considered equal if they are structurally identical
// and the nodes have the same value.
//
// Complexity:
// DFS, O(n) time, O(h) space, h is the height of tree
// BFS, O(n) time, O(n) space
//============================================================================

#include <iostream>

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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (p == NULL && q == NULL) return true;
        if (p != NULL && q != NULL) {
            return (p->val == q->val) && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
        }
        return false;
    }
};

int main() {
    Solution sol;
    TreeNode * p0, *p1;

    {
        p0 = new TreeNode(1);
        p0->right = new TreeNode(2);
        p0->right->left = new TreeNode(3);
        p1 = new TreeNode(1);
        p1->right = new TreeNode(2);
        p1->right->left = new TreeNode(3);
        cout << sol.isSameTree(p0, p1) << endl;
    }

    return 0;
}
