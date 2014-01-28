//============================================================================
// Given a binary tree, check whether it is a mirror of itself (ie, symmetric
// around its center).
//
// For example, this binary tree is symmetric:
//
//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
// But the following is not:
//    1
//   / \
//  2   2
//   \   \
//   3    3
// Note:
// Bonus points if you could solve it both recursively and iteratively.
//
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
    bool isSymmetric(TreeNode * root) {
        return isSymmetric2(root);
    }

    bool isSymmetric1(TreeNode * root) {
        if (root == NULL) return true;
        return isSymmetricHelper1(root->left, root->right);
    }
    bool isSymmetricHelper1(TreeNode *p, TreeNode *q) {
        if (p == NULL && q == NULL) return true;
        if (p == NULL || q == NULL || p->val != q->val) return false;
        return isSymmetricHelper1(p->left, q->right) && isSymmetricHelper1(p->right, q->left);
    }

    bool isSymmetric2(TreeNode * root) {
        if (root == NULL || (root->left == NULL && root->right == NULL)) return true;
        if (root->left == NULL || root->right == NULL || root->left->val != root->right->val) return false;
        queue<TreeNode *> ps, qs;
        ps.push(root->left), qs.push(root->right);
        while (!ps.empty() && !qs.empty()) {
            TreeNode * cp = ps.front(), *cq = qs.front();
            ps.pop(), qs.pop();
            if (cp->left != NULL && cq->right != NULL) {
                if (cp->left->val != cq->right->val) return false;
                ps.push(cp->left), qs.push(cq->right);
            }
            else if (!(cp->left == NULL && cq->right == NULL)) return false;
            if (cp->right != NULL && cq->left != NULL) {
                if (cp->right->val != cq->left->val) return false;
                ps.push(cp->right), qs.push(cq->left);
            }
            else if (!(cp->right == NULL && cq->left == NULL)) return false;
        }

        return ps.empty() && qs.empty();
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
        p0->left->right = new TreeNode(4);
        p0->right->left = new TreeNode(4);
        p0->right->right = new TreeNode(3);
        cout << sol.isSymmetric(p0) << endl;
    }

    {
        p0 = new TreeNode(1);
        p0->left = new TreeNode(2);
        p0->right = new TreeNode(2);
        p0->left->right = new TreeNode(3);
        p0->right->right = new TreeNode(3);
        cout << sol.isSymmetric(p0) << endl;
    }

    return 0;
}