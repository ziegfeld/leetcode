//============================================================================
// Balanced Binary Tree
// Given a binary tree, determine if it is height-balanced.
//
// An example of a height-balanced tree. A height-balanced tree is a tree
// whose subtrees differ in height by no more than one and the subtrees are
// height-balanced, too.
//
// Top-Down, Pre-Order, O(n^2) time, O(h) space
// Bottom-Up, Post-Order, O(n) time, O(h) space
//============================================================================

#include <iostream>
#include <sstream>
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
    bool isBalanced(TreeNode *root) {
        return isBalanced2(root);
    }

    bool isBalanced1(TreeNode *cur) {
        if (cur == NULL) return true;
        return (abs(height(cur->left) - height(cur->right)) <= 1) && isBalanced(cur->left) && isBalanced1(cur->right);
    }

    int height(TreeNode * cur) {
        if (cur == NULL) return 0;
        return max(height(cur->left), height(cur->right)) + 1;
    }

    bool isBalanced2(TreeNode * root) {
        return (isBalancedHelper(root) >= 0);
    }

    int isBalancedHelper(TreeNode *cur) {
        if (cur == NULL) return 0;
        int lh = isBalancedHelper(cur->left), rh = isBalancedHelper(cur->right);
        if (lh == -1 || rh == -1 || abs(lh - rh) > 1) return -1;
        return max(lh, rh) + 1;
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
        p0 = fromString("{1,2,2,3,3,3,3,4,4,4,4,4,4,#,#,5,5}");
        cout << sol.isBalanced(p0) << endl;
    }

    return 0;
}