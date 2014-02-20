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

ListNode * pushHead(ListNode * head) {
    ListNode * newNode = new ListNode(-1);
    newNode->next = head;
    return newNode;
}

ListNode * popHead(ListNode * head) {
    ListNode * delNode = head;
    head = head->next;
    delete delNode;
    return head;
}

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        head = pushHead(head);
        ListNode * fastNode = head;
        for (; n > 0 && fastNode != NULL; n--) fastNode = fastNode->next;
        if (fastNode == NULL) return popHead(head);
        ListNode * slowNode = head;
        for (; fastNode->next != NULL; fastNode = fastNode->next) slowNode = slowNode->next;
        slowNode->next = popHead(slowNode->next)
        return popHead(head);
    }
};

int main() {
    return 0;
}
