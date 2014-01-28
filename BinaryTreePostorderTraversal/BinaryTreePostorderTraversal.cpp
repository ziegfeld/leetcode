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
// Complexity:
// O(n) time, O(k) space, k is the depth of tree
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
    vector<int> postorderTraversal(TreeNode* root) {
        return postorderTraversal1(root);
    }

    vector<int> postorderTraversal1(TreeNode* root) {
        vector<int> res;
        postorderTraversalHelper1(root, res);
        return res;
    }

    void postorderTraversalHelper1(TreeNode* node, vector<int> & res) {
        if (node == NULL) return;
        postorderTraversalHelper1(node->left, res);
        postorderTraversalHelper1(node->right, res);
        res.push_back(node->val);
    }

    vector<int> postorderTraversal2(TreeNode *root) {
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode * cur = root;
        while (cur != NULL) {
            res.push_back(cur->val);
            stk.push(cur);
            cur = cur->right;
        }
        while (!stk.empty()) {
            cur = stk.top(), stk.pop();
            cur = cur->left;
            while (cur != NULL) {
                res.push_back(cur->val);
                stk.push(cur);
                cur = cur->right;
            }
        }

        reverse(begin(res), end(res));
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
        auto p1 = sol.postorderTraversal(p0);
        for (auto it : p1) cout << it << " ";
        cout << endl;
    }

    return 0;
}