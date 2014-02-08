//============================================================================
// Recover Binary Search Tree
// Two elements of a binary search tree (BST) are swapped by mistake.
//
// Recover the tree without changing its structure.
// 
// Complexity:
// Recursion or Stack: O(n) time, O(h) space, h is the depth of tree
// Threaded Binary Tree : O(n) time, O(1) space
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
    void recoverTree(TreeNode *root) {
        recoverTree3(root);
    }

    void recoverTree1(TreeNode *root) {
        TreeNode * pre = NULL, *first = NULL, *second = NULL;
        recoverTreeHelper1(root, pre, first, second);
        swap(first->val, second->val);
    }

    void recoverTreeHelper1(TreeNode * cur, TreeNode *& pre, TreeNode *& first, TreeNode *& second) {
        if (cur == NULL) return;
        recoverTreeHelper1(cur->left, pre, first, second);
        if (pre != NULL && pre->val > cur->val) {
            if (first == NULL) first = pre;
            second = cur;
        }
        pre = cur;
        recoverTreeHelper1(cur->right, pre, first, second);
    }

    void recoverTree2(TreeNode *root) {
        TreeNode * pre = NULL, *first = NULL, *second = NULL;
        stack<TreeNode *> stk;
        for (; root != NULL; root = root->left) stk.push(root);
        while (!stk.empty()) {
            root = stk.top(), stk.pop();
            if (pre != NULL && pre->val > root->val) {
                if (first == NULL) first = pre;
                second = root;
            }
            for (root = root->right; root != NULL; root = root->left) stk.push(root);
        }
        swap(first->val, second->val);
    }

    void recoverTree3(TreeNode *root) {
        TreeNode * last = NULL, *first = NULL, *second = NULL;

        while (root != NULL) {
            if (root->left != NULL) {
                TreeNode * pre = root->left;
                while (pre->right != NULL && pre->right != root) pre = pre->right;
                if (pre->right == NULL) {
                    pre->right = root;
                    root = root->left;
                }
                else {
                    pre->right = NULL;
                    if (last != NULL && last->val > root->val) {
                        if (first == NULL) first = last;
                        second = root;
                    }
                    last = root;
                    root = root->right;
                }
            }
            else {
                if (last != NULL && last->val > root->val) {
                    if (first == NULL) first = last;
                    second = root;
                }
                last = root;
                root = root->right;
            }
        }

        swap(first->val, second->val);
    }
};

string toStringHelper(TreeNode * cur) {
    if (cur == NULL) return "#,";
    string res = to_string(cur->val) + ',';
    res += toStringHelper(cur->left);
    res += toStringHelper(cur->right);
    return res;
}

string toString(TreeNode * root) {
    string res = "{";
    res += toStringHelper(root);
    res.pop_back();
    res += "}";
    return res;
}

int main() {
    Solution sol;
    TreeNode * p0;

    {
        p0 = new TreeNode(1);
        p0->right = new TreeNode(2);
        p0->right->left = new TreeNode(3);
        sol.recoverTree(p0);
        cout << toString(p0) << endl;
    }

    return 0;
}