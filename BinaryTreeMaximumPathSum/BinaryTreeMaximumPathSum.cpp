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
// Complexity:
// O(n) time, O(h) space
//============================================================================

#include <iostream>
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
    int maxPathSum(TreeNode *root) {
        if (root == NULL) return 0;
        int res = INT_MIN;
        maxPathHelper(root, res);
        return res;
    }

    int maxPathHelper(TreeNode *cur, int & path, int & sum) {
        if (cur == NULL) return 0;
        int lsub = maxPathHelper(cur->left, res);
        int rsub = maxPathHelper(cur->right, res);
        int sub = max(cur->val, cur->val + max(lsub, rsub));
        res = max(res, max(sub, cur->val + lsub + rsub));
        return sub;
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
    TreeNode *p0;
    int p1;

    {
        p0 = fromString("{1,2,3}");
        p1 = sol.maxPathSum(p0);
        cout << p1 << endl;
    }

    {
        p0 = fromString("{-3}");
        p1 = sol.maxPathSum(p0);
        cout << p1 << endl;
    }

    {
        p0 = fromString("{}");
        p1 = sol.maxPathSum(p0);
        cout << p1 << endl;
    }

    {
        p0 = fromString("{9,6,-3,#,#,-6,2,#,#,2,#,-6,-6,-6}");
        p1 = sol.maxPathSum(p0);
        cout << p1 << endl;
    }

    return 0;
}