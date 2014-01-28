//============================================================================
// Binary Tree PreOrder Traversal
//
// Given a binary tree, return the preorder traversal of its nodes' values.
// 
// For example,
//
// Given binary tree {1,#,2,3},
// /*  1    */
// /*   \   */
// /*    2  */
// /*   /   */
// /*  3    */
// return [1,2,3].
//
// Note: Recursive solution is trivial, could you do it iteratively?
//
// Complexity:
// O(n) time, O(h) space, h is the depth of tree
//============================================================================

#include <iostream>
#include <stack>
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
    vector<int> preorderTraversal(TreeNode *root) {
        return preorderTraversal2(root);
    }

    vector<int> preorderTraversal1(TreeNode * root) {
        vector<int> res;
        preorderTraversalHelper1(root, res);
        return res;
    }

    void preorderTraversalHelper1(TreeNode * node, vector<int> & res) {
        if (node == NULL) return;
        res.push_back(node->val);
        preorderTraversalHelper1(node->left, res);
        preorderTraversalHelper1(node->right, res);
    }

    vector<int> preorderTraversal2(TreeNode * root) {
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode * cur = root;
        while (cur != NULL) {
            res.push_back(cur->val);
            stk.push(cur);
            cur = cur->left;
        }
        while (!stk.empty()) {
            cur = stk.top(), stk.pop();
            cur = cur->right;
            while (cur != NULL) {
                res.push_back(cur->val);
                stk.push(cur);
                cur = cur->left;
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
        auto p1 = sol.preorderTraversal(p0);
        for (auto it : p1) cout << it << " ";
        cout << endl;
    }

    return 0;
}