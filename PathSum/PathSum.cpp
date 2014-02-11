//============================================================================
// Path Sum
// Given a binary tree and a sum, determine if the tree has a root-to-leaf 
// path such that adding up all the values along the path equals the given 
// sum.
//
// For example:
// Given the below binary tree and sum = 22,
//              5
//             / \
//            4   8
//           /   / \
//          11  13  4
//         /  \      \
//        7    2      1
// return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 
// 22.
//
// Complexity:
// O(n) time, O(h) space, h is the height of tree
//============================================================================

#include <iostream>
#include <queue>
#include <sstream>

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
    bool hasPathSum(TreeNode *root, int sum) {
        return hasPathSumHelper(root, sum);
    }

    bool hasPathSumHelper(TreeNode * cur, int sum) {
        if (cur == NULL) return false;
        sum -= cur->val;
        if (cur->left == NULL && cur->right == NULL) return (sum == 0);
        return hasPathSumHelper(cur->left, sum) || hasPathSumHelper(cur->right, sum);
    }
};

int main() {
    Solution sol;
    TreeNode *p0;
    int p1;
    bool p2;

    {
        p0 = new TreeNode(5);
        p0->left = new TreeNode(4);
        p0->right = new TreeNode(8);
        p0->left->left = new TreeNode(11);
        p0->right->left = new TreeNode(13);
        p0->right->right = new TreeNode(4);
        p0->left->left->left = new TreeNode(7);
        p0->left->left->right = new TreeNode(2);
        p0->right->right->right = new TreeNode(1);
        p1 = 22;
        p2 = sol.hasPathSum(p0, p1);
        cout << p2 << endl;
    }

    {
        p0 = new TreeNode(-2);
        p0->right = new TreeNode(-3);
        p1 = -5;
        p2 = sol.hasPathSum(p0, p1);
        cout << p2 << endl;
    }

    return 0;
}