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

    vector<int> inorderTraversal1(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> stk;
        for (; root != NULL; root = root->left) stk.push(root);
        while (!stk.empty()) {
            root = stk.top(), stk.pop(), res.push_back(root->val);
            for (root = root->right; root != NULL; root = root->left) stk.push(root);
        }
        return res;
    }

    vector<int> inorderTraversal2(TreeNode * root) {
        vector<int> res;
        while (root != NULL) {
            if (root->left != NULL) {
                auto pre = root->left;
                while (pre->right != NULL && pre->right != root) pre = pre->right;
                if (pre->right == NULL) {
                    pre->right = root;
                    root = root->left;
                }
                else {
                    pre->right = NULL;
                    res.push_back(root->val);
                    root = root->right;
                }
            }
            else {
                res.push_back(root->val);
                root = root->right;
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