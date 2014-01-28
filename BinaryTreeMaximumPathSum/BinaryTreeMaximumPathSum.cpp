//============================================================================
// Binary Tree Maximum Path Sum
// Given a binary tree, find the maximum path sum.
//
// The path may start and end at any node in the tree.
//
// For example:
// Given the below binary tree,
//
//  "     1     "
//  "    / \    "
//  "   2   3   " 
//  
//  Return 6.
//
//============================================================================

#include <iostream>

using namespace std;

/**
 * Definition for binary tree
 */ 
struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxPathSum(TreeNode *root) {
        if (root == NULL) return 0;
        int res = INT_MIN;
        maxPathSumHelper(root, res);
        return res;
    }

    int maxPathSumHelper(TreeNode * cur, int & res) {
        if (cur == NULL) return 0;
        int leftPath = maxPathSumHelper(cur->left, res);
        int rightPath = maxPathSumHelper(cur->right, res);
        int curPath = cur->val;
        if (leftPath > 0) curPath += leftPath;
        if (rightPath > 0) curPath += rightPath;
        if (curPath > res) res = curPath;
        return max(cur->val, cur->val + max(leftPath, rightPath));
    }
};

TreeNode * readNode(istringstream & is) {
    string str;
    if (is >> str) {
        if (str == "#") return NULL;
        return new TreeNode(stoi(str));
    }
    return NULL;
}

TreeNode * fromString(string str) {
    str.erase(str.begin());
    str.pop_back();
    replace(begin(str), end(str), ',', ' ');
    istringstream is(str);
    TreeNode * root = readNode(is);
    queue<TreeNode *> qs;
    if (root != NULL) qs.push(root);
    while (!qs.empty()) {
        TreeNode * cur = qs.front();
        qs.pop();
        if (cur != NULL) {
            cur->left = readNode(is);
            if (cur->left != NULL) qs.push(cur->left);
            cur->right = readNode(is);
            if (cur->right != NULL) qs.push(cur->right);
        }
    }
    return root;
}

int main() {
    Solution sol;
    TreeNode * p0;

    {
        p0 = fromString("{1,2,3}");
        cout << sol.maxPathSum(p0) << endl;
    }
}