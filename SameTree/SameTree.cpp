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
        return isSameTree2(p, q);
    }

    bool isSameTree1(TreeNode *p, TreeNode *q) {
        if (p == NULL && q == NULL) return true;
        if (p == NULL || q == NULL) return false;
        return (p->val == q->val) && isSameTree1(p->left, q->left) && isSameTree1(p->right, q->right);
    }

    bool isSameTree2(TreeNode *p, TreeNode *q) {
        queue<TreeNode *> ps, qs;
        if (p != NULL) ps.push(p);
        if (q != NULL) qs.push(q);
        while (!ps.empty() && !qs.empty()) {
            p = ps.front(), ps.pop();
            q = qs.front(), qs.pop();
            if (p->val != q->val) return false;
            if (p->left != NULL && q->left != NULL) ps.push(p->left), qs.push(q->left);
            else if (!(p->left == NULL && q->left == NULL)) return false;
            if (p->right != NULL && q->right != NULL) ps.push(p->right), qs.push(q->right);
            else if (!(p->right == NULL && q->right == NULL)) return false;
        }
        return ps.empty() && qs.empty();
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
