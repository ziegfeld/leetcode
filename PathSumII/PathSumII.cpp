//============================================================================
// Path Sum II
// Given a binary tree and a sum, find all root-to-leaf paths where each
// path's sum equals the given sum.
//
// For example:
// Given the below binary tree and sum = 22,
//              5
//             / \
//            4   8
//           /   / \
//          11  13  4
//         /  \    / \
//        7    2  5   1
// return
// [
//   [5,4,11,2],
//   [5,8,4,5]
// ]
//
// Complexity:
// O(n*h) time, O(h) space, h is the height of the tree
//============================================================================

#include <iostream>
#include <vector>
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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<int> path;
        vector<vector<int> > res;
        pathSumHelper(root, sum, path, res);
        return res;
    }

    void pathSumHelper(TreeNode * cur, int sum, vector<int> & path, vector<vector<int> > & res) {
        if (cur == NULL) return;
        sum -= cur->val;
        path.push_back(cur->val);
        if (cur->left == NULL && cur->right == NULL && sum == 0) res.push_back(path);
        pathSumHelper(cur->left, sum, path, res);
        pathSumHelper(cur->right, sum, path, res);
        path.pop_back();
    }
};

int main() {
    Solution sol;
    TreeNode *p0;
    int p1;
    vector<vector<int> > p2;

    {
        p0 = new TreeNode(5);
        p0->left = new TreeNode(4);
        p0->right = new TreeNode(8);
        p0->left->left = new TreeNode(11);
        p0->right->left = new TreeNode(13);
        p0->right->right = new TreeNode(4);
        p0->left->left->left = new TreeNode(7);
        p0->left->left->right = new TreeNode(2);
        p0->right->right->left = new TreeNode(5);
        p0->right->right->right = new TreeNode(1);
        p1 = 22;
        p2 = sol.pathSum(p0, p1);
        for (auto it1 : p2) {
            for (auto it2 : it1) cout << it2 << " ";
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}