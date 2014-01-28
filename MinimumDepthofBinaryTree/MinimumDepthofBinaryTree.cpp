//============================================================================
// Minimum Depth of Binary Tree
//
// Given a binary tree, find its minimum depth.
//
// The minimum depth is the number of nodes along the shortest path from the
// root node down to the nearest leaf node.
//
// Complexity:
// DFS takes O(2^h-1) time, O(h) space, h is the min depth of tree
// BFS takes O(2^h-1) time, O(2^(h-1)) space
//============================================================================

#include <iostream>
#include <climits>
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
    int minDepth(TreeNode *root) {
        return minDepth2(root);
    }

    int minDepth1(TreeNode * root) {
        if (root == NULL) return 0;
        int res = INT_MAX;
        minDepthHelper1(root, 0, res);
        return res;
    }

    void minDepthHelper1(TreeNode * cur, int depth, int & res) {
        if (cur == NULL || depth >= res) return;
        depth += 1;
        if (cur->left == NULL && cur->right == NULL) {
            res = min(res, depth);
            return;
        }
        minDepthHelper1(cur->left, depth, res);
        minDepthHelper1(cur->right, depth, res);
    }

    int minDepth2(TreeNode * root) {
        if (root == NULL) return 0;
        int res = 0;
        queue<TreeNode *> qs;
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
                if (cur->left == NULL && cur->right == NULL) return res + 1;
                if (cur->left != NULL) qs.push(cur->left);
                if (cur->right != NULL) qs.push(cur->right);
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
        cout << sol.minDepth(p0) << endl;
    }

    return 0;
}