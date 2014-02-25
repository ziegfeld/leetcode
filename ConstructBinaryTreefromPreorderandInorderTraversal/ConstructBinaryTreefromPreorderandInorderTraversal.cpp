//============================================================================
// Construct Binary Tree from Preorder and Inorder Traversal
// Given preorder and inorder traversal of a tree, construct the binary tree.
//
// Note:
// You may assume that duplicates do not exist in the tree.
//
// Complexity:
// Brute Force, O(nlog(n)) time, O(h) space
// Hash Table, O(n) time, O(n) space
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>

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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTree2(preorder, inorder);
    }

    TreeNode *buildTree1(vector<int> &preorder, vector<int> &inorder) {
        return buildTreeHelper1(preorder, inorder, 0, 0, preorder.size() - 1);
    }

    TreeNode *buildTreeHelper1(vector<int> &preorder, vector<int> &inorder, int i, int l, int u) {
        if (l > u) return NULL;
        int m;
        for (m = l; m <= u; m++) if (preorder[i] == inorder[m]) break;
        TreeNode * root = new TreeNode(preorder[i]);
        root->left = buildTreeHelper1(preorder, inorder, i + 1, l, m - 1);
        root->right = buildTreeHelper1(preorder, inorder, i + m - l + 1, m + 1, u);
        return root;
    }

    TreeNode *buildTree2(vector<int> &preorder, vector<int> &inorder) {
        unordered_map<int, int> table;
        for (int i = 0; i < inorder.size(); i++) table[inorder[i]] = i;
        return buildTreeHelper2(preorder, inorder, table, 0, 0, preorder.size() - 1);
    }

    TreeNode *buildTreeHelper2(vector<int> &preorder, vector<int> &inorder, unordered_map<int, int> & table, int i, int l, int u) {
        if (l > u) return NULL;
        int m = table[preorder[i]];
        TreeNode * root = new TreeNode(preorder[i]);
        root->left = buildTreeHelper2(preorder, inorder, table, i + 1, l, m - 1);
        root->right = buildTreeHelper2(preorder, inorder, table, i + m - l + 1, m + 1, u);
        return root;
    }
};

int main() {
    return 0;
}