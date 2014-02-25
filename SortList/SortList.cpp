//============================================================================
// Sort List 
// Sort a linked list in O(n log n) time using constant space complexity.
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
    ListNode *sortList(ListNode *head) {
        return mergetSort(head);    
    }

    ListNode *mergetSort(ListNode * head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode * frontHead, * backHead;
        split(head, frontHead, backHead);
        frontHead = mergetSort(frontHead);
        backHead = mergetSort(backHead);
        return merge(frontHead, backHead);
    }

    void split(ListNode * head, ListNode *& frontHead, ListNode *& backHead) {
        ListNode * fastNode = head, * slowNode = head;
        while (fastNode->next != NULL && fastNode->next->next != NULL) fastNode = fastNode->next->next, slowNode = slowNode->next;
        frontHead = slowNode->next;
        slowNode->next = NULL;
        backHead = head;
    }

    ListNode * merge(ListNode * frontHead, ListNode * backHead) {
        ListNode * head = pushDummy(NULL), *curNode = head;
        while (frontHead != NULL || backHead != NULL) {
            if (backHead == NULL || (frontHead != NULL && frontHead->val <= backHead->val)) curNode->next = frontHead, frontHead = frontHead->next;
            else curNode->next = backHead, backHead = backHead->next;
            curNode = curNode->next;
        }
        return popDummy(head);
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
