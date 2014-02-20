//============================================================================
// Given a binary tree, check whether it is a mirror of itself (ie, symmetric
// around its center).
//
// For example, this binary tree is symmetric:
//
//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
// But the following is not:
//    1
//   / \
//  2   2
//   \   \
//   3    3
// Note:
// Bonus points if you could solve it both recursively and iteratively.
//
// DFS, O(n) time, O(h) space, h is the height of tree
// BFS, O(n) time, O(n) space
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
    bool isSymmetric(TreeNode *root) {
        return isSymmetric2(root);
    }
    
    bool isSymmetric1(TreeNode *root) {
        if (!root) return true;
        if (root->left == NULL)
            if (root->right == NULL) return true;
            else return false;
        else if (root->right == NULL) return false;
            else return mirrorSubtree(root->left, root->right);
    }
    
    bool mirrorSubtree(TreeNode *left, TreeNode *right) {
        if (left->val != right->val) return false;
        
        if (left->right == NULL) {
            if (right -> left != NULL) return false;
        } else if ((right -> left == NULL) || !mirrorSubtree(left->right, right->left))
            return false;
            
        if (left->left == NULL) {
            if (right -> right != NULL) return false;
        } else if ((right -> right == NULL) || !mirrorSubtree(left->left, right->right)) return false;
        
        return true; 
    }
    
    //these 3 func are from Symmetric1 of https://github.com/anson627/leetcode/blob/master/SymmetricTree/SymmetricTree.cpp  
    
    bool isSymmetric2(TreeNode *root) {
        if (root == NULL) return true;
        //return isSymmetric2(root->left, root->right);
        return isSymmetric3(root->left, root->right);
    }
        
    // DFS. only diff. from mine is that they judge NULL after going into next level of the recursive function.
    // WHICH IS MORE INDUSTRIAL STANDARD.
    bool isSymmetric2(TreeNode *p, TreeNode *q) {
        if (p == NULL && q == NULL) return true;
        if (p == NULL || q == NULL) return false;
        return (p->val == q->val) && isSymmetric2(p->left, q->right) && isSymmetric2(p->right, q->left);
    }
    
    
    // BFS. with Queue.  LEARN!!!!!!
    bool isSymmetric3(TreeNode * p, TreeNode *q) {
        queue<TreeNode *> ps, qs;
        if (p) ps.push(p);
        if (q) qs.push(q);
        while (!ps.empty() && !qs.empty()) {
            p = ps.front(), ps.pop();
            q = qs.front(), qs.pop();
            if (p->val != q->val) return false;
            if (p->left && q->right) ps.push(p->left),qs.push(q->right);
            else if (!(!p->left && !q->right)) return false;
            if (p->right && q->left) ps.push(p->right),qs.push(q->left);
            else if (!(!p->right && !q->left)) return false;
        }
        return ps.empty() && qs.empty();
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
        p0->left->right = new TreeNode(4);
        p0->right->left = new TreeNode(4);
        p0->right->right = new TreeNode(3);
        cout << sol.isSymmetric(p0) << endl;
    }

    {
        p0 = new TreeNode(1);
        p0->left = new TreeNode(2);
        p0->right = new TreeNode(2);
        p0->left->right = new TreeNode(3);
        p0->right->right = new TreeNode(3);
        cout << sol.isSymmetric(p0) << endl;
    }

    return 0;
}
