//============================================================================
// Remove Nth Node From End of List
// Given a linked list, remove the nth node from the end of list and return
// its head.
//
// For example,
//
// Given linked list: 1->2->3->4->5, and n = 2.
//
// After removing the second node from the end, the linked list becomes
// 1->2->3->5.
// Note:
// Given n will always be valid.
// Try to do this in one pass.
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
    ListNode(int x) : val(x), next(NULL) {};
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (head == NULL || n < 1) return head;
        ListNode * newNode = new ListNode(-1);
        newNode->next = head;
        head = newNode;
        ListNode * slow = head, *fast = head;
        while (n > 0 && fast->next != NULL) fast = fast->next, n--;
        if (n > 0) return deleteNode(head);
        while (fast->next != NULL) fast = fast->next, slow = slow->next;
        slow->next = deleteNode(slow->next);
        return deleteNode(head);
    }

    ListNode* deleteNode(ListNode * cur) {
        ListNode *toDel = cur;
        cur = cur->next;
        delete toDel;
        return cur;
    }
};

int main() {
    return 0;
}
