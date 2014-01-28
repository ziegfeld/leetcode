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
        TreeNode * cur = root;
        while (cur != NULL) stk.push(cur), cur = cur->left;
        while (!stk.empty()) {
            cur = stk.top(), stk.pop();
            if (pre != NULL && pre->val > cur->val) {
                if (first == NULL) first = pre;
                second = cur;
            }
            pre = cur;
            cur = cur->right;
            while (cur != NULL) stk.push(cur), cur = cur->left;
        }

        swap(first->val, second->val);
    }

    void recoverTree3(TreeNode *root) {
        TreeNode * pre = NULL, *first = NULL, *second = NULL;
        TreeNode * cur = root;
        while (cur != NULL) {
            if (cur->left != NULL) {
                TreeNode * p = cur->left;
                while (p->right != NULL && p->right != cur) p = p->right;
                if (p->right == NULL) {
                    p->right = cur;
                    cur = cur->left;
                }
                else {
                    p->right = NULL;
                    if (pre != NULL && pre->val > cur->val) {
                        if (first == NULL) first = pre;
                        second = cur;
                    }
                    pre = cur;
                    cur = cur->right;
                }
            }
            else {
                if (pre != NULL && pre->val > cur->val) {
                    if (first == NULL) first = pre;
                    second = cur;
                }
                pre = cur;
                cur = cur->right;
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