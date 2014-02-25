//============================================================================
// Binary Tree Zigzag Level Order Traversal
// Given a binary tree, return the zigzag level order traversal of its nodes'
// values. (ie, from left to right, then right to left for the next level and
// alternate between).
//
//For example:
// Given binary tree {3,9,20,#,#,15,7},
//    3
//   / \
//  9  20
//    /  \
//   15   7
// return its zigzag level order traversal as:
// [
//   [3],
//   [20,9],
//   [15,7]
// ]
//
// Complexity:
// O(n) time, O(n) space
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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > res;
        vector<stack<TreeNode *> > stk(2, stack<TreeNode *>());
        bool order = true;
        int pre = 0, cur = 1;
        if (root != NULL) stk[pre].push(root);
        while (!stk[pre].empty()) {
            vector<int> path;
            while (!stk[pre].empty()) {
                root = stk[pre].top(), stk[pre].pop();
                path.push_back(root->val);
                if (order) {
                    if (root->left != NULL) stk[cur].push(root->left);
                    if (root->right != NULL) stk[cur].push(root->right);
                }
                else {
                    if (root->right != NULL) stk[cur].push(root->right);
                    if (root->left != NULL) stk[cur].push(root->left);
                }
            }
            res.push_back(path);
            pre = cur, cur = !cur;
            order = !order;
        }
        return res;
    }
};

int main() {
    Solution sol;
    TreeNode * p0;

    {
        p0 = new TreeNode(3);
        p0->left = new TreeNode(9);
        p0->right = new TreeNode(20);
        p0->right->left = new TreeNode(15);
        p0->right->right = new TreeNode(7);
        auto p1 = sol.zigzagLevelOrder(p0);
        for (auto it1 : p1) {
            for (auto it2 : it1) cout << it2 << " ";
            cout << endl;
        }
    }

    return 0;
}