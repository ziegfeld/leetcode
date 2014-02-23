//============================================================================
// Populating Next Right Pointers in Each Node
// 
// Given a binary tree
//
// struct TreeLinkNode {
//     TreeLinkNode *left;
//     TreeLinkNode *right;
//     TreeLinkNode *next;
// }
//
// Populate each next pointer to point to its next right node. If there is no 
// next right node, the next pointer should be set to NULL.
//
// Initially, all next pointers are set to NULL.
//
// Note:
//
// You may only use constant extra space.
// You may assume that it is a perfect binary tree (ie, all leaves are at the 
// same level, and every parent has two children).
// 
// For example, given the following perfect binary tree:
//  "     1     "
//  "    / \    "
//  "   2   3   "
//  "  / \ / \  "
//  " 4  5 6  7 "
// After calling your function, the tree should look like:
//  "      1 -> NULL      "
//  "     /  \            "
//  "    2 -> 3 -> NULL   "
//  "   / \  / \          "
//  "  4->5->6->7 -> NULL "
//
// Complexity:
// O(n) time, O(1) space
//============================================================================

#include <iostream>

using namespace std;

/**
 * Definition for binary tree with next pointer.
 */
struct TreeLinkNode
{
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        while (root && root->left) {
            TreeLinkNode *cur = root;
            while (cur) {
                cur->left->next = cur->right;
                cur->right->next = cur->next ? cur->next->left : NULL;
                cur = cur->next;
            }
            root = root->left;
        }
    }
};

int main() {
    Solution sol;
    TreeLinkNode * p0;

    {
        p0 = new TreeLinkNode(1);
        p0->left = new TreeLinkNode(2);
        p0->right = new TreeLinkNode(3);
        p0->left->left = new TreeLinkNode(4);
        p0->left->right = new TreeLinkNode(5);
        p0->right->left = new TreeLinkNode(6);
        p0->right->right = new TreeLinkNode(7);
        sol.connect(p0);
        while (p0 != NULL) {
            TreeLinkNode * cur = p0;
            while (cur != NULL) {
                cout << cur->val << "->";
                cur = cur->next;
            }
            cout << "#" << endl;
            p0 = p0->left;
        }
    }

    return 0;
}
