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
        //return isBalanced_queue(root);
        return (isBalancedHelper(root) >= 0);
    }

    int isBalancedHelper(TreeNode *cur) {
        if (cur == NULL) return 0;
        int lh = isBalancedHelper(cur->left), rh = isBalancedHelper(cur->right);
        if (lh == -1 || rh == -1 || abs(lh - rh) > 1) return -1;
        return max(lh, rh) + 1;
    }

    // wrong answer by me! for example:
    // { 1; 2,2 ; 3,3,3,3;4,4,4,4,4,4,#,#; 5,5 is balanced!! but false negative here.
    bool isBalanced_queue(TreeNode *root) {
        queue<TreeNode*> qs;
        if (!root) return true;
        qs.push(root);
        qs.push(NULL);

        int totalOfLevel = 0;
        int totalShouldOfLevel = 1;
        
        while (!qs.empty()){
            TreeNode * cur = qs.front();
            qs.pop();
            
            if (cur) {
                totalOfLevel ++;
                if (cur->left)  qs.push(cur->left);
                if (cur->right) qs.push(cur->right);
            } else if (!qs.empty()) {
                // level ends, tree still goes.
                if (totalShouldOfLevel != totalOfLevel)
                    return false;
                
                totalShouldOfLevel <<= 1;
                totalOfLevel = 0;
                qs.push(NULL);
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    TreeNode * p0;

    {
        p0 = new TreeNode(1);
        p0->left = new TreeNode(2);
        p0->right = new TreeNode(2);
        p0->left->left = new TreeNode(3);
        p0->left->right = new TreeNode(3);
        p0->right->left = new TreeNode(3);
        p0->right->right = new TreeNode(3);
        p0->left->left->left = new TreeNode(4);
        p0->left->left->right = new TreeNode(4);
        p0->left->right->left = new TreeNode(4);
        p0->left->right->right = new TreeNode(4);
        p0->right->left->left = new TreeNode(4);
        p0->right->left->right = new TreeNode(4);
        p0->left->left->left->left = new TreeNode(5);
        p0->left->left->left->right = new TreeNode(5);
        cout << sol.isBalanced(p0) << endl;
    }

    return 0;
}
