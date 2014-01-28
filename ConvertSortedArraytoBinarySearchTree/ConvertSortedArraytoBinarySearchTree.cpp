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
                os << "#,";
            }
            else {
                os << cur->val << ",";
                nq.push(cur->left);
                nq.push(cur->right);
            }
        }
        swap(cq, nq);
    }
    string res = os.str();
    res.pop_back();
    return "{" + res + "}";
}

int main() {
    Solution sol;
    vector<int> p0;

    {
        p0 = { 3, 5, 8 };
        auto p1 = sol.sortedArrayToBST(p0);
        cout << toString(p1) << endl;
    }
    return 0;
}