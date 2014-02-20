//============================================================================
// Binary Tree Level Order Traversal
// Given a binary tree, return the level order traversal of its nodes' values.
// (ie, from left to right, level by level).
//
// For example:
// Given binary tree {3,9,20,#,#,15,7},
//    3
//   / \
//  9  20
//    /  \
//   15   7
// return its level order traversal as:
// [
//   [3],
//   [9,20],
//   [15,7]
// ]
//
// Complexity:
// DFS O(n) time, O(h) space, h is the height (max depth) of tree
// BFS O(n) time, O(n) space
//============================================================================

#include <iostream>
#include <vector>
#include <queue>
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
    
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int>> tree;
        //if (! root) return tree;
        if (root == NULL) return tree;
        vector<int> level;
        //tree.push_back(new vector<int> {root->val});
        queue<TreeNode*> qtree;
        qtree.push(root);
        qtree.push(NULL);
        while (!qtree.empty()) {
            TreeNode * node = qtree.front();
            qtree.pop();
            if (node) {
                if (node->left) qtree.push(node->left);
                if (node->right) qtree.push(node->right);
                level.push_back(node->val);
            } else {
                //tree.insert(tree.begin(),level); insert is linear time
                tree.push_back(level);//push_back constant time
                if (!qtree.empty()) qtree.push(NULL);
                level.clear();
            }
            
        }
        return tree;
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
        auto p1 = sol.levelOrder(p0);
        for (auto it1 : p1) {
            for (auto it2 : it1) cout << it2 << " ";
            cout << endl;
        }
    }

    return 0;
}
