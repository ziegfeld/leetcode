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
        vector<int> res;
        stack<TreeNode *> stk;
        if (root != NULL) stk.push_back(root);
        while (!stk.empty()) {
            root = stk.top(), stk.pop();
            res.push_back(root->val);
            if (root->right != NULL) res.push_back(root->right);
            if (root->left != NULL) res.push_back(root->left);
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