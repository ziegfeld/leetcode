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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> stk;
        for (; root != NULL; root = root->right) res.push_back(root->val), stk.push(root);
        while (!stk.empty()) {
            root = stk.top()->left, stk.pop();
            for (; root != NULL; root = root->right) res.push_back(root->val), stk.push(root);
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