//============================================================================
// Construct Binary Tree from Inorder and Postorder Traversal
// Given inorder and postorder traversal of a tree, construct the binary tree.
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return buildTree2(inorder, postorder);
    }

    TreeNode *buildTree1(vector<int> &inorder, vector<int> &postorder) {
        return buildTreeHelper1(inorder, postorder, postorder.size() - 1, 0, postorder.size() - 1);
    }

    TreeNode *buildTreeHelper1(vector<int> &inorder, vector<int> &postorder, int i, int l, int u) {
        if (l > u) return NULL;
        int m;
        for (m = l; m <= u; m++) if (postorder[i] == inorder[m]) break;
        TreeNode * root = new TreeNode(postorder[i]);
        root->left = buildTreeHelper1(inorder, postorder, i - (u - m) - 1, l, m - 1);
        root->right = buildTreeHelper1(inorder, postorder, i - 1, m + 1, u);
        return root;
    }

    TreeNode *buildTree2(vector<int> &inorder, vector<int> &postorder) {
        unordered_map<int, int> table;
        for (int i = 0; i < inorder.size(); i++) table[inorder[i]] = i;
        return buildTreeHelper2(inorder, postorder, table, postorder.size() - 1, 0, postorder.size() - 1);
    }

    TreeNode *buildTreeHelper2(vector<int> &inorder, vector<int> &postorder, unordered_map<int, int> & table, int i, int l, int u) {
        if (l > u) return NULL;
        int m = table[postorder[i]];
        TreeNode * root = new TreeNode(postorder[i]);
        root->left = buildTreeHelper1(inorder, postorder, i - (u - m) - 1, l, m - 1);
        root->right = buildTreeHelper1(inorder, postorder, i - 1, m + 1, u);
        return root;
    }
};

string toString(TreeNode * root) {
    ostringstream os;
    queue<TreeNode *> cq, nq;
    cq.push(root);
    while (!cq.empty()) {
        vector<int> path;
        while (!cq.empty()) {
            TreeNode * cur = cq.front();
            cq.pop();
            if (cur == NULL) {
                os << "# ";
            }
            else {
                os << cur->val << " ";
                nq.push(cur->left);
                nq.push(cur->right);
            }
        }
        swap(cq, nq);
    }
    string res = os.str();
    res.pop_back();
    return res;
}

int main() {
    Solution sol;
    vector<int> p0;
    vector<int> p1;

    {
        p0 = { 1, 3, 2 };
        p1 = { 3, 2, 1 };
        auto p2 = sol.buildTree(p0, p1);
        cout << toString(p2) << endl;
    }

    return 0;
}