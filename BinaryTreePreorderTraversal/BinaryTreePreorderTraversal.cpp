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
    vector<int> preorderTraversal(TreeNode *root)
    {
        return preorderTraversal2(root);
    }

    vector<int> preorderTraversal1(TreeNode *root) {
        vector<int> result;
        preorderTraversalHelper1(root, result);
        return result;
    }

    void preorderTraversalHelper1(TreeNode* node, vector<int>& result) {
        if(NULL == node) return;
        result.push_back(node->val);
        preorderTraversalHelper1(node->left, result);
        preorderTraversalHelper1(node->right, result);
    }

    vector<int> preorderTraversal2(TreeNode *root) {
        vector<int> result;
        if(NULL == root) return result;
        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode* curNode = stk.top();
            stk.pop();
            result.push_back(curNode->val);
            if (curNode->right) stk.push(curNode->right);
            if (curNode->left) stk.push(curNode->left);
        }
        return result;
    }
};
int main() {
    return 0;
}
