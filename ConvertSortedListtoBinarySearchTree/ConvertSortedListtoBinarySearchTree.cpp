//============================================================================
// Convert Sorted List to Binary Search Tree
//
// Given a singly linked list where elements are sorted in ascending order,
// convert it to a height balanced BST.
//
// Complexity:
// Pre-Order, O(nlog(n)) time, O(h) space
// In-Order, O(n) time, O(h) space
//============================================================================

#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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
    TreeNode *sortedListToBST(ListNode *head) {
        return sortedListToBST1(head);
    }

    TreeNode *sortedListToBST1(ListNode *head) {
        if (head == NULL) return NULL;
        ListNode* cur = head;
        int n = 1;
        while (NULL != (cur = cur->next)) n++;
        return sortedListToBSTHelper1(head, 0, n - 1);
    }

    TreeNode* sortedListToBSTHelper1(ListNode * head, int l, int u) {
        if (l > u) return NULL;
        int m = l + (u - l) / 2;
        int s = m - l;
        ListNode * cur = head;
        while (s > 0) {
            cur = cur->next;
            s--;
        }
        TreeNode * root = new TreeNode(cur->val);
        root->left = sortedListToBSTHelper1(head, l, m - 1);
        root->right = sortedListToBSTHelper1(cur->next, m + 1, u);

        return root;
    };

    TreeNode *sortedListToBST2(ListNode *head) {
        if (head == NULL) return NULL;
        ListNode* cur = head;
        int n = 1;
        while (NULL != (cur = cur->next)) n++;
        return sortedListToBSTHelper2(head, 0, n - 1);
    }

    TreeNode* sortedListToBSTHelper2(ListNode *& cur, int l, int u) {
        if (l > u) return NULL;
        int m = l + (u - l) / 2;
        TreeNode* tmp = sortedListToBSTHelper2(cur, l, m - 1);
        TreeNode* root = new TreeNode(cur->val);
        root->left = tmp;
        cur = cur->next;
        root->right = sortedListToBSTHelper2(cur, m + 1, u);
        return root;
    };
};

int main() {
    return 0;
}