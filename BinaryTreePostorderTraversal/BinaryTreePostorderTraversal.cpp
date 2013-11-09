//============================================================================
// Binary Tree Postorder Traversal
//
// Given a binary tree, return the postorder traversal of its nodes' values.
//
// For example:
// Given binary tree {1,#,2,3},
//   1
//    \
//     2
//    /
//   3
// return [3,2,1].
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
    vector<int> postorderTraversal(TreeNode* node) {
        //return postorderTraversal1(node);
    return postorderTraversal2(node);
    }

    vector<int> postorderTraversal1(TreeNode* node) {
        vector<int> result;
        if (node == NULL) return result;
        postorderTraversalHelper1(node, result);
        return result;
    }

    void postorderTraversalHelper1(TreeNode* node, vector<int> &result) {
        if (node == NULL) return;
        postorderTraversalHelper1(node->left, result);
        postorderTraversalHelper1(node->right, result);
        result.push_back(node->val);
    }

    vector<int> postorderTraversal2(TreeNode *node) {
        vector<int> result;
        if (node == NULL) return result;
        stack<TreeNode*> stk;
        stk.push(node);
        TreeNode* preNode = NULL;
        while (!stk.empty()) {
            TreeNode* curNode = stk.top();
            if (!preNode || preNode->left == curNode || preNode->right == curNode) {
                // we are traversing down
                if (curNode->left) stk.push(curNode->left);
                else if (curNode->right) stk.push(curNode->right);
            }
            else if(curNode->left == preNode) {
                // we are traversing up, and from left node
                if (curNode->right) stk.push(curNode->right);
            }
            else {
                result.push_back(curNode->val);
                stk.pop();
            }
            preNode = curNode;
        }
        return result;
    }
};
int main() {
   return 0;
}
