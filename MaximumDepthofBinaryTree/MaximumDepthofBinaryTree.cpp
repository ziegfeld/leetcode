//============================================================================
// Maximum Depth of Binary Tree
// Given a binary tree, find its maximum depth.
//
// The maximum depth is the number of nodes along the longest path from the
// root node down to the farthest leaf node.
//
// DFS takes O(n) time, O(h) space, h is the max depth of tree
// BFS takes O(n) time, O(n/2) space
//============================================================================

#include <iostream>
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
    int maxDepth(TreeNode * root) {
        return maxDepth2(root);
    }

    int maxDepth1(TreeNode * cur) {
        if (cur == NULL) return 0;
        return 1 + max(maxDepth1(cur->left), maxDepth1(cur->right));
    }

    int maxDepth2(TreeNode * root) {
        if (root == NULL) return 0;
        int res = 0;
        queue<TreeNode*> qs;
        qs.push(root);
        qs.push(NULL);

        while (!qs.empty()) {
            TreeNode * cur = qs.front();
            qs.pop();
            if (cur == NULL) {
                res++;
                if (!qs.empty()) qs.push(NULL);
            }
            else {
                if (cur->left) qs.push(cur->left);
                if (cur->right) qs.push(cur->right);
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
        cout << sol.maxDepth(p0) << endl;
    }

    return 0;
}