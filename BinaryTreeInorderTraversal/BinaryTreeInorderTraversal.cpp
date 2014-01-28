//============================================================================
// Binary Tree Inorder Traversal
// Given a binary tree, return the inorder traversal of its nodes' values.
//
// For example:
// Given binary tree {1,#,2,3},
//   1
//    \
//     2
//    /
//   3
// return [1,3,2].
//
// Note: Recursive solution is trivial, could you do it iteratively?
//
// Complexity:
// Recursion or Stack: O(n) time, O(h) space, h is the depth of tree
// Threaded Binary Tree : O(n) time, O(1) space
//============================================================================

#include <iostream>
#include <vector>
#include <stack>
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
    vector<int> inorderTraversal(TreeNode *root) {
        return inorderTraversal2(root);
    }

    vector<int> inorderTraversal1(TreeNode * root) {
        vector<int> res;
        inorderTraversalHelper1(root, res);
        return res;
    }

    void inorderTraversalHelper1(TreeNode * node, vector<int> & res) {
        if (node == NULL) return;
        inorderTraversalHelper1(node->left, res);
        res.push_back(node->val);
        inorderTraversalHelper1(node->right, res);
    }

    vector<int> inorderTraversal2(TreeNode * root) {
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode * cur = root;
        while (cur != NULL) stk.push(cur), cur = cur->left;
        while (!stk.empty()) {
            cur = stk.top(), stk.pop();
            res.push_back(cur->val);
            cur = cur->right;
            while (cur != NULL) stk.push(cur), cur = cur->left;
        }
        return res;
    }

    vector<int> inorderTraversal3(TreeNode * root) {
        vector<int> res;
        TreeNode * cur = root;
        while (cur != NULL) {
            if (cur->left != NULL) {
                TreeNode * pre = cur->left;
                while (pre->right != NULL && pre->right != cur) pre = pre->right;
                if (pre->right == NULL) {
                    pre->right = cur;
                    cur = cur->left;
                }
                else {
                    pre->right = NULL;
                    res.push_back(cur->val);
                    cur = cur->right;
                }
            }
            else {
                res.push_back(cur->val);
                cur = cur->right;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    TreeNode * p0;

    {
        p0 = new TreeNode(1);
        p0->right = new TreeNode(2);
        p0->right->left = new TreeNode(3);
        auto p1 = sol.inorderTraversal(p0);
        for (auto it : p1) cout << it << " ";
        cout << endl;
    }

    return 0;
}