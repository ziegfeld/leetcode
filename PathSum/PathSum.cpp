//============================================================================
// Path Sum
// Given a binary tree and a sum, determine if the tree has a root-to-leaf 
// path such that adding up all the values along the path equals the given 
// sum.
//
// For example:
// Given the below binary tree and sum = 22,
//              5
//             / \
//            4   8
//           /   / \
//          11  13  4
//         /  \      \
//        7    2      1
// return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 
// 22.
//
// Complexity:
// O(n) time, O(h) space, h is the height of tree
//============================================================================

#include <iostream>
#include <queue>
#include <sstream>

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
    bool hasPathSum(TreeNode *root, int sum) {
        return hasPathSum2(root, sum);
    }
    
    bool hasPathSum1(TreeNode *root, int sum) {
        if (!root) return false;
        return hasPathSum1_helper(root, sum);
    }
        
    bool hasPathSum1_helper(TreeNode *root, int sum) {
        sum = sum - root->val;
        if (! root->left && ! root-> right) return (sum == 0);
        return ( root->left && hasPathSum1_helper(root->left, sum) || root->right && hasPathSum1_helper(root->right, sum));
    }
    
    // approach 2: stack for DFS incursion
    bool hasPathSum2(TreeNode *root, int sum) {
        if (!root) return false;
        stack<TreeNode *> stree;
        stack<int> ssum;
        
        //pushPath(stree, root, ssum, sum);
        TreeNode * cur = root;
        int cur_sum = sum;
        while (cur){
            cur_sum -= cur->val;
            ssum.push(cur_sum);
            stree.push(cur);
            cur = (cur->left) ? cur->left : cur->right;
        }
        if (cur_sum == 0) return true;
        
        while (!stree.empty()){
            cur = stree.top(), stree.pop();
            cur_sum = ssum.top(), ssum.pop();
            if (!stree.empty() && cur == stree.top() -> left) {
                //pushPath(stree, root, ssum, sum);
                cur = stree.top() -> right;
                if (cur) {
                    cur_sum = ssum.top();
                    do {
                        cur_sum -= cur->val;
                        ssum.push(cur_sum);
                        stree.push(cur);
                        cur = (cur->left) ? cur->left : cur->right;
                    } while (cur);
                    // if (cur != stree.top()->right && cur_sum == 0) return true;
                    if (cur_sum == 0) return true;
                }
            }
        }
        return false;
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
    TreeNode *p0;
    int p1;
    bool p2;

    {
        p0 = fromString("{5,4,8,11,#,13,4,7,2,#,#,#,#,#,1}");
        p1 = 22;
        p2 = sol.hasPathSum(p0, p1);
        cout << p2 << endl;
    }

    {
        p0 = fromString("{-2,#,-3}");
        p1 = -5;
        p2 = sol.hasPathSum(p0, p1);
        cout << p2 << endl;
    }

    return 0;
}
