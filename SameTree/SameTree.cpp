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
        if (p == NULL || q == NULL || p->val != q->val) return false;
        return isSameTree1(p->left, q->left) && isSameTree1(p->right, q->right);
    }

    bool isSameTree2(TreeNode *p, TreeNode *q) {
        if (p == NULL && q == NULL) return true;
        if (p == NULL || q == NULL || p->val != q->val) return false;
        queue<TreeNode *> ps, qs;
        ps.push(p), qs.push(q);
        while (!ps.empty() && !qs.empty()) {
            TreeNode * cp = ps.front(), *cq = qs.front();
            ps.pop(), qs.pop();
            if (cp->left != NULL && cq->left != NULL) {
                if (cp->left->val != cq->left->val) return false;
                ps.push(cp->left), qs.push(cq->left);
            }
            else if (!(cp->left == NULL && cq->left == NULL)) return false;
            if (cp->right != NULL && cq->right != NULL) {
                if (cp->right->val != cq->right->val) return false;
                ps.push(cp->right), qs.push(cq->right);
            }
            else if (!(cp->right == NULL && cq->right == NULL)) return false;
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