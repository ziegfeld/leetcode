//============================================================================
// Convert Sorted Array to Binary Search Tree
//
// Given an array where elements are sorted in ascending order, convert it to
// a height balanced BST.
//
// Pre-Order, O(n) time, O(h) space
// In-Order, O(n) time, O(h) space
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
    TreeNode *sortedArrayToBST(vector<int> & num) {
        if (num.empty()) return NULL;
        auto it = num.begin();
        return sortedArrayToBST2(it, 0, num.size() - 1);
    }

    TreeNode *sortedArrayToBST1(vector<int> &num, int l, int u) {
        if (l > u) return NULL;
        int m = l + (u - l) / 2;
        TreeNode * cur = new TreeNode(num[m]);
        cur->left = sortedArrayToBST1(num, l, m - 1);
        cur->right = sortedArrayToBST1(num, m + 1, u);
        return cur;
    }

    TreeNode *sortedArrayToBST2(vector<int>::iterator & it, int l, int u) {
        if (l > u) return NULL;
        int m = l + (u - l) / 2;
        TreeNode * tmp = sortedArrayToBST2(it, l, m - 1);
        TreeNode * cur = new TreeNode(*it++);
        cur->left = tmp;
        cur->right = sortedArrayToBST2(it, m + 1, u);
        return cur;
    }
};

int main() {
    return 0;
}