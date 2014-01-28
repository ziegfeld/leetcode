//============================================================================
// Populating Next Right Pointers in Each Node II
// 
// Follow up for problem "Populating Next Right Pointers in Each Node".
//
// What if the given tree could be any binary tree? Would your previous 
// solution still work?
//
// Note:
//
// You may only use constant extra space.
// 
// For example, given the following perfect binary tree:
//  "     1     "
//  "    / \    "
//  "   2   3   "
//  "  / \   \  "
//  " 4  5    7 "
// After calling your function, the tree should look like:
//  "      1 -> NULL      "
//  "     /  \            "
//  "    2 -> 3 -> NULL   "
//  "   / \    \          "
//  "  4-> 5 -> 7 -> NULL "
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
        while (root != NULL) {
            TreeLinkNode * cur = root;
            while (cur != NULL) {
                if (cur->left != NULL && cur->right != NULL) cur->left->next = cur->right;
                TreeLinkNode * next = cur->next;
                while (next != NULL && next->left == NULL && next->right == NULL) next = next->next;
                if (next == NULL) break;
                TreeLinkNode * child = (next->left != NULL) ? next->left : next->right;
                if (cur->right != NULL) {
                    cur->right->next = child;
                }
                else if (cur->left != NULL) {
                    cur->left->next = child;
                }
                cur = next;
            }

            while (root != NULL && root->left == NULL && root->right == NULL) root = root->next;
            if (root != NULL) root = (root->left != NULL) ? root->left : root->right;
        }
    }
};

int main() {
    Solution sol;
    TreeLinkNode * p0;

    {
        p0 = new TreeLinkNode(3);
        p0->left = new TreeLinkNode(9);
        p0->right = new TreeLinkNode(20);
        p0->right->left = new TreeLinkNode(15);
        p0->right->right = new TreeLinkNode(7);
        sol.connect(p0);
        vector<TreeLinkNode*> vs = { p0, p0->left, p0->right->left };
        for (auto cur : vs) {
            while (cur != NULL) {
                cout << cur->val << "->";
                cur = cur->next;
            }
            cout << "#" << endl;
        }
    }
}