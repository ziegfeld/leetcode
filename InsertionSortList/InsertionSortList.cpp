//============================================================================
// Insertion Sort List 
// Sort a linked list using insertion sort.
//
// Complexity:
// O(n^2) time
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
    ListNode *insertionSortList(ListNode *head) {
        return insertionSortList2(head);
    }

    ListNode *insertionSortList1(ListNode * head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode * newHead = pushDummy(NULL);
        newHead->next = insertionSortList1(head->next);
        insertNode(newHead, head);
        return popDummy(newHead);
    }

    ListNode *insertionSortList2(ListNode * head) {
        ListNode * newHead = pushDummy(NULL), * curNode = head;
        while (curNode != NULL) {
            ListNode * nextNode = curNode->next;
            insertNode(newHead, curNode);
            curNode = nextNode;
        }
        return popDummy(newHead);
    }

    void insertNode(ListNode * head, ListNode * newNode) {
        ListNode * curNode = head;
        while (curNode->next != NULL && curNode->next->val <= newNode->val) curNode = curNode->next;
        newNode->next = curNode->next;
        curNode->next = newNode;
    }

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
};


int main() {
    return 0;
}
