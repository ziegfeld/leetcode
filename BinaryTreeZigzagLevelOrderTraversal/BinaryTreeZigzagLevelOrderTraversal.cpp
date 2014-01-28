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
        stack<TreeNode *> cs, ns;
        if (root != NULL) cs.push(root);
        bool order = true;
        while (!cs.empty()) {
            vector<int> path;
            while (!cs.empty()) {
                TreeNode * cur = cs.top();
                cs.pop();
                path.push_back(cur->val);
                if (order) {
                    if (cur->left != NULL) ns.push(cur->left);
                    if (cur->right != NULL) ns.push(cur->right);
                }
                else {
                    if (cur->right != NULL) ns.push(cur->right);
                    if (cur->left != NULL) ns.push(cur->left);
                }
            }
            order = !order;
            res.push_back(path);
            swap(cs, ns);
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