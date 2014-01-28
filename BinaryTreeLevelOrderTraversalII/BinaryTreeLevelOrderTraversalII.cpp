//============================================================================
// Binary Tree Level Order Traversal II
// Given a binary tree, return the bottom-up level order traversal of its
// nodes' values. (ie, from left to right, level by level from leaf to root).
//
// For example:
// Given binary tree {3,9,20,#,#,15,7},
// "    3      "
// "   / \     "
// "  9  20    "
// "    /  \   "
// "   15   7  "
// return its bottom-up level order traversal as:
// [
//   [15,7]
//   [9,20],
//   [3],
// ]
//
// Complexity:
// DFS O(n) time, O(h) space, h is the height (max depth) of tree
// BFS O(n) time, O(n) space
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
    vector<vector<int> > levelOrderBottom(TreeNode * root) {
        return levelOrderBottom1(root);
    }

    vector<vector<int> > levelOrderBottom1(TreeNode * root) {
        vector<vector<int> > res;
        int D = maxDepth(root);
        for (int depth = D; depth >= 1; depth--) {
            vector<int> path;
            levelOrderBottomHelper1(root, depth, path);
            res.push_back(path);
        }
        return res;
    }

    int maxDepth(TreeNode * cur) {
        if (cur == NULL) return 0;
        return max(maxDepth(cur->left), maxDepth(cur->right)) + 1;
    }

    void levelOrderBottomHelper1(TreeNode * cur, int depth, vector<int> & path) {
        if (cur == NULL || depth == 0) return;
        if (depth == 1) path.push_back(cur->val);
        depth -= 1;
        levelOrderBottomHelper1(cur->left, depth, path);
        levelOrderBottomHelper1(cur->right, depth, path);
    }

    vector<vector<int> > levelOrderBottom2(TreeNode * root) {
        vector<vector<int> > res;
        queue<TreeNode *> cq, nq;
        if (root != NULL) cq.push(root);
        while (!cq.empty()) {
            vector<int> path;
            while (!cq.empty()) {
                TreeNode * cur = cq.front();
                cq.pop();
                path.push_back(cur->val);
                if (cur->left != NULL) nq.push(cur->left);
                if (cur->right != NULL) nq.push(cur->right);
            }
            res.push_back(path);
            swap(cq, nq);
        }
        reverse(begin(res), end(res));
        return res;
    }

    vector<vector<int> > levelOrderBottom3(TreeNode * root) {
        vector<int> path;
        vector<vector<int> > res;
        queue<TreeNode *> qs;
        if (root != NULL) {
            qs.push(root);
            qs.push(NULL);
        }
        while (!qs.empty()) {
            TreeNode * cur = qs.front();
            qs.pop();
            if (cur == NULL) {
                res.push_back(path);
                path.clear();
                if (!qs.empty()) qs.push(NULL);
            }
            else {
                path.push_back(cur->val);
                if (cur->left != NULL) qs.push(cur->left);
                if (cur->right != NULL) qs.push(cur->right);
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
        p0 = new TreeNode(3);
        p0->left = new TreeNode(9);
        p0->right = new TreeNode(20);
        p0->right->left = new TreeNode(15);
        p0->right->right = new TreeNode(7);
        auto p1 = sol.levelOrderBottom(p0);
        for (auto it1 : p1) {
            for (auto it2 : it1) cout << it2 << " ";
            cout << endl;
        }
    }

    return 0;
}