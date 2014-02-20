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
