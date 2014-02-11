//============================================================================
//  Given a binary tree containing digits from 0-9 only, each root-to-leaf 
//  path could represent a number.
//
//  An example is the root-to-leaf path 1->2->3 which represents the number 
//  123.
//
//  Find the total sum of all root-to-leaf numbers.
//
//  For example,
//
//  /*    1     */
//  /*   / \    */
//  /*  2   3   */
//  The root-to-leaf path 1->2 represents the number 12.
//  The root-to-leaf path 1->3 represents the number 13.
//
//  return the sum = 12 + 13 = 25.
//
// Complexity:
// O(n) time, O(h) space
//============================================================================

#include <iostream>
#include <vector>
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
    int sumNumbers(TreeNode *root) {
        int res = 0;
        sumNumbersHelper(root, 0, res);
        return res;
    }

    void sumNumbersHelper(TreeNode * cur, int path, int & res) {
        if (cur == NULL) return;
        path += cur->val;
        if (cur->left == NULL && cur->right == NULL) {
            res += path;
            return;
        }
        path *= 10;
        sumNumbersHelper(cur->left, path, res);
        sumNumbersHelper(cur->right, path, res);
    }
};

int main() {
    Solution sol;
    TreeNode * p0;

    {
        p0 = new TreeNode(1);
        p0->left = new TreeNode(2);
        p0->right = new TreeNode(3);
        cout << sol.sumNumbers(p0) << endl;
    }
}