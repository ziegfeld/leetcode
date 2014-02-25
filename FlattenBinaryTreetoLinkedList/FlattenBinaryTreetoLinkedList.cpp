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
// O(n) time, O(1) space
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
        while (root != NULL) {
            if (root->left != NULL) {
                TreeNode * rt = root->right;
                root->right = root->left;
                root->left = NULL;
                TreeNode * cur = root;
                while (cur->right) cur = cur->right;
                cur->right = rt;
            }
            root = root->right;
        }
    }
};

int main() {
    return 0;
}