//============================================================================
// Swap Nodes in Pairs
// Given a linked list, swap every two adjacent nodes and return its head.
//
// For example,
// Given 1->2->3->4, you should return the list as 2->1->4->3.
//
// Your algorithm should use only constant space. You may not modify the
// values in the list, only nodes itself can be changed.
//
// Complexity:
// O(n)
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

ListNode * pushDummy(ListNode * head) {
    ListNode * newNode = new ListNode(-1);
    newNode->next = head;
    return newNode;
}

ListNode * popDummy(ListNode * head) {
    ListNode * delNode = head;
    head = head->next;
    delete delNode;
    return head;
}

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        return swapPairs2(head);
    }

    ListNode * swapPairs1(ListNode *curNode) {
        if (curNode == NULL || curNode->next == NULL) return curNode;
        ListNode * nextNode = curNode->next;
        curNode->next = swapPairs1(nextNode->next);
        nextNode->next = curNode;
        return nextNode;
    }

    ListNode *swapPairs2(ListNode *head) {
        head = pushDummy(head);
        ListNode *preNode = head, *curNode = head->next;
        while (curNode != NULL && curNode->next != NULL) {
            ListNode * nextNode = curNode->next;
            curNode->next = nextNode->next;
            nextNode->next = curNode;
            preNode->next = nextNode;
            preNode = curNode;
            curNode = curNode->next;
        }
        return popDummy(head);
    }
};

int main() {
    Solution sol;
    ListNode * head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head = sol.swapPairs(head);
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    return 0;
}
