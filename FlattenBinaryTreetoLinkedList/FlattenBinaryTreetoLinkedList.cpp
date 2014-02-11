//============================================================================
// Flatten Binary Tree to Linked List
// Given a binary tree, flatten it to a linked list in-place.
//
// For example,
// Given
//
//         1
//        / \
//       2   5
//      / \   \
//     3   4   6
// The flattened tree should look like:
//   1
//    \
//     2
//      \
//       3
//        \
//         4
//          \
//           5
//            \
//             6
// Hints:
// If you notice carefully in the flattened tree, each node's right child
// points to the next node of a pre-order traversal.
//
// Complexity:
// Recursion, O(n) time, O(h) space
// Stack, O(n) time, O(h) space
// Incremental, O(n) time, O(1) space
//============================================================================

#include <iostream>
#include <stack>
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
    void flatten(TreeNode *root) {
        flatten2(root);
    }

    TreeNode * flatten1(TreeNode * cur) {
        if (cur == NULL) return NULL;
        TreeNode * rt = cur->right;
        if (cur->left != NULL) {
            cur->right = cur->left;
            cur->left = NULL;
            cur = flatten1(cur->right);
        }
        if (rt != NULL) {
            cur->right = rt;
            cur = flatten1(cur->right);
        }
        return cur;
    }

    void flatten2(TreeNode *cur) {
        stack<TreeNode *> stk;
        while (cur != NULL) {
            if (cur->left != NULL) {
                if (cur->right != NULL) stk.push(cur->right);
                cur->right = cur->left;
                cur->left = NULL;
            }
            if (cur->right == NULL && !stk.empty()) {
                cur->right = stk.top(), stk.pop();
            }
            cur = cur->right;
        }
    }

    void flatten3(TreeNode *cur) {
        while (cur != NULL) {
            TreeNode * pre = cur->left;
            while (pre != NULL && pre->right != NULL) pre = pre->right;
            if (pre != NULL) {
                pre->right = cur->right;
                cur->right = cur->left;
                cur->left = NULL;
            }
            cur = cur->right;
        }
    }
};

int main() {
    return 0;
}