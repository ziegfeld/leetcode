//============================================================================
// Remove Duplicates from Sorted List
// Given a sorted linked list, delete all duplicates such that each element
// appear only once.
//
// For example,
// Given 1->1->2, return 1->2.
// Given 1->1->2->3->3, return 1->2->3.
//
// Complexity:
// O(n) time
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

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode * cur = head;
        while (cur != NULL && cur->next != NULL) {
            if (cur->val == cur->next->val) cur->next = deleteNode(cur->next);
            else cur = cur->next;
        }
        return head;
    }

    ListNode* deleteNode(ListNode * cur) {
        ListNode *toDel = cur;
        cur = cur->next;
        delete toDel;
        return cur;
    }
};

int main() {
    Solution sol;

    {
        ListNode * head = new ListNode(1);
        head->next = new ListNode(1);
        head->next->next = new ListNode(2);
        head = sol.deleteDuplicates(head);
        while (head != NULL) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }

    {
        ListNode * head = new ListNode(1);
        head->next = new ListNode(1);
        head->next->next = new ListNode(2);
        head->next->next->next = new ListNode(3);
        head->next->next->next->next = new ListNode(3);
        head = sol.deleteDuplicates(head);
        while (head != NULL) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }

    return 0;
}
